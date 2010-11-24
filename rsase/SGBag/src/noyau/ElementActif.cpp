#include "ElementActif.h"
//Begin section for file ElementActif.cpp
//TODO: Add definitions that you want preserved
//End section for file ElementActif.cpp

const double ElementActif::VITESSE_DEFAUT = 10; // m/s
const double ElementActif::VITESSE_MAX_DEFAUT = 20; // m/s

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
ElementActif::ElementActif(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _vitesse (VITESSE_DEFAUT),
        _vitesseMax (VITESSE_MAX_DEFAUT),
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

/*void ElementActif::modifierVitesse(double nouvelleVitesse)
{
    _vitesse = nouvelleVitesse;
}*/

void ElementActif::freiner()
{
    if (_estActif)
    {
        _estActif = false;
        emit activationModifiee(false);
    }
}

void ElementActif::accelerer()
{
    if (!_estActif)
    {
        _estActif = true;
        emit activationModifiee(true);
    }
}

void ElementActif::definirActivation (bool estActif)
{
    _estActif = estActif;
}

void ElementActif::modifierVitesseMax(double nouvelleVitesseMax)
{
    _vitesseMax = nouvelleVitesseMax;
}


bool ElementActif::estActif ()
{
    return _estActif;
}

double ElementActif::vitesse() {
    return _vitesse;
}

double ElementActif::vitesseMax ()
{
    return _vitesseMax;
}
