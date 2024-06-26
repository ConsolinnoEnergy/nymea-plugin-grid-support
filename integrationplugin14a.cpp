#include "integrationplugin14a.h"
#include <QDebug>

IntegrationPlugin14a::IntegrationPlugin14a() :
    m_limitingActive(false),
    m_pLim(0.0)
{
}

IntegrationPlugin14a::~IntegrationPlugin14a()
{
}

void IntegrationPlugin14a::init()
{
    qDebug() << "Initializing Integration Plugin 14a";
    connect(&m_timer, &QTimer::timeout, this, &IntegrationPlugin14a::onTimeout);
    m_timer.start(1000); // 1 second interval
}

void IntegrationPlugin14a::discoverThings(ThingDiscoveryInfo *info)
{
    Q_UNUSED(info)
    // Discovery logic
}

void IntegrationPlugin14a::setupThing(ThingSetupInfo *info)
{
    Q_UNUSED(info)
    // Setup logic
}

void IntegrationPlugin14a::postSetupThing(Thing *thing)
{
    Q_UNUSED(thing)
    // Post setup logic
}

void IntegrationPlugin14a::thingRemoved(Thing *thing)
{
    Q_UNUSED(thing)
    // Cleanup logic when a thing is removed
}

void IntegrationPlugin14a::executeAction(ThingActionInfo *info)
{
    Q_UNUSED(info)
    // Action execution logic
}

void IntegrationPlugin14a::onTimeout()
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
