#include <QtSvg/QSvgRenderer>

#include "src/ihm/vuebagage.h"
#include "src/ihm/vueconfig.h"

using namespace vue_config::bagage;

VueBagage::VueBagage(FenetrePrincipale& fenetrePrincipale, Bagage &bagage):
        VueElement(fenetrePrincipale),
        //_image(new QSvgRenderer(resBagage[rand() % nbrRes])),
        _image(new QSvgRenderer(bagageSimple)), // TODO : restaurer le rand
        _bagage(bagage)
{
    setZValue(zIndex);
}


void VueBagage::advance(int pas)
{
    if(pas == 0)
    {
            return;
    }
    setPos(_bagage.position());
}

void VueBagage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);

    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    _image->render(painter, rect);
}

QRectF VueBagage::boundingRect() const
{
    return rect;
}


Bagage* VueBagage::bagageAssocie()
{
    return &_bagage;
}
