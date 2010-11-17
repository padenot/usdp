#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T10:07:22
#
#-------------------------------------------------

QT       += core gui

TARGET = SGBag
TEMPLATE = app
DEPENDPATH += src ui




SOURCES += ihm/main.cpp\
    ihm/fenetreprincipale.cpp \
    noyau/Chariot.cpp \
    noyau/Bagage.cpp \
    noyau/ElementActif.cpp \
    noyau/Element.cpp \
    noyau/Vol.cpp \
    noyau/Troncon.cpp \
    noyau/Toboggan.cpp \
    noyau/Tapis.cpp \
    noyau/Prototype.cpp \
    noyau/Noeud.cpp \
    noyau/XmlConfigFactory.cpp

HEADERS  += ihm/fenetreprincipale.h \
    noyau/Chariot.h \
    noyau/Bagage.h \
    noyau/ElementActif.h \
    noyau/Element.h \
    noyau/Vol.h \
    noyau/Troncon.h \
    noyau/Toboggan.h \
    noyau/Tapis.h \
    noyau/Prototype.h \
    noyau/Noeud.h \
    noyau/XmlConfigFactory.h \
    noyau/Elements.h

FORMS    += fenetreprincipale.ui

QT+=xml
