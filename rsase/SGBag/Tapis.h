#ifndef TAPIS_H
#define TAPIS_H
//Begin section for file Tapis.h
//TODO: Add definitions that you want preserved
//End section for file Tapis.h

#include "ElementActif.h"
#include "Bagage.h"
#include "Chariot.h"


class Troncon; //Dependency Generated Source:Tapis Target:Troncon

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Tapis : ElementActif
{

    //Begin section for Tapis
    //TODO: Add attributes that you want preserved
    //End section for Tapis

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_tziQ8eshEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage * bagage;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_fSJGQeswEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Chariot * chariotConnecte;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_TYtfcfDpEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon * tronconSupport;



    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_4ChQwPDwEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void deroulerTapis();

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Tapis();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Tapis();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_JpFKsO5zEd-X2qSx1xpmxg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void maj();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_wD2mgO5-Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void ajouterBagage(Bagage* bagageEntrant);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__9W_YPD7Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void connecter(Chariot* chariot);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__aB14PIZEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon* trouverObjectifImmediat();

};  //end class Tapis

#endif
