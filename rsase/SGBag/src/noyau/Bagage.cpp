#include "Bagage.h"
#include "Noeud.h"
#include "Vol.h"
//Begin section for file Bagage.cpp
//TODO: Add definitions that you want preserved
//End section for file Bagage.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Bagage::Bagage(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur)
{
    //TODO Auto-generated method stub
}

void Bagage::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    Element::init(indexParamValeur,fabrique);
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Bagage::~Bagage()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qKAMUPDxEd-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Bagage::simulerDeplacement(const QVector2D& deplacement)
{
    _position += deplacement.toPointF();
    //TODO Auto-generated method stub
}

Toboggan* Bagage::objectifFinal()
{
    return _vol->tobogganAssocie();
}

