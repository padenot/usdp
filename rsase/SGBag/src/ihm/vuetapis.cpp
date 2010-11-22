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
        _handler(*new VueTapisHandler(*this,fenetrePrincipale))
{
    QLineF direction = QLineF(QPoint(0, 0), _tapis.pointConnexion() - _tapis.position());
    QVector2D vecteurDir = QVector2D(_tapis.pointConnexion() - _tapis.position());

    _rect = QRectF(0,-largeur/2,direction.length(), largeur);

    setZValue(zIndex);
    setPos(_tapis.position() - (vecteurDir.normalized().toPointF() * (vue_config::chariot::largeur/2)));
    setRotation(-direction.angle());

    QAction* ajouterBagageAction = new QAction("Ajouter un bagage", 0);
    _contextMenuActionsList.append(ajouterBagageAction);
    QObject::connect(ajouterBagageAction, SIGNAL(triggered()), &(this->_handler), SLOT(ajouterBagage()));
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
    _image->render(painter, _rect);
}

QRectF VueTapis::boundingRect() const
{
    return _rect;
}

Tapis* VueTapis::tapisAssocie()
{
    return &_tapis;
}

/**
 * Constructeur du handler, dit au handler que VueTapis est le parent.
 */
VueTapisHandler::VueTapisHandler(VueTapis& vueTapis, FenetrePrincipale& fenetrePrincipale):
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

