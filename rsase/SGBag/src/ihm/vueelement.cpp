#include "vueelement.h"

VueElement::VueElement(): contextMenu(0), contextMenuActionsList()
{
    setFlags(QGraphicsItem::ItemIsSelectable);

    /* Exemple : Ajouter des QAction* au menu
    QAction* action = new QAction("Label", this);
    QObject::connect(action, SIGNAL(triggered()), this, SLOT(slotPourMonAction()));
    contextMenuActionsList.append(action);
    //*/
}

VueElement::~VueElement()
{
    // Détruire les QAction*
    QList<QAction*>::iterator it;
    for(it = contextMenuActionsList.begin(); it != contextMenuActionsList.end(); ++it)
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
    if(!contextMenuActionsList.empty())
    {
        // On a pas encore renseigné les actions, il faut les ajouter
        if(contextMenu.actions().empty())
            contextMenu.addActions(contextMenuActionsList);

        // On affiche
        // TODO il faut peut-être faire une conversion vers la "global pos"
        contextMenu.exec(event->screenPos());
    }
}
