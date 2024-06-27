include(plugins.pri)

QT += core gui network

SOURCES += \
    integrationplugingridsupport.cpp

HEADERS += \
    integrationplugingridsupport.h

TRANSLATIONS += translations/integrationplugingridsupport_en.ts \
                translations/integrationplugingridsupport_de.ts

CONFIG += c++11
