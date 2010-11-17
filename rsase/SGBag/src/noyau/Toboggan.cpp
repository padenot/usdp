#include "Toboggan.h"
//Begin section for file Toboggan.cpp
//TODO: Add definitions that you want preserved
//End section for file Toboggan.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Toboggan::Toboggan(const QMap<QString,QString>& mapParam)
    :Element(mapParam)
{
    //TODO Auto-generated method stub
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
    delete bagage;
}

Troncon* Toboggan::tronconSupport()
{
    return _tronconSupport;
}
