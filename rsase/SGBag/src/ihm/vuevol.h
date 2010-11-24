#ifndef VUEVOL_H
#define VUEVOL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QObject>

#include "vuecanevas.h"
#include "src/noyau/Vol.h"

//#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"
class FenetrePrincipale;

class VueVol : public VueCanevas
{
public:
    /**
     * Constructeur de la classe.
     * @param [in] fenetrePrincipale - la fenêtre principale de l'application
     * @param [in] vol - le vol associé à la vue réspective
     */
    VueVol(FenetrePrincipale& fenetrePrincipale, Vol& vol);

    /**
     * Méthode qui permet de dessiner la vue
     * @param [in] painter - l'objet Qt pour dessiner
     * @param [in] option - des options en fonction  de l'environnement graphique.
     * @param [in] widget - le widget sur lequel dessiner.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Accesseur au vol associé à la vue
     */
    Vol* volAssocie();

private:
    /**
     * L'image associé à la vue de l'objet vol
     */
    //QSvgRenderer *_image;

    /**
     * attribut qui permet de rendre le fichier svg associé à la vue
     */
    static QSvgRenderer *_renderer;

    /**
     * L'objet Vol associé à la vue Vol
     */
    Vol& _vol;
};

#endif // VUEVOL_H
