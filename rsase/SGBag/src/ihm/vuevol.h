#ifndef VUEVOL_H
#define VUEVOL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QObject>

#include "vue.h"
#include "src/noyau/Vol.h"

//#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"
class VueVolHandler;
class FenetrePrincipale;

class VueVol : public Vue
{
public:
    VueVol(FenetrePrincipale* fenetrePrincipale);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    Vol* volAssocie();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Vol* vol;
    VueVolHandler* handler;
};

class VueVolHandler: public QObject
{
    Q_OBJECT

public:
    VueVolHandler(VueVol*, FenetrePrincipale*);
    void estSelectionne();

signals:
    void estSelection(VueVol*);

private:
    VueVol* vueVol;
};

#endif // VUEVOL_H
