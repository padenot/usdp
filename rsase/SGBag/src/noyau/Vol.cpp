#include "Vol.h"
//Begin section for file Vol.cpp
//TODO: Add definitions that you want preserved
//End section for file Vol.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Vol::Vol(const QString& nom) : _bagage(0), _dateDepart(0), _toboggan(0), _nom(nom)
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Vol::~Vol() 
{
    //TODO Auto-generated method stub
}

Toboggan* Vol::tobogganAssocie ()
{
    return _toboggan;
}

void Vol::associer(Toboggan* toboggan)
{
    _toboggan = toboggan;
}

QString Vol::nom()
{
    return _nom;
}
