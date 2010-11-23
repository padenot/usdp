#include <QtSvg/QSvgRenderer>
#include <QVector2D>

#include "src/ihm/vuetroncon.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Noeud.h"


using namespace vue_config::troncon;

VueTroncon::VueTroncon(FenetrePrincipale& fenetrePrincipale, Troncon& troncon):
        VueElement(fenetrePrincipale),
        _troncon(troncon),
        _vecteurDirection(_troncon.noeudDebut()->position() - _troncon.noeudFin()->position()),
        _lignePerpendiculaire(QPointF(0,0), _vecteurDirection.toPointF()),
        _handler(*new VueTronconHandler(*this,fenetrePrincipale))
{
    setZValue(zIndex);

    definirCoordonnees(_troncon.noeudDebut()->position(),
                       _troncon.noeudFin()->position(),
                       largeur);

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
}

void VueTroncon::reparer()
{
    _troncon.reparer();
}

void VueTroncon::advance(int pas)
{
}

void VueTroncon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    double longueur = QVector2D(_troncon.noeudDebut()->position() -
                                _troncon.noeudFin()->position()).length();
    VueElement::paint(painter,0,0);

    painter->setBrush(brushGray);

    painter->setPen(penDark);
    // Dessin du noeud de début
    painter->drawEllipse(QPointF(), largeur*1.2, largeur*1.2);
    // Dessin du noeud de fin
    painter->drawEllipse(QPointF(longueur, 0), largeur*1.2, largeur*1.2);

    if (_troncon.etat() == Troncon::HORS_SERVICE)
    {
        double espaceBrise = qMin(largeurEspaceBrise,longueur/4);
        //painter->setPen(penLight);
        //painter->drawPolygon(_fond, 4);

        painter->setPen(penDark);
        // Dessin de la ligne brisée n° 1
        painter->drawLine(0,-largeur,longueur/2-espaceBrise,-largeur);
        painter->drawLine(longueur/2+espaceBrise,-largeur,longueur,-largeur);
        // Dessin du bris de la ligne 1
        // TODO
        // Dessin de la ligne brisée n° 2
        painter->drawLine(0,largeur,longueur/2-espaceBrise,largeur);
        painter->drawLine(longueur/2+espaceBrise,largeur,longueur,largeur);
        // Dessin du bris de la ligne 2
        // TODO
    }
    else
    {
        //painter->setPen(penLight);
        //painter->drawPolygon(_fond, 4);

        painter->setPen(penDark);
        // Dessin des deux lignes du rail
        painter->drawLine(0,-largeur,longueur,-largeur);
        painter->drawLine(0,largeur,longueur,largeur);
    }
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
