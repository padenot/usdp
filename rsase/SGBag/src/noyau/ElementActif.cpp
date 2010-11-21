#include "ElementActif.h"
//Begin section for file ElementActif.cpp
//TODO: Add definitions that you want preserved
//End section for file ElementActif.cpp

const qreal ElementActif::VITESSE_DEFAUT = 0.05;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
ElementActif::ElementActif(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _vitesse (VITESSE_DEFAUT),
        _estActif(true)
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

/*void ElementActif::modifierVitesse(qreal nouvelleVitesse)
{
    _vitesse = nouvelleVitesse;
}*/

void ElementActif::arreter()
{
    // TODO : gérer la décrémentation progressive de la vitesse
    _estActif = false;
}

void ElementActif::demarrer()
{
    _estActif = true;
}

bool ElementActif::estActif ()
{
    return _estActif;
}

