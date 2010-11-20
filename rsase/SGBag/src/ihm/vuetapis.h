#ifndef VUETAPIS_H
#define VUETAPIS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QObject>

#include "src/noyau/Tapis.h"
#include "vueelement.h"


#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"

class VueTapisHandler;

class VueTapis : public VueElement
{
public:
    VueTapis(FenetrePrincipale* _fenetrePrincipale, Tapis *tapis);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    Tapis* tapisAssocie();
    void ajouterBagage();

protected:
    void advance(int step);

private:
    int etat;
    QSvgRenderer *image;
    Tapis *tapis;

    /**
     * Instance de VueTapisHandler intégrée à la vue.
     */
    VueTapisHandler* handler;
};

/**
 * Gestionnnaire d'événements pour VueTapis
 */
class VueTapisHandler : public QObject
{
    Q_OBJECT

public:
    VueTapisHandler(VueTapis*);
public slots:
    void ajouterBagage();
protected:
    VueTapis* vueTapis;
};

#endif // VUETAPIS_H
