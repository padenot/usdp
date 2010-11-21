#ifndef VUEELEMENT_H
#define VUEELEMENT_H

#include "vue.h"

#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QList>
#include <QAction>

const  Qt::GlobalColor COULEUR_SELECTION = Qt::darkBlue;

class FenetrePrincipale;

class VueElement : public Vue
{
public:
    VueElement(FenetrePrincipale* _fenetrePrincipale);
    ~VueElement();

protected:
    /**
     * @var contextMenu Menu contextuel
     */
    QMenu _contextMenu;

    /**
     * @var contextMenuActionsList Liste des actions du menu contextuel, doit être rempli dans le constructeur
     */
    QList<QAction*> _contextMenuActionsList;

    /**
     * Event handler appelé quand l'utilisateur souhaite afficher le menu contextuel.
     * @param *event Evenement utilisateur
     */
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @var fenetrePrincipale pointeur vers la fenêtre principale.
     */
    FenetrePrincipale* _fenetrePrincipale;
};

#endif // VUEELEMENT_H
