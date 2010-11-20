#ifndef VUEELEMENT_H
#define VUEELEMENT_H

#include "vue.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QList>
#include <QAction>

class VueElement : public Vue
{
public:
    VueElement();
    ~VueElement();

protected:
    /**
     * @var contextMenu Menu contextuel
     */
    QMenu contextMenu;

    /**
     * @var contextMenuActionsList Liste des actions du menu contextuel, doit être rempli dans le constructeur
     */
    QList<QAction*> contextMenuActionsList;

    /**
     * Event handler appelé quand l'utilisateur souhaite afficher le menu contextuel.
     * @param *event Evenement utilisateur
     */
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif // VUEELEMENT_H
