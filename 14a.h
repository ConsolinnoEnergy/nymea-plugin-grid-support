#ifndef FOURTEENA_H
#define FOURTEENA_H

#include <plugintimer.h>
#include <pluginstate.h>

class FourteenA : public PluginTimer
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.nymea.plugin" FILE "14a.json")
    Q_INTERFACES(PluginTimer)

public:
    explicit FourteenA(QObject *parent = nullptr);

protected:
    void init() override;
    void timerTimeout() override;

private:
    void handleVariables();
    PluginState *m_limitingActive;
    PluginState *m_pLim;
};

#endif // FOURTEENA_H
