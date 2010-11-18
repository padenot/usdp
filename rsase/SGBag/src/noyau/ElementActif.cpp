#include "ElementActif.h"
//Begin section for file ElementActif.cpp
//TODO: Add definitions that you want preserved
//End section for file ElementActif.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
ElementActif::ElementActif()
{
    //TODO Auto-generated method stub
}


void ElementActif::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    Element::init(indexParamValeur,fabrique);
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
ElementActif::~ElementActif() 
{
    //TODO Auto-generated method stub
}

void ElementActif::modifierVitesse(double nouvelleVitesse)
{
    _vitesse = nouvelleVitesse;
}

void ElementActif::arreter()
{
    _estActif = false;
}

void ElementActif::demarrer()
{
    _estActif = true;
}

