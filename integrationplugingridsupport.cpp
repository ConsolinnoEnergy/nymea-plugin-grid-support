#include "integrationplugingridsupport.h"
#include "integrations/thing.h"
#include "plugininfo.h"
#include <QDebug>

IntegrationPluginGridSupport::IntegrationPluginGridSupport() { }

IntegrationPluginGridSupport::~IntegrationPluginGridSupport() { }

void IntegrationPluginGridSupport::setupThing(ThingSetupInfo* info)
{
    qCDebug(dcGridsupport) << "Setup thing" << info->thing()->name() << info->thing()->params();
    if (!m_pluginTimer) {
        m_pluginTimer = hardwareManager()->pluginTimerManager()->registerTimer(60 * 60);
        connect(m_pluginTimer, &PluginTimer::timeout, this,
            &IntegrationPluginGridSupport::onPluginTimer);
    }
    info->finish(Thing::ThingErrorNoError);
}

void IntegrationPluginGridSupport::thingRemoved(Thing* thing)
{
    Q_UNUSED(thing)
    if (m_pluginTimer && myThings().isEmpty()) {
        hardwareManager()->pluginTimerManager()->unregisterTimer(m_pluginTimer);
        m_pluginTimer = nullptr;
    }
}

void IntegrationPluginGridSupport::executeAction(ThingActionInfo* info)
{
    if (info->action().actionTypeId() == gridsupportPlimActionTypeId) {
        float plim = info->action().paramValue(gridsupportPlimActionPlimParamTypeId).toFloat();
        info->thing()->setStateValue(gridsupportPlimStateTypeId, plim);
        info->finish(Thing::ThingErrorNoError);
    } else if (info->action().actionTypeId() == gridsupportPlimStatusActionTypeId) {
        QString value = info->action().paramValue(gridsupportPlimStatusActionPlimStatusParamTypeId).toString();
        info->thing()->setStateValue(gridsupportPlimStatusStateTypeId, value);
        info->finish(Thing::ThingErrorNoError);
    }
}

void IntegrationPluginGridSupport::onPluginTimer()
{
    // Periodic timer logic
}
