#ifndef VUETOBOGGAN_H
#define VUETOBOGGAN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Toboggan.h"

#define FILEPATH_SVG_ETATNORMAL ":/images/toboggan-etatNormal"

class VueToboggan : public QGraphicsItem
{
public:
    VueToboggan();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;
    Bagage *bagage;
};

#endif // VUETOBOGGAN_H
