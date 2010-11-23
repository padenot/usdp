#include "src/ihm/vuechariot.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::chariot;

VueChariot::VueChariot(FenetrePrincipale& fenetrePrincipale, Chariot &chariot):
        VueElement(fenetrePrincipale,rect),
        _image(new QSvgRenderer(etatNormal)),
        _chariot(chariot),
        _pixmap(200, 200),
        _paintPixmap(&_pixmap)
{
    setZValue(zIndex);
    setPos(chariot.position());

    _image->render(&_paintPixmap);

    /* Affichage de l'id du chariot
       Valable avec les nouveaux rendus.*/

    _paintPixmap.setFont (font);
    QTransform matriceActuelle = _paintPixmap.transform();
    QTransform matriceTexte;
    matriceTexte.translate(dxTexte,dyTexte);
    matriceTexte.rotate(rotationTexte);
    _paintPixmap.setTransform(matriceTexte);
    _paintPixmap.setPen(couleurTexte);
    _paintPixmap.drawText(QRectF(0,0,200,100), Qt::AlignLeft, QString::number(_chariot.id()));
    _paintPixmap.setTransform(matriceActuelle);//*/
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

    painter->drawPixmap(rect, _pixmap, QRectF(0, 0, 200, 200));
}

Chariot& VueChariot::chariot()
{
    return _chariot;
}
