#ifndef BAGAGE_H
#define BAGAGE_H
//Begin section for file Bagage.h
//TODO: Add definitions that you want preserved
//End section for file Bagage.h

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


    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage();

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Bagage();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qKAMUPDxEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void simulerDeplacement(double x, double y);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_yl4N8PIZEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * @todo Définir une interface commune à Tapis et Bagage pour cette méthode ? (IDestinationChariot ?)
         * @todo Commenter la méthode
         */
        Troncon* trouverObjectifImmediat(Noeud* positionActuelle);

        /**
         * @todo Définir une interface commune à Tapis et Bagage pour cette méthode ? (IDestinationChariot ?)
         * @todo commenter la méthode
         */
        bool estObjectifFinal (const Troncon* troncon);

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_j91OgfCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Vol * _vol;
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_UjYFQPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //std::string description;


};  //end class Bagage

#endif
