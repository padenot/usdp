#include "src/ihm/vuebagage.h"
#include <QtSvg/QSvgRenderer>

const QRectF VueBagage::rect(VueBagage::longueur/2,VueBagage::largeur/2,VueBagage::longueur,VueBagage::largeur);
const QString VueBagage::etatNormal(FILEPATH_SVG_ETATNORMAL);

VueBagage::VueBagage():
        image(new QSvgRenderer())
{

    image->load(etatNormal);

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
        setPos(x()+1,y()+1);
}

void VueBagage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    image->render(painter);
    //painter->drawImage(rect, svg);
    //painter->setBrush(QColor(0, 0, 0));
    //painter->drawEllipse(QPoint(x, y), 10, 20);
}

QPainterPath VueBagage::shape() const
{
    QPainterPath shape(QPointF(10,10));
    return shape;
}

QRectF VueBagage::boundingRect() const
{
    QRectF rect(QPoint(-5,-5), QPoint(5,5));
    return rect;
}
