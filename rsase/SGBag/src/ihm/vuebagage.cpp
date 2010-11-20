#include "src/ihm/vuebagage.h"
#include "src/ihm/vueconfig.h"
#include <QtSvg/QSvgRenderer>

using namespace vue_config::bagage;

VueBagage::VueBagage(FenetrePrincipale* _fenetrePrincipale, Bagage *bagage):
        VueElement(_fenetrePrincipale),
        image(new QSvgRenderer(resBagage[rand() % nbrRes])),
        bagage(bagage)
{
    setZValue(zIndex);
}


void VueBagage::advance(int pas)
{
    if(pas == 0)
    {
            return;
    }
    setPos(bagage->position());
}

void VueBagage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);
    image->render(painter, rect);
}

QRectF VueBagage::boundingRect() const
{
    return rect;
}
