#ifndef VUETAPIS_H
#define VUETAPIS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Tapis.h"
#include "vueelement.h"


#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"

class VueTapis : public VueElement
{
public:
    VueTapis();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;
    Bagage *bagage;
};

#endif // VUETAPIS_H
