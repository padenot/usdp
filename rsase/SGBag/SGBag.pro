#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T10:07:22
#
#-------------------------------------------------

QT       += core gui svg

TARGET = SGBag
TEMPLATE = app
QT+=xml
DEPENDPATH += src ui

QMAKE_CXXFLAGS += -Wall -Wextra

 CONFIG(debug) {
     QMAKE_CXXFLAGS += -DDEBUG_ACHEMINEMENT
 }

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
    src/ihm/vuechariot.cpp \
    src/ihm/vueelement.cpp \
    src/ihm/vuevol.cpp \
    src/ihm/vuecanevas.cpp \
    src/noyau/StrategiePilotage.cpp \
    src/noyau/StrategiePilotageAuto.cpp \
    src/noyau/StrategiePilotageManuel.cpp \
    src/noyau/modelvols.cpp \
    src/ihm/vueparametreschariot.cpp
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
    src/ihm/vueconfig.h \
    src/ihm/vuevol.h \
    src/ihm/vueelement.h \
    src/ihm/vuecanevas.h \
    src/noyau/StrategiePilotage.h \
    src/noyau/StrategiePilotageAuto.h \
    src/noyau/StrategiePilotageManuel.h \
    src/noyau/modelvols.h \
    src/ihm/vueparametreschariot.h \
    src/noyau/Direction.h
FORMS    += fenetreprincipale.ui \
    ajouterVol.ui \
    ui/vueparametreschariot.ui \
    ui/about.ui


RESOURCES += \
    images.qrc

OTHER_FILES += \
    ui/images/bagage.svg \
    ui/images/valise.svg \
    ui/images/toboggan.svg \
    ui/images/tapis-roulant.svg \
    ui/images/sacsport.svg \
    ui/images/saccuir.svg \
    ui/images/homard.svg \
    ui/images/chariot.svg \
    ui/images/avion.svg \
    ui/images/toboggan2.svg \
    ui/images/tapis.svg \
    ui/images/caisse.svg
