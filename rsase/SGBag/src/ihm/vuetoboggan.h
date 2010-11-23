#ifndef VUETOBOGGAN_H
#define VUETOBOGGAN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Toboggan.h"
#include "vueelement.h"

class VueToboggan : public VueElement
{
public:
    VueToboggan(FenetrePrincipale& _fenetrePrincipale, Toboggan &toboggan);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void associerVol(Vol* vol);
protected:
    void advance(int step);

private:
    int _etat;
    QSvgRenderer *_image;
    Toboggan &_toboggan;

    QPixmap _pixmap;
    QPainter _paintPixmap;
};

#endif // VUETOBOGGAN_H
