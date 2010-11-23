#ifndef VUECHARIOT_H
#define VUECHARIOT_H

#include <QFile>

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

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
    static QSvgRenderer *_renderer;
    QGraphicsSvgItem *_image;
    Chariot &_chariot;

    QPixmap _pixmap;
    QPainter _paintPixmap;
};

#endif // VUECHARIOT_H
