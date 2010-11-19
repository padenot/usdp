#ifndef VUEBAGAGE_H
#define VUEBAGAGE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "src/noyau/Bagage.h"

#define FILEPATH_SVG_ETATNORMAL ":/images/bagages-etatNormal"

class VueBagage : public QGraphicsItem
{
public:
    VueBagage();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //TODO a revoir
    QPainterPath shape() const;
    QRectF boundingRect() const;

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;

    Bagage *bagage;

    static const int longueur = 10;
    static const int largeur = 10;
    static const QRectF rect;

    static const QString etatNormal;
};

#endif // VUEBAGAGE_H
