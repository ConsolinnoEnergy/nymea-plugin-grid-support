#ifndef INTEGRATIONPLUGIN14A_H
#define INTEGRATIONPLUGIN14A_H

#include "integrations/integrationplugin.h"
#include <QTimer>

class IntegrationPlugin14a : public IntegrationPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.nymea.IntegrationPlugin" FILE "integrationplugin14a.json")
    Q_INTERFACES(IntegrationPlugin)

public:
    explicit IntegrationPlugin14a();
    ~IntegrationPlugin14a() override;

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

#endif // INTEGRATIONPLUGIN14A_H
