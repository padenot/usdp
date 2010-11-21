#ifndef VUECONFIG_H
#define VUECONFIG_H

#include <QString>
#include <QRectF>

namespace vue_config
{
        const int dt = 10; // rafraichissement en ms

    namespace scene
    {
        const int longueur = 70;
        const int largeur = 70;
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
        const QString resBagage[nbrRes] = { sacsport, saccuir, valise, homard };
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
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
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }

    namespace toboggan
    {
        const int zIndex = 7;
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/toboggan";
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }

    namespace troncon
    {
        const int zIndex = 6;
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/bagage-etatNormal";
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }
}

#endif // VUECONFIG_H
