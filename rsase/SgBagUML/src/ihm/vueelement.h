#ifndef VUEELEMENT_H
#define VUEELEMENT_H

#include "vuecanevas.h"

#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QList>
#include <QAction>

const  Qt::GlobalColor COULEUR_SELECTION = Qt::darkBlue;

class FenetrePrincipale;

/**
 * Classe abstraite qui regroupe des implémentations de méthodes pour les
 * vues graphiques des Element de la simulation.
 */
class VueElement : public VueCanevas
{
public:
	/**
	 * Constructeur.
	 * @param fenetrePrincipale Une référence vers la fenêtre principale.
	 */
    explicit VueElement(FenetrePrincipale& fenetrePrincipale);
    /**
     * Constructeur.
     * @param fenetrePrincipale Une référence vers la fenêtre principale.
     * @param boundingBox La boite englobante pour l'élément.
     */
    VueElement(FenetrePrincipale& fenetrePrincipale, QRectF boundingBox);
    /**
     * Le destructeur d'un élément.
     */
    virtual ~VueElement();
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
    /**
	* Dessiner l'élément graphique.
	* @param painter L'objet Qt pour dessiner.
	* @param option Des options en fonction  de l'environnement graphique.
	* @param widget Le widget sur lequel dessiner.
	*/
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
};

#endif // VUEELEMENT_H
