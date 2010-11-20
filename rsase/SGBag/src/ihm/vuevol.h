#ifndef VUEVOL_H
#define VUEVOL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>

#include "vue.h"
#include "src/noyau/Vol.h"

//#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"

class VueVol : public Vue
{
public:
    VueVol();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:


private:
    Vol* vol;
};

#endif // VUEVOL_H
