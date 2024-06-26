#include "integrationplugin14a.h"
#include <QDebug>

IntegrationPlugin14a::IntegrationPlugin14a()
{
}

void IntegrationPlugin14a::init()
{
    qDebug() << "Initializing Integration Plugin 14a";
    m_limitingActive = new PluginState("limitingActive", this);
    m_pLim = new PluginState("pLim", this);

    // Initialize states with default values
    m_limitingActive->setValue(false);
    m_pLim->setValue(0.0);
}

void IntegrationPlugin14a::discoverThings(ThingDiscoveryInfo *info)
{
    // Discovery logic
}

void IntegrationPlugin14a::setupThing(ThingSetupInfo *info)
{
    // Setup logic
}

void IntegrationPlugin14a::postSetupThing(Thing *thing)
{
    // Post setup logic
}

void IntegrationPlugin14a::executeAction(ThingActionInfo *info)
{
    // Action execution logic
}

void IntegrationPlugin14a::thingRemoved(Thing *thing)
{
    // Cleanup logic when a thing is removed
}

void IntegrationPlugin14a::handleVariables()
{
    qDebug() << "Handling variables...";

    // Example logic for updating states
    bool limitingActive = m_limitingActive->value().toBool();
    float pLim = m_pLim->value().toFloat();

    qDebug() << "Limitierung aktiv:" << limitingActive;
    qDebug() << "PLim:" << pLim;

    // Update states as needed
    m_limitingActive->setValue(!limitingActive);
    m_pLim->setValue(pLim + 0.1);
}
