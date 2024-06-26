#include "14a.h"
#include <QDebug>

FourteenA::FourteenA(QObject *parent)
    : PluginTimer(parent)
{
    m_limitingActive = new PluginState("limitingActive", this);
    m_pLim = new PluginState("pLim", this);
}

void FourteenA::init()
{
    qDebug() << "Initializing 14a plugin";
    setInterval(1000); // Set timer interval to 1 second

    // Initialize states with default values
    m_limitingActive->setValue(false);
    m_pLim->setValue(0.0);
}

void FourteenA::timerTimeout()
{
    handleVariables();
}

void FourteenA::handleVariables()
{
    // Handle your variables here
    qDebug() << "Handling variables...";

    // Example logic for updating states
    bool limitingActive = m_limitingActive->value().toBool();
    float pLim = m_pLim->value().toFloat();

    qDebug() << "Limitierung aktiv:" << limitingActive;
    qDebug() << "PLim:" << pLim;

    // Update states as needed
    // For example, toggle limitingActive and increment pLim
    m_limitingActive->setValue(!limitingActive);
    m_pLim->setValue(pLim + 0.1);
}
