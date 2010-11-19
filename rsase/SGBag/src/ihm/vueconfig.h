#ifndef VUECONFIG_H
#define VUECONFIG_H

#include <QString>
#include <QRectF>

namespace vue_config
{

    namespace bagage
    {
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/bagage-etatNormal";
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }
    namespace chariot
    {
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/bagage-etatNormal";
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }

    namespace tapis
    {
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/bagage-etatNormal";
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }

    namespace toboggan
    {
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/bagage-etatNormal";
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }

    namespace troncon
    {
        const int longueur = 10;
        const int largeur = 10;
        const QString etatNormal = ":/images/bagage-etatNormal";
        const QRectF rect = QRectF(longueur/2, largeur/2, longueur, largeur);
    }
}

#endif // VUECONFIG_H
