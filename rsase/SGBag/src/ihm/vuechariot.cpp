#include "src/ihm/vuechariot.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::chariot;

VueChariot::VueChariot(FenetrePrincipale& fenetrePrincipale, Chariot &chariot):
        VueElement(fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _chariot(chariot)
{
    setZValue(zIndex);
    setPos(chariot.position());
}

void VueChariot::advance(int pas)
{
        if(pas == 0)
        {
                return;
        }
        setPos(_chariot.position());
}

void VueChariot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);

    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    _image->render(painter, rect);

    /*QPixmap *pixmap = new QPixmap();
    QPainter paintPixmap(pixmap);
    _image->render(paintPixmap);

    painter->drawPixmap(pixmap);*/

    QFont f ("Courier", 2, QFont::Normal);
    painter->setFont (f);

    painter->drawText(QRectF(5,5,100,100), Qt::AlignLeft, "Ici, la description d'un chariot\n sur plusieurs lignes");
}

QRectF VueChariot::boundingRect() const
{
    return rect;
}

Chariot& VueChariot::chariot()
{
    return _chariot;
}
