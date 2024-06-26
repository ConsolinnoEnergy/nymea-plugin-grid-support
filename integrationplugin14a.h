#ifndef INTEGRATIONPLUGIN14A_H
#define INTEGRATIONPLUGIN14A_H

#include <QObject>
#include <integrations/integrationplugin.h>
#include <plugintimer.h>
#include <pluginstate.h>

class IntegrationPlugin14a : public IntegrationPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "io.nymea.IntegrationPlugin" FILE "integrationplugin14a.json")
    Q_INTERFACES(IntegrationPlugin)

public:
    explicit IntegrationPlugin14a();

    void init() override;
    void discoverThings(ThingDiscoveryInfo *info) override;
    void setupThing(ThingSetupInfo *info) override;
    void postSetupThing(Thing *thing) override;
    void executeAction(ThingActionInfo *info) override;
    void thingRemoved(Thing *thing) override;

private:
    PluginState *m_limitingActive;
    PluginState *m_pLim;

    void handleVariables();
};

#endif // INTEGRATIONPLUGIN14A_H