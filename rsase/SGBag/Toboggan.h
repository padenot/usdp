#ifndef TOBOGGAN_H
#define TOBOGGAN_H
//Begin section for file Toboggan.h
//TODO: Add definitions that you want preserved
//End section for file Toboggan.h

#include "Element.h"

class Bagage;
class Vol; //Dependency Generated Source:Toboggan Target:Vol
class Troncon; //Dependency Generated Source:Toboggan Target:Troncon

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Toboggan : Element
{

    //Begin section for Toboggan
    //TODO: Add attributes that you want preserved
    //End section for Toboggan

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_luU7wfCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Vol * vol;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_hBPwkOspEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon * tronconSupport;



    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Toboggan();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Toboggan();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_ZhHysO55Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void transfererBagage(Bagage* bagage);

};  //end class Toboggan

#endif
