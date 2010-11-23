#ifndef VUECONFIG_H
#define VUECONFIG_H

#include <QString>
#include <QRectF>
#include <QPen>
#include <QFont>

namespace vue_config
{
    const double ZOOM_ELEMENTS = 10.0;
    const int fps = 30;
    const int dt = 1000/fps; // rafraichissement en ms

    namespace canevas
    {
        const double marge = 2;
    }

    namespace element
    {
        const QBrush brushSelection(Qt::lightGray);
        const QPen penSelection(Qt::darkGray);
        const double opacite = 0.7;
        const double arrondis = 1;
    }

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

        const QFont font = QFont("SansSerif", 26, QFont::Normal);
        const QColor couleurTexte = QColor(35,35,35);
        const qreal rotationTexte = -15;
        const qreal dxTexte = 40;
        const qreal dyTexte = 90;

    }

    namespace tapis
    {
        const int zIndex = 8;
        const double largeur = 1*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/tapis-roulant";
    }

    namespace toboggan
    {
        const int zIndex = 5;
        const double largeur = 1*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/toboggan";
    }

    namespace troncon
    {
        const int zIndex = 5;

        const double largeur = 0.5; //Demi largeur d'un rail à l'affichage
        const double rayonNoeud = largeur*1.3;

        const QBrush brushGray(Qt::gray); //couleur de fond du rail
        const QPen penLight(Qt::gray, 0); //affichage du fond du rail
        const QPen penDark(Qt::darkGray, 0.3); //affichage des bords du rail

        const QBrush brushRed(Qt::red); //couleur de fond du rail
        const QPen penRedLight(Qt::red, 0); //affichage du fond du rail
        const QPen penRedDark(Qt::darkRed, 0.3); //affichage des bords du rail
    }

    namespace vol
    {
        const int zIndex = 10;
        const double longueur = 70;
        const double largeur = longueur*0.5;
        const double ecartToboggan = 3*ZOOM_ELEMENTS;
        const QString etatNormal = ":/images/avion";
    }
}

#endif // VUECONFIG_H
