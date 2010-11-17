#ifndef TRONCON_H
#define TRONCON_H
//Begin section for file Troncon.h
//TODO: Add definitions that you want preserved
//End section for file Troncon.h

#include <QMap>

#include "Element.h"


class Noeud;
class Chariot; //Dependency Generated Source:Troncon Target:Chariot

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Troncon : public Element
{

    //Begin section for Troncon
    //TODO: Add attributes that you want preserved
    //End section for Troncon

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_0QxHMOsuEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Noeud * _noeudFin;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_akvbYO5DEd-dcpIgUje6-w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Chariot * _chariot;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_5u8RMOtcEd-6Qct7MaUvyw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Noeud * _noeudDebut;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_bOJUIPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //unsigned long longueur;

        bool _estLibre;


    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon(const QMap<QString,QString>& mapParam);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Troncon();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_3ZUsUPD8Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        bool occuper();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_WmO0QPD9Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void liberer();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_CIZ-wPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Noeud* noeudFin();

};  //end class Troncon

#endif
