#ifndef VUETOBOGGAN_H
#define VUETOBOGGAN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Toboggan.h"
#include "vueelement.h"


#define FILEPATH_SVG_ETATNORMAL ":/images/toboggan-etatNormal"

class VueToboggan : public VueElement
{
public:
    VueToboggan(Toboggan *toboggan);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;
    Toboggan *toboggan;
};

#endif // VUETOBOGGAN_H
