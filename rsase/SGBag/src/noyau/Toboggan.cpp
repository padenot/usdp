#include "Toboggan.h"
#include "Bagage.h"
#include "Noeud.h"
//Begin section for file Toboggan.cpp
//TODO: Add definitions that you want preserved
//End section for file Toboggan.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Toboggan::Toboggan(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _tronconSupport(0),
        _nombreBagages(0)
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

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Toboggan::~Toboggan()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_ZhHysO55Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Toboggan::transfererBagage(Bagage* bagage)
{
    ++_nombreBagages;
    // TODO : faire avancer le bagage ?
    delete bagage;
    emit nombreDeBagages(_nombreBagages);
}


Troncon* Toboggan::trouverObjectifImmediat(Noeud* positionActuelle)
{
    return positionActuelle->trouverProchainTroncon(_tronconSupport);
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

