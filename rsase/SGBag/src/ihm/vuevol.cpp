#include "src/ihm/vuevol.h"
#include "src/ihm/vueconfig.h"
#include "fenetreprincipale.h"

#include <QtSvg/QSvgRenderer>

//using namespace vue_config::vol;

VueVol::VueVol(FenetrePrincipale* fenetrePrincipale):
        Vue()
{
    handler = new VueVolHandler(this, fenetrePrincipale);
    //TODO
}

void VueVol::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //image->render(painter, rect);
    //TODO
}

void VueVol::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    handler->estSelectionne();
}

QRectF VueVol::boundingRect() const
{
    return QRectF();
    //TODO
}

Vol* VueVol::volAssocie()
{
    return vol;
}

VueVolHandler::VueVolHandler(VueVol* _vueVol, FenetrePrincipale* fenetrePrincipale):
        vueVol(_vueVol)
{
    connect(this, SIGNAL(estSelection(VueVol*)), fenetrePrincipale, SIGNAL(volSelectionne(VueVol*)));
}

void VueVolHandler::estSelectionne()
{
    emit estSelection(vueVol);
}
