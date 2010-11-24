#include "Troncon.h"
#include "Noeud.h"

Troncon::Troncon(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _chariotProprietaire(0),
        _noeudDebut(0),
        _noeudFin(0),
        _estHorsService(false)
{
    //TODO Auto-generated method stub
}


void Troncon::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                    XmlConfigFactory& fabrique)
{
    Element::init(indexParamValeur,fabrique);
    _noeudDebut = dynamic_cast<Noeud*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::noeudDebut]].toInt()));
    _noeudFin = dynamic_cast<Noeud*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::noeudFin]].toInt()));
    _position = (_noeudDebut->position() + _noeudFin->position()) / 2;
}

Troncon::~Troncon()
{
    //TODO Auto-generated method stub
}

bool Troncon::occuper(Chariot* chariotCandidat)
{
    if (_estHorsService)
    {
        return false;
    }
    else
    {
        if (_chariotProprietaire == 0
            || chariotCandidat == _chariotProprietaire)
        {
            _chariotProprietaire = chariotCandidat;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Troncon::liberer()
{
    _chariotProprietaire = 0;
}

bool Troncon::mettreHorsService()
{
    if (_chariotProprietaire == 0)
    {
        _estHorsService = true;
        emit etatModifie();
        return true;
    }
    else
    {
        return false;
    }
}

void Troncon::reparer()
{
    if (_estHorsService)
    {
        _estHorsService = false;
        emit etatModifie();
    }
}

Noeud* Troncon::noeudFin()
{
    return _noeudFin;
}

Noeud* Troncon::noeudDebut()
{
    return _noeudDebut;
}

Troncon::EtatTroncon Troncon::etat()
{
    if (_estHorsService)
    {
        return HORS_SERVICE;
    }
    else if (_chariotProprietaire == 0)
    {
        return LIBRE;
    }
    else
    {
        return OCCUPE;
    }
}
