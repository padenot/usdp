#include "vuebagage.h"

const QRectF VueBagage::rect(VueBagage::longueur/2,VueBagage::largeur/2,VueBagage::longueur,VueBagage::largeur);

VueBagage::VueBagage():
    imageFile(":/images/bagages-image"),
    image(imageFile)
{
    //setZValue()
    //set default state
    //set image

}


void VueBagage::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //bagage.getPos();
        x++;
        y++;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //painter->drawImage(rect, svg);
    painter->setBrush(QColor(0, 0, 0));
    painter->drawEllipse(QPoint(x, y), 10, 20);
}
