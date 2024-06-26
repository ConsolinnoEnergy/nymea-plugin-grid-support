#include "integrationplugin14a.h"
#include <QDebug>

IntegrationPlugin14a::IntegrationPlugin14a() :
    m_limitingActive(false),
    m_pLim(0.0)
{
}

IntegrationPlugin14a::~IntegrationPlugin14a()
{
    if (m_pluginTimer) {
        delete m_pluginTimer;
    }
}

void IntegrationPlugin14a::init()
{
    qDebug() << "Initializing Integration Plugin 14a";

    m_pluginTimer = new PluginTimer(this);
    connect(m_pluginTimer, &PluginTimer::timeout, this, &IntegrationPlugin14a::onPluginTimer);
    m_pluginTimer->start(1000);
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

void IntegrationPlugin14a::thingRemoved(Thing *thing)
{
    // Cleanup logic when a thing is removed
}

void IntegrationPlugin14a::executeAction(ThingActionInfo *info)
{
    // Action execution logic
}

void IntegrationPlugin14a::onPluginTimer()
{
    handleVariables();
}

void IntegrationPlugin14a::handleVariables()
{
    qDebug() << "Handling variables...";

    // Example logic for updating states
    m_limitingActive = !m_limitingActive;
    m_pLim += 0.1;

    qDebug() << "Limitierung aktiv:" << m_limitingActive;
    qDebug() << "PLim:" << m_pLim;

    // Publish the updated states
    // Example:
    // myThing->setStateValue("limitingActive", m_limitingActive);
    // myThing->setStateValue("pLim", m_pLim);
}
