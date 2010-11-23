#ifndef VUETAPIS_H
#define VUETAPIS_H

#include <QObject>
#include <QFile>

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include "src/noyau/Tapis.h"
#include "vueelement.h"


#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"

class VueTapisHandler;

class VueTapis : public VueElement
{
    public:
        VueTapis(FenetrePrincipale& _fenetrePrincipale, Tapis &tapis);
        virtual ~VueTapis();

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        Tapis* tapisAssocie();

    protected:
        void advance(int step);

    private:
        int _etat;
        static QSvgRenderer *_renderer;
        QGraphicsSvgItem *_image;
        Tapis &_tapis;

        /**
         * Instance de VueTapisHandler intégrée à la vue.
         */
        VueTapisHandler& _handler;
};

/**
 * Gestionnnaire d'événements pour VueTapis
 */
class VueTapisHandler : public QObject
{
    Q_OBJECT

    public:
        VueTapisHandler(VueTapis& vueTapis, FenetrePrincipale& fenetrePrincipale);
    public slots:
        void ajouterBagage();
    protected:
        VueTapis& _vueTapis;
        FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUETAPIS_H
