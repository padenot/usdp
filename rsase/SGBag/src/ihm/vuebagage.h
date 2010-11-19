#ifndef VUEBAGAGE_H
#define VUEBAGAGE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Bagage.h"

class VueBagage : public QGraphicsItem
{
public:
    VueBagage();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;

    Bagage *bagage;
};

#endif // VUEBAGAGE_H
