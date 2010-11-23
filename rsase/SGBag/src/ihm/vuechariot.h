#ifndef VUECHARIOT_H
#define VUECHARIOT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "vueelement.h"
#include "src/noyau/Chariot.h"

class VueChariot : public VueElement
{
public:
    VueChariot(FenetrePrincipale& _fenetrePrincipale, Chariot &chariot);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Chariot& chariot();

protected:
    void advance(int step);

private:
    int _etat;
    QSvgRenderer *_image;
    Chariot &_chariot;

    QPixmap _pixmap;
    QPainter _paintPixmap;
};

#endif // VUECHARIOT_H
