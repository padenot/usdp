#ifndef VUEVOL_H
#define VUEVOL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QObject>

#include "vuecanevas.h"
#include "src/noyau/Vol.h"

//#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"
class FenetrePrincipale;

class VueVol : public VueCanevas
{
public:
    VueVol(FenetrePrincipale& fenetrePrincipale, Vol& vol);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Vol* volAssocie();

private:
    QSvgRenderer *_image;
    Vol& _vol;
};

#endif // VUEVOL_H
