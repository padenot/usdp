#ifndef VUEBAGAGE_H
#define VUEBAGAGE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include "vueelement.h"

#include "src/noyau/Bagage.h"

class VueBagage : public VueElement
{
public:
    VueBagage(FenetrePrincipale* fenetrePrincipale, Bagage *bagage);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *_image;
    Bagage *_bagage;
};

#endif // VUEBAGAGE_H
