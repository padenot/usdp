#include "src/ihm/vuevol.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

//using namespace vue_config::vol;

VueVol::VueVol()

{

}

void VueVol::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //image->render(painter, rect);
}


QRectF VueVol::boundingRect() const
{
    return QRectF();
    //TODO
}
