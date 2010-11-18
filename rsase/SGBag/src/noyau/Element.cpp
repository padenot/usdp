#include "Element.h"
#include "XmlConfigFactory.h"
//Begin section for file Element.cpp
//TODO: Add definitions that you want preserved
//End section for file Element.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Element::Element(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        _position(indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::x]].toFloat(),
                  indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::y]].toFloat())
{
    // Vide
}

void Element::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    // Vide
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Element::~Element()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_h21_IPD4Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
QPointF Element::position()
{
    return _position;
}
