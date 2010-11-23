#include <QtSvg/QSvgRenderer>
#include <QVector2D>

#include "src/ihm/vuetroncon.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Noeud.h"


using namespace vue_config::troncon;

VueTroncon::VueTroncon(FenetrePrincipale& fenetrePrincipale, Troncon& troncon):
        VueElement(fenetrePrincipale),
        _troncon(troncon),
        _handler(*new VueTronconHandler(*this,fenetrePrincipale))
{
    setZValue(zIndex);

    definirCoordonnees(_troncon.noeudDebut()->position(),
                       _troncon.noeudFin()->position(),
                       2*largeur);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    QAction* mettreEnPanneAction = new QAction(QObject::trUtf8("Mettre en panne"), 0);
    QAction* reparerAction = new QAction(QObject::trUtf8("Réparer"), 0);
    _contextMenuActionsList.append(mettreEnPanneAction);
    _contextMenuActionsList.append(reparerAction);
    QObject::connect(mettreEnPanneAction, SIGNAL(triggered()), &_handler, SLOT(mettreHorsService()));
    QObject::connect(reparerAction, SIGNAL(triggered()), &_handler, SLOT(reparer()));

}

VueTroncon::~VueTroncon()
{
    delete &_handler;
}

void VueTroncon::mettreHorsService()
{
    _troncon.mettreHorsService();
    update();
}

void VueTroncon::reparer()
{
    _troncon.reparer();
    update();
}

void VueTroncon::advance(int pas)
{

}

void VueTroncon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    double longueur = QVector2D(_troncon.noeudDebut()->position() -
                                    _troncon.noeudFin()->position()).length();

    VueElement::paint(painter,0,0);

    //------------ Choix des couleurs du tronçon
    if (_troncon.etat() == Troncon::HORS_SERVICE)
    {
        painter->setPen(penRedLight);
        painter->setBrush(brushRed);
    }
    else
    {
        painter->setPen(penLight);
        painter->setBrush(brushGray);
    }

    //------------ Dessin du tronçon
    painter->drawRect(QRectF(0,-largeur,longueur,2.0*largeur));

    //------------ Choix des couleurs des noeuds
    if (_troncon.etat() == Troncon::HORS_SERVICE)
    {
        painter->setPen(penRedDark);
    }
    else
    {
        painter->setPen(penDark);
    }

    painter->drawLine(QPointF(0,-largeur),QPointF(longueur,-largeur));
    painter->drawLine(QPointF(0,largeur),QPointF(longueur,largeur));

    //------------ Dessin des noeuds
    painter->setBrush(brushGray);
    painter->setPen(penDark);
    // Dessin du noeud de début
    painter->drawEllipse(QPointF(0,0),
                         rayonNoeud, rayonNoeud);
    // Dessin du noeud de fin
    painter->drawEllipse(QPointF(longueur, 0),
                         rayonNoeud, rayonNoeud);
}

/**
 * Constructeur du handler, dit au handler que VueTroncon est le parent.
 */
VueTronconHandler::VueTronconHandler(VueTroncon& vueTroncon,
                                     FenetrePrincipale& fenetrePrincipale):
        _vueTroncon(vueTroncon),
        _fenetrePrincipale(fenetrePrincipale)
{
}

/**
 * Action quand l'utilisateur veut mettre le tronçon en panne.
 */
void VueTronconHandler::mettreHorsService()
{
    _vueTroncon.mettreHorsService();
}

/**
 * Action quand l'utilisateur veut réparer le tronçon.
 */
void VueTronconHandler::reparer()
{
    _vueTroncon.reparer();
}
