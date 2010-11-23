#ifndef VUETOBOGGAN_H
#define VUETOBOGGAN_H

#include <QFile>


#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include "src/noyau/Toboggan.h"
#include "vueelement.h"

class VueToboggan : public VueElement
{
public:
    VueToboggan(FenetrePrincipale& _fenetrePrincipale, Toboggan &toboggan);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void associerVol(Vol* vol);
    Toboggan& toboggan() const;
protected:
    void advance(int step);

private:
    int _etat;
    static QSvgRenderer *_renderer;
    QGraphicsSvgItem *_image;
    Toboggan &_toboggan;
};

#endif // VUETOBOGGAN_H
