include(plugins.pri)

QT += core gui network

SOURCES += \
    integrationpluginGridSupport.cpp

HEADERS += \
    integrationpluginGridSupport.h

TRANSLATIONS += translations/integrationpluginGridSupport_en.ts \
                translations/integrationpluginGridSupport_de.ts

CONFIG += c++11
