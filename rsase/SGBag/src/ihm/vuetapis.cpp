#include "src/ihm/vuetapis.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Troncon.h"
#include "src/ihm/fenetreprincipale.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::tapis;

VueTapis::VueTapis(FenetrePrincipale* _fenetrePrincipale, Tapis *tapis):
        VueElement(_fenetrePrincipale),
        image(new QSvgRenderer(etatNormal)),
        tapis(tapis)
{
    setZValue(zIndex);
    setPos(tapis->position());

    handler = new VueTapisHandler(this);



    QAction* ajouterBagageAction = new QAction("Ajouter un bagage", 0);
    contextMenuActionsList.append(ajouterBagageAction);
    QObject::connect(ajouterBagageAction, SIGNAL(triggered()), this->handler, SLOT(ajouterBagage()));
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
    image->render(painter, rect);
}

void VueTapis::ajouterBagage()
{
    fenetrePrincipale->modeAjoutBagage(this);
    //VueGlobale.ajoutBagage(tapis);
}

QRectF VueTapis::boundingRect() const
{
    return rect;
}

Tapis* VueTapis::tapisAssocie()
{
    return tapis;
}

/**
 * Constructeur du handler, dit au handler que VueTapis est le parent.
 */
VueTapisHandler::VueTapisHandler(VueTapis * parent):
        vueTapis(parent)
{
}

/**
 * Action quand l'utilisateur veut ajouter un bagage.
 */
void VueTapisHandler::ajouterBagage()
{
    vueTapis->ajouterBagage();
}
