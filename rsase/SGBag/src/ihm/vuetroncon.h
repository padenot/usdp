#ifndef VUETRONCON_H
#define VUETRONCON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

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
};

#endif // VUETRONCON_H
