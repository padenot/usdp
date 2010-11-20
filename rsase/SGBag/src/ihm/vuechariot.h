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
    VueChariot();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;
    Bagage *bagage;
};

#endif // VUECHARIOT_H
