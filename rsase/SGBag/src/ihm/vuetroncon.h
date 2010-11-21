#ifndef VUETRONCON_H
#define VUETRONCON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Troncon.h"
#include "vueelement.h"


#define FILEPATH_SVG_ETATNORMAL ":/images/bagage-etatNormal"

class VueTroncon : public VueElement
{
public:
    VueTroncon(FenetrePrincipale* _fenetrePrincipale, Troncon* troncon);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int _etat;
    QSvgRenderer *_image;
    Troncon *_troncon;
};

#endif // VUETRONCON_H
