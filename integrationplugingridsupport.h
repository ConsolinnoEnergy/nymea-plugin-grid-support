#ifndef INTEGRATIONPLUGINGRIDSUPPORT_H
#define INTEGRATIONPLUGINGRIDSUPPORT_H

#include "integrations/integrationplugin.h"
#include "plugintimer.h"
#include <QTimer>

class IntegrationPluginGridSupport : public IntegrationPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.nymea.IntegrationPlugin" FILE "integrationplugingridsupport.json")
    Q_INTERFACES(IntegrationPlugin)

public:
    explicit IntegrationPluginGridSupport();
    ~IntegrationPluginGridSupport() override;

    void setupThing(ThingSetupInfo *info) override;
    void thingRemoved(Thing *thing) override;


private slots:
    void onPluginTimer();

private: 
    PluginTimer *m_pluginTimer = nullptr;
};

#endif // INTEGRATIONPLUGINGRIDSUPPORT_H
