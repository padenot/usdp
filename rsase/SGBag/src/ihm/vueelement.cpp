#include "vueelement.h"
#include "vueconfig.h"

#include <QPainter>

using namespace vue_config::element;

VueElement::VueElement(FenetrePrincipale& fenetrePrincipale):
        VueCanevas(fenetrePrincipale),
        _contextMenu(0),
        _contextMenuActionsList()
{
}

VueElement::VueElement(FenetrePrincipale& fenetrePrincipale,
                       QRectF rect):
        VueCanevas(fenetrePrincipale,rect),
        _contextMenu(0),
        _contextMenuActionsList()
{
}

VueElement::~VueElement()
{
    // Détruire les QAction*
    QList<QAction*>::iterator it;
    for(it = _contextMenuActionsList.begin(); it != _contextMenuActionsList.end(); ++it)
    {
        delete *it;
    }

}

/**
 * Affiche un menu contextuel si des actions ont été renseignées dans la liste
 * contextMenuActionsList.
 */
void VueElement::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // Si des actions sont définies pour le menu contextuel
    if(!_contextMenuActionsList.empty())
    {
        // On a pas encore renseigné les actions, il faut les ajouter
        if(_contextMenu.actions().empty())
            _contextMenu.addActions(_contextMenuActionsList);

        // On affiche
        _contextMenu.exec(event->screenPos());
    }
}

void VueElement::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    if(isSelected())
    {
        painter->setBrush(brushSelection);
        painter->setPen(penSelection);
        painter->setOpacity(opacite);
        painter->drawRoundedRect(boundingRect(),arrondis,arrondis);
        painter->setOpacity(1);
    }
}

