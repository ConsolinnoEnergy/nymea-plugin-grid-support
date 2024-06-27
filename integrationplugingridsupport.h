#ifndef INTEGRATIONPLUGINGRIDSUPPORT_H
#define INTEGRATIONPLUGINGRIDSUPPORT_H

#include "integrations/integrationplugin.h"
#include <QTimer>

class IntegrationPluginGridSupport : public IntegrationPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.nymea.IntegrationPlugin" FILE "integrationplugingridsupport.json")
    Q_INTERFACES(IntegrationPlugin)

public:
    explicit IntegrationPluginGridSupport();
    ~IntegrationPluginGridSupport() override;

    void init() override;
    void discoverThings(ThingDiscoveryInfo *info) override;
    void setupThing(ThingSetupInfo *info) override;
    void postSetupThing(Thing *thing) override;
    void thingRemoved(Thing *thing) override;
    void executeAction(ThingActionInfo *info) override;

private slots:
    void onTimeout();

private:
    QTimer m_timer;
    bool m_limitingActive;
    float m_pLim;
};

#endif // INTEGRATIONPLUGINGRIDSUPPORT_H
