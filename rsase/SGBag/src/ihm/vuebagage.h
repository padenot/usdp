#ifndef VUEBAGAGE_H
#define VUEBAGAGE_H

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include <QFile>

#include "vueelement.h"

#include "src/noyau/Bagage.h"

class VueBagage : public VueElement
{
public:
    VueBagage(FenetrePrincipale& _fenetrePrincipale, Bagage &bagage);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Bagage* bagageAssocie();

protected:
    void advance(int step);

private:
    int _etat;
    static QSvgRenderer *_renderer;
    QGraphicsSvgItem *_image;
    Bagage &_bagage;
};

#endif // VUEBAGAGE_H
