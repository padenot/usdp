#include "Bagage.h"
#include "Noeud.h"
#include "Vol.h"
//Begin section for file Bagage.cpp
//TODO: Add definitions that you want preserved
//End section for file Bagage.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Bagage::Bagage()
{
    //TODO Auto-generated method stub
}

void Bagage::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    Element::init(indexParamValeur,fabrique);
    // TODO
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Bagage::~Bagage()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qKAMUPDxEd-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Bagage::simulerDeplacement(double x, double y)
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_yl4N8PIZEd-TbK1o_cJlKw"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon* Bagage::trouverObjectifImmediat(Noeud* positionActuelle)
{
    return positionActuelle->trouverProchainTroncon(_vol->tronconAcces());
}

bool Bagage::estObjectifFinal (const Troncon* troncon)
{
    return _vol->tronconAcces() == troncon;
}
