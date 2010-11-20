#ifndef BAGAGE_H
#define BAGAGE_H
//Begin section for file Bagage.h
//TODO: Add definitions that you want preserved
//End section for file Bagage.h

#include <QVector2D>

#include "Element.h"

class Toboggan;
class Troncon;
class Noeud;
class Vol; //Dependency Generated Source:Bagage Target:Vol

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Bagage : public Element
{
    Q_OBJECT

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage(Vol* vol);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Bagage();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qKAMUPDxEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void simulerDeplacement(const QVector2D& deplacement);


        /** Renvoie le toboggan sur lequel doit être déposé le bagage.
         * @return Le toboggan sur lequel doit être déposé le bagage.
         */
        Toboggan* objectifFinal();


        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_yl4N8PIZEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_j91OgfCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Vol * _vol;
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_UjYFQPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //std::string description;


};  //end class Bagage

#endif
