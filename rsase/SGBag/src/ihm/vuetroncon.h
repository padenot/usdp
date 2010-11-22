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

/**
 * @todo TODO : gestion de la mise en panne du tronçon (clic droit -> simuler l'indisponibilité)
 */
class VueTroncon : public VueElement
{
public:
    VueTroncon(FenetrePrincipale& _fenetrePrincipale, Troncon& troncon);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int _etat;
    Troncon &_troncon;

    QVector2D _vecteurDirection;
    QLineF _lignePerpendiculaire;

    QPointF point1;
    QPointF point2;
    QPointF point3;
    QPointF point4;
    QPointF _fond[4];
};

#endif // VUETRONCON_H
