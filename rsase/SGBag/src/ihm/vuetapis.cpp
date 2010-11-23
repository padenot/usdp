#include <QtSvg/QSvgRenderer>
#include <QLineF>

#include "src/ihm/vuetapis.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Troncon.h"
#include "src/ihm/fenetreprincipale.h"

using namespace vue_config::tapis;

VueTapis::VueTapis(FenetrePrincipale& fenetrePrincipale, Tapis &tapis):
        VueElement(fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _tapis(tapis),
        _pixmap(200, 200),
        _paintPixmap(&_pixmap),
        _handler(*new VueTapisHandler(*this,fenetrePrincipale))
{
    setZValue(zIndex);
    definirCoordonnees(_tapis.position(),_tapis.pointConnexion(),
                       largeur,vue_config::chariot::largeur/2);

    QAction* ajouterBagageAction = new QAction("Ajouter un bagage", 0);
    _contextMenuActionsList.append(ajouterBagageAction);
    QObject::connect(ajouterBagageAction, SIGNAL(triggered()), &(this->_handler), SLOT(ajouterBagage()));

    _image->render(&_paintPixmap);
}

VueTapis::~VueTapis()
{
    delete &_handler;
    delete _image;
}


void VueTapis::advance(int pas)
{
    if(!pas)
    {
            return;
    }

    //setPos(tapis->position());
}

void VueTapis::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);

    painter->drawPixmap(_rect, _pixmap, QRectF(0, 0, 200, 200));
}

Tapis* VueTapis::tapisAssocie()
{
    return &_tapis;
}

/**
 * Constructeur du handler, dit au handler que VueTapis est le parent.
 */
VueTapisHandler::VueTapisHandler(VueTapis& vueTapis,
                                 FenetrePrincipale& fenetrePrincipale):
        _vueTapis(vueTapis),
        _fenetrePrincipale(fenetrePrincipale)
{
}

/**
 * Action quand l'utilisateur veut ajouter un bagage.
 */
void VueTapisHandler::ajouterBagage()
{
    _fenetrePrincipale.ajoutBagage(_vueTapis);
}

