#ifndef VUECONFIG_H
#define VUECONFIG_H

#include <QString>
#include <QRectF>
#include <QPen>

namespace vue_config
{
    const double ZOOM_ELEMENTS = 10.0;
    const int dt = 1000/30; // rafraichissement en ms

    namespace bagage
    {
        const int zIndex = 10;
        const double longueur = 0.3*ZOOM_ELEMENTS;
        const double largeur = 0.5*ZOOM_ELEMENTS;
        const int nbrRes = 4;
        const QString sacsport = ":/images/sacsport";
        const QString saccuir = ":/images/saccuir";
        const QString valise = ":/images/valise";
        const QString homard = ":/images/homard";
        const QString bagageSimple = ":/images/bagageSimple";
        const QString resBagage[nbrRes] = { sacsport, saccuir, valise, homard };
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }
    namespace chariot
    {
        const int zIndex = 9;
        const double longueur = 1*ZOOM_ELEMENTS;
        const double largeur = 1*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/chariot";
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }

    namespace tapis
    {
        const int zIndex = 8;
        const double largeur = 1*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/tapis-roulant";
    }

    namespace toboggan
    {
        const int zIndex = 10;
        const double largeur = 1*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/toboggan";
    }

    namespace troncon
    {
        const int zIndex = 5;
        const double largeur = 1; //Demi largeur d'un rail à l'affichage
        const double largeurEspaceBrise = 2;

        const QBrush brushGray(Qt::gray); //couleur de fond du rail
        const QPen penLight(Qt::gray, 0); //affichage du fond du rail
        const QPen penDark(Qt::darkGray, 0.3); //affichage des bords du rail
    }

    namespace vol
    {
        const int zIndex = 10;
        const double longueur = 3*ZOOM_ELEMENTS;
        const double largeur = 3*ZOOM_ELEMENTS;
        const double ecartToboggan = 3*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/avion";
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }
}

#endif // VUECONFIG_H
