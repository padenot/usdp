#include "Vol.h"
#include "Toboggan.h"
//Begin section for file Vol.cpp
//TODO: Add definitions that you want preserved
//End section for file Vol.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Vol::Vol()
{
    //TODO Auto-generated method stub
}

void Vol::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    // TODO
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Vol::~Vol() 
{
    //TODO Auto-generated method stub
}

Troncon* Vol::tronconAcces()
{
    if (_toboggan != 0)
    {
        return _toboggan->tronconSupport();
    }
    else
    {
        return 0;
    }
}
