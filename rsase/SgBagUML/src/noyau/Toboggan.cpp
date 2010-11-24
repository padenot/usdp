#include "Toboggan.h"
#include "Bagage.h"
#include "Noeud.h"

Toboggan::Toboggan(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _nombreBagages(0),
        _tronconSupport(0)
{
    //TODO Auto-generated method stub
}

void Toboggan::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                     XmlConfigFactory& fabrique)
{
    Element::init(indexParamValeur,fabrique);
    _tronconSupport = dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()));
}

Toboggan::~Toboggan()
{
    //TODO Auto-generated method stub
}

void Toboggan::transfererBagage(Bagage* bagage)
{
    ++_nombreBagages;
    delete bagage;
    emit nombreDeBagages(_nombreBagages);
}


Noeud::Chemin Toboggan::trouverChemin(Noeud* positionActuelle)
{
    return positionActuelle->trouverChemin(_tronconSupport);
}

bool Toboggan::estSupport (const Troncon* troncon) const
{
    return _tronconSupport == troncon;
}

QPointF Toboggan::pointConnexion() const
{
    return _tronconSupport->position();
}

void Toboggan::associerVol(Vol* vol)
{
    _vol = vol;
}

int Toboggan::nombreDeBagages() const
{
    return _nombreBagages;
}

