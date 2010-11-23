/**
  * @file Bagage.h
  */

#ifndef BAGAGE_H
#define BAGAGE_H
#include <QVector2D>

#include "Element.h"

class Toboggan;
class Troncon;
class Noeud;
class Vol; //Dependency Generated Source:Bagage Target:Vol

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
/**
  * @class Bagage 
* @brief Classe gérant l'association d'un bagage avec un ou plusieurs vols et l'accès aux informations de celui-ci telles que la position courante ou l'objectif final.
*/
class Bagage : public Element
{
    Q_OBJECT

    public:
        static const double TAILLE;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1cuGUOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage(Vol* vol, QPointF positionInitiale);

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
        /**
         * Donne le vol associé à ce bagage.
         * @return Le vol associé à ce bagage.
         */
        Vol* volAssocie();

        /**
         * Met à jour la position d'après la position de l'élément de départ.
         * @param Element& tapis de départ
         */
        void positionInitiale(Element&);


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
