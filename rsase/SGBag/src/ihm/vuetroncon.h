#ifndef VUETRONCON_H
#define VUETRONCON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QVector2D>

#include "src/noyau/Troncon.h"
#include "vueelement.h"

class VueTronconHandler;

/**
 * @todo TODO : gestion de la mise en panne du tronçon (clic droit -> simuler l'indisponibilité)
 */
class VueTroncon : public VueElement
{
public:
    VueTroncon(FenetrePrincipale& _fenetrePrincipale, Troncon& troncon);
    ~VueTroncon();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mettreHorsService();
    void reparer();


protected:
    void advance(int step);

private:
    int _etat;
    Troncon &_troncon;

    /**
     * Instance de VueTronconHandler intégrée à la vue.
     */
    VueTronconHandler& _handler;

    QVector2D _vecteurDirection;
    QLineF _lignePerpendiculaire;

    QPointF point1;
    QPointF point2;
    QPointF point3;
    QPointF point4;
    QPointF _fond[4];
};

/**
 * Gestionnnaire d'événements pour VueTroncon
 */
class VueTronconHandler : public QObject
{
    Q_OBJECT

    public:
        VueTronconHandler(VueTroncon& vueTroncon, FenetrePrincipale& fenetrePrincipale);

    public slots:
        void mettreHorsService();
        void reparer();

    protected:
        VueTroncon& _vueTroncon;
        FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUETRONCON_H
