#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T10:07:22
#
#-------------------------------------------------

QT       += core gui svg

TARGET = SGBag
TEMPLATE = app
DEPENDPATH += src ui




SOURCES += ihm/main.cpp\
    ihm/fenetreprincipale.cpp \
    ihm/vuebagage.cpp \
    noyau/Chariot.cpp \
    noyau/Bagage.cpp \
    noyau/ElementActif.cpp \
    noyau/Element.cpp \
    noyau/Vol.cpp \
    noyau/Prototype.cpp \
    noyau/Noeud.cpp \
    noyau/XmlConfigFactory.cpp \
    noyau/Troncon.cpp \
    noyau/Toboggan.cpp \
    noyau/Tapis.cpp \
    src/ihm/vuetroncon.cpp \
    src/ihm/vuetoboggan.cpp \
    src/ihm/vuetapis.cpp \
    src/ihm/vuechariot.cpp

HEADERS  += ihm/fenetreprincipale.h \
    ihm/vuebagage.h \
    noyau/Chariot.h \
    noyau/Bagage.h \
    noyau/ElementActif.h \
    noyau/Element.h \
    noyau/Vol.h \
    noyau/Prototype.h \
    noyau/Noeud.h \
    noyau/XmlConfigFactory.h \
    noyau/Elements.h \
    noyau/Troncon.h \
    noyau/Toboggan.h \
    noyau/Tapis.h \
    src/ihm/vuetroncon.h \
    src/ihm/vuetoboggan.h \
    src/ihm/vuetapis.h \
    src/ihm/vuechariot.h \
    src/ihm/vueconfig.h

FORMS    += fenetreprincipale.ui

QT+=xml

RESOURCES += \
    images.qrc

OTHER_FILES += \
    ui/images/bagage.svg
