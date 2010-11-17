#ifndef CHARIOT_H
#define CHARIOT_H
//Begin section for file Chariot.h
//TODO: Add definitions that you want preserved
//End section for file Chariot.h

#include "ElementActif.h"
#include "Bagage.h"


class Troncon; //Dependency Generated Source:Chariot Target:Troncon
class Tapis; //Dependency Generated Source:Chariot Target:Tapis

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Chariot : public ElementActif
{

    //Begin section for Chariot
    //TODO: Add attributes that you want preserved
    //End section for Chariot

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_klhKcOybEd-q55IxPzNK8w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage * bagage;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_alMHUO5DEd-dcpIgUje6-w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon * troncon;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1bIQYPDzEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Tapis * tapisAssocie;



    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pgh1sO55Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void dechargerBatterie();

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Chariot();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Chariot();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_XNzMkO52Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void chargerBagage(Bagage* bagage);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_r3Lz8PD-Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void avancer();

        virtual void arreter();

        virtual void demarrer();

        virtual void maj();

};  //end class Chariot

#endif
