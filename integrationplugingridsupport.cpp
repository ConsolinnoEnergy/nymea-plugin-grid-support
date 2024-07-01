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

void IntegrationPluginGridSupport::onPluginTimer()
{
    // Periodic timer logic
}
