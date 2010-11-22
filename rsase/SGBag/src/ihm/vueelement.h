#ifndef VUEELEMENT_H
#define VUEELEMENT_H

#include "vuecanevas.h"

#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QList>
#include <QAction>

const  Qt::GlobalColor COULEUR_SELECTION = Qt::darkBlue;

class FenetrePrincipale;

class VueElement : public VueCanevas
{
public:
    explicit VueElement(FenetrePrincipale& fenetrePrincipale);
    VueElement(FenetrePrincipale& fenetrePrincipale, QRectF boundingBox);
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
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
};

#endif // VUEELEMENT_H
