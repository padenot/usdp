#ifndef VUECONFIG_H
#define VUECONFIG_H

#include <QString>
#include <QRectF>
#include <QPen>

namespace vue_config
{
        const int dt = 10; // rafraichissement en ms

    namespace scene
    {
        const int longueur = 380;
        const int largeur = 380;
        const QRectF rect = QRectF(0, 0, longueur, largeur);
    }

    namespace bagage
    {
        const int zIndex = 10;
        const int longueur = 10;
        const int largeur = 10;
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
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/chariot";
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }

    namespace tapis
    {
        const int zIndex = 8;
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/tapis-roulant";
    }

    namespace toboggan
    {
        const int zIndex = 10;
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/toboggan";
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }

    namespace troncon
    {
        const int zIndex = 5;
        const float largeur = 0.3; //Demi largeur d'un rail à l'affichage

        const QBrush brushGray(Qt::gray); //couleur de fon du rail
        const QPen penLight(Qt::gray, 0); //affichage du fond du rail
        const QPen penDark(Qt::darkGray, 0.3); //affichage des bords du rail


        //const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }

    namespace vol
    {
        const int zIndex = 10;
        const int longueur = 20;
        const int largeur = 20;
        const int ecartToboggan = 20;
        const QString etatNormal = ":/images/avion";
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }
}

#endif // VUECONFIG_H
