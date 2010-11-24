/**
 * @file Tapis.cpp
 * @author Martin Richard (martin.richard@insa-lyon.fr)
 */

#include <QPointF>
#include <QVector2D>

#include "Tapis.h"
#include "Noeud.h"

#include "XmlConfigFactory.h"

const double Tapis::RAYON_PROXIMITE_TRONCON = 0.5;
const double Tapis::VITESSE_MAX_DEFAUT = 3;

Tapis::Tapis(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        ElementActif(indexParamValeur),
        _bagages(),
        _chariotConnecte(0),
        _tronconSupport(0)
{
    _vitesseMax = VITESSE_MAX_DEFAUT;
    _vitesse = VITESSE_MAX_DEFAUT;
}

void Tapis::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                  XmlConfigFactory& fabrique)
{
    ElementActif::init(indexParamValeur,fabrique);
    Element::init(indexParamValeur,fabrique);
    _tronconSupport = dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()));
}

Tapis::~Tapis()
{
    // Destructeur
}

void Tapis::maj(double dt)
{
    // si un chariot est connecté au tapis
    if(_chariotConnecte != 0)
    {
        // Déroule le tapis (fait avancer les objets).
        deroulerTapis(dt);
    }
}

bool Tapis::ajouterBagage(Bagage* bagageEntrant)
{
    bagageEntrant->positionInitiale(*this);
    if(!_bagages.empty())
    {
        Bagage* dernierBagage = _bagages.last();
        // Vérifier la présence d'un bagage juste devant...
        if(QVector2D(dernierBagage->position()-bagageEntrant->position()).length() < 10*Bagage::TAILLE)
            return false;
    }

    // Connexion du bagage
    _bagages.push_back(bagageEntrant);
    return true;
}

void Tapis::deroulerTapis(double dt)
{
    QVector2D deplacement(_tronconSupport->position() - _position);
    deplacement.normalize();
    deplacement *= _vitesse*dt;

    // Pour chaque bagage sur le tapis
    for (QVector<Bagage*>::iterator it = _bagages.begin() ;
        it != _bagages.end() && _chariotConnecte != 0;
        ++it)
    {
        (*it)->simulerDeplacement(deplacement);

        if(bagageEstSorti(*it))
        {
            _chariotConnecte->chargerBagage(*it);
            _bagages.erase(it);
            deconnecter();
        }
    }
}

void Tapis::connecter (Chariot* chariot)
{
    if (_chariotConnecte == 0 && chariot != 0)
    {
        _chariotConnecte = chariot;
        chariot->connecter(this);
    }
}

void Tapis::deconnecter ()
{
    if (_chariotConnecte != 0)
    {
        Chariot* chariot = _chariotConnecte;
        _chariotConnecte = 0;
        chariot->deconnecter();
    }
}

Noeud::Chemin Tapis::trouverChemin(Noeud* positionActuelle)
{
    return positionActuelle->trouverChemin(_tronconSupport);
}

bool Tapis::estSupport (const Troncon* troncon) const
{
    return _tronconSupport == troncon;
}

/**
 * Compare les coordonnées du bagage aux coordonnées du tronçon suivant.
 */
bool Tapis::bagageEstSorti(Bagage *bagage)
{
    return QVector2D(bagage->position() - _tronconSupport->position()).length()
            < RAYON_PROXIMITE_TRONCON;
}

QPointF Tapis::pointConnexion() const
{
    return _tronconSupport->position();
}

/**
 * Pas de variation de vitesse pour un tapis.
 */
void Tapis::modifierVitesseMax(double nouvelleVitesseMax)
{
    _vitesseMax = nouvelleVitesseMax;
    _vitesse = _vitesseMax;
}
