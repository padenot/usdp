#include "vueelement.h"
#include <QDebug>
#include <QPainter>


VueElement::VueElement(FenetrePrincipale* _fenetrePrincipale):
        _fenetrePrincipale(_fenetrePrincipale), _contextMenu(0), _contextMenuActionsList()
{

    /* Exemple : Ajouter des QAction* au menu
    QAction* action = new QAction("Label", 0);
    //QObject::connect(action, SIGNAL(triggered()), this->handler, SLOT(slotPourMonAction()));
    contextMenuActionsList.append(action);
    //*/
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
    qDebug() << isSelected();
    // Si des actions sont définies pour le menu contextuel
    if(!_contextMenuActionsList.empty())
    {
        // On a pas encore renseigné les actions, il faut les ajouter
        if(_contextMenu.actions().empty())
            _contextMenu.addActions(_contextMenuActionsList);

        // On affiche
        // TODO il faut peut-être faire une conversion vers la "global pos"
        _contextMenu.exec(event->screenPos());
    }
}

void VueElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isSelected())
    {
        painter->setPen(Qt::red);
        // painter->setOpacity(0.4);
        QRectF rect = boundingRect();
        rect.setTopLeft(rect.topLeft() - QPoint(2,2));
        rect.setBottomRight(rect.bottomRight() + QPoint(2,2));
        painter->drawRoundedRect(rect,2,2);
        qDebug() << boundingRect();
    }
}

