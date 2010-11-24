#include <QDebug>
#include <QtSvg/QSvgRenderer>
#include <QLineF>

#include "src/ihm/vuetapis.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Troncon.h"
#include "src/ihm/fenetreprincipale.h"

using namespace vue_config::tapis;

QSvgRenderer *VueTapis::_renderer = new QSvgRenderer(etatNormal);

VueTapis::VueTapis(FenetrePrincipale& fenetrePrincipale, Tapis &tapis):
        VueElement(fenetrePrincipale),
        _image(new QGraphicsSvgItem()),
        _tapis(tapis),
        _handler(*new VueTapisHandler(*this,fenetrePrincipale))
{
    setZValue(zIndex);
    _image->setSharedRenderer(_renderer);

    definirCoordonnees(_tapis.position(),_tapis.pointConnexion(),
                       largeur,-vue_config::chariot::largeur/2);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    _image->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    QAction* ajouterBagageAction = new QAction("Ajouter un bagage", 0);
    _contextMenuActionsList.append(ajouterBagageAction);
    QObject::connect(ajouterBagageAction, SIGNAL(triggered()), &(this->_handler), SLOT(ajouterBagage()));

    _image->renderer()->setFramesPerSecond(vue_config::fps);
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _image->renderer()->isValid();
#endif
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
}

void VueTapis::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);
    _image->renderer()->render(painter, boundingRect());
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
    // S'il n'y a pas de vol, on refuse l'ajout, l'utilisateur serait bloqué
    // en mode ajout de bagages.
   if(_fenetrePrincipale.nombreVols() != 0)
    _fenetrePrincipale.ajoutBagage(_vueTapis);
   else
       _fenetrePrincipale.messageBarreDeStatus("Impossible d'ajouter un bagage : aucun vol disponible.",2000);
}

