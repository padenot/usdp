#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <QMap>
#include <QVector>
#include <QTimer>

//Begin section for file Prototype.h
//TODO: Add definitions that you want preserved
//End section for file Prototype.h


class Element; //Dependency Generated Source:Prototype Target:Element

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"

/**
 * Prototype de la simulation : classe d'entrée de la simulation.
 */
class Prototype
{

    //Begin section for Prototype
    //TODO: Add attributes that you want preserved
    //End section for Prototype

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pf5ngOygEd-0NvPstdZN1w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * Map des ID sur des pointeurs d'éléments
         */
        QMap<int, Element*> _idSurElements;



        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qtglIPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * Vitesse de la simulation.
         */
        double _vitesseSimulation;

        /**
         * Ce timer règle la vitesse de la simulation, il envoie un évènement à chaque tick.
         */
        QTimer _timer;



    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * Construit un prototype, et instancie les objets a partir du fichier
         * XML passé en paramêtre.
         */
        Prototype(const QString& xmlfilepath);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * Detruit tous les objets de la simulation.
         */
        virtual ~Prototype();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_oCLrkO59Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        bool modeManuel();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_0yUWMO59Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void ajouterBagage();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Eq-X8PCiEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        bool modeAjoutBagage();

};  //end class Prototype

#endif
