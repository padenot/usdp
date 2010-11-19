#ifndef VUETRONCON_H
#define VUETRONCON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Bagage.h"

#define FILEPATH_SVG_ETATNORMAL ":/images/bagage-etatNormal"

class VueTroncon : public QGraphicsItem
{
public:
    VueTroncon();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;
    Bagage *bagage;
};

#endif // VUETRONCON_H
