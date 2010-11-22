#include "Bagage.h"
#include "Noeud.h"
#include "Vol.h"
//Begin section for file Bagage.cpp
//TODO: Add definitions that you want preserved
//End section for file Bagage.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Bagage::Bagage(Vol* vol, QPointF positionInitiale) :
        Element(XmlConfigFactory::IndexParamValeur()), // TODO : réfléchir à ce problème
        _vol(vol)
{
    _position = positionInitiale;
#ifdef DEBUG_ACHEMINEMENT
        _typeElement = "bagage";
#endif
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
    #ifdef DEBUG_ACHEMINEMENT
    qDebug() << "Nouvelle position du bagage "<< _position;
    #endif
    //TODO Auto-generated method stub
}

Toboggan* Bagage::objectifFinal()
{
    return _vol->tobogganAssocie();
}

