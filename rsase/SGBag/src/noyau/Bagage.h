#ifndef BAGAGE_H
#define BAGAGE_H
//Begin section for file Bagage.h
//TODO: Add definitions that you want preserved
//End section for file Bagage.h

#include <string>
#include <QMap>

#include "Element.h"

class Troncon;
class Noeud;
class Vol; //Dependency Generated Source:Bagage Target:Vol

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Bagage : public Element
{

    //Begin section for Bagage
    //TODO: Add attributes that you want preserved
    //End section for Bagage

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_j91OgfCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Vol * _vol;
        int a;
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_UjYFQPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //std::string description;



    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage(const QMap<QString,QString>& mapParam);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Bagage();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qKAMUPDxEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void simulerDeplacement(double x, double y);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_yl4N8PIZEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon* trouverObjectifImmediat(Noeud* positionActuelle);

};  //end class Bagage

#endif
