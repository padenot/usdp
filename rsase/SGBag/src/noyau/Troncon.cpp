#include "Troncon.h"
//Begin section for file Troncon.cpp
//TODO: Add definitions that you want preserved
//End section for file Troncon.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon::Troncon()
{
    //TODO Auto-generated method stub
}


void Troncon::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                    XmlConfigFactory& fabrique) : _noeudFin(0), _noeudDebut(0), _chariot(0), _estLibre(0)
{
    Element::init(indexParamValeur,fabrique);
    _noeudDebut = dynamic_cast<Noeud*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::noeudDebut]]));
    _noeudFin = dynamic_cast<Noeud*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::noeudFin]]));
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon::~Troncon()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_3ZUsUPD8Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool Troncon::occuper()
{
    //TODO Auto-generated method stub
    if (_estLibre)
    {
        _estLibre = false;
        return true;
    }
    else
    {
        return false;
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_WmO0QPD9Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Troncon::liberer()
{
    _estLibre = true;
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_CIZ-wPG5Ed-XFOLnxrkHLA"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Noeud* Troncon::noeudFin()
{
    return _noeudFin;
}
