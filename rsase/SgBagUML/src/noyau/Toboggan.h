#ifndef TOBOGGAN_H
#define TOBOGGAN_H
#include <QMap>


#include "Element.h"
#include "XmlConfigFactory.h"
#include "Vol.h"
#include "Noeud.h"

class Bagage;
class Vol; //Dependency Generated Source:Toboggan Target:Vol
class Troncon; //Dependency Generated Source:Toboggan Target:Troncon

/**
  * @class Toboggan
  * @brief Classe gérant l'ensemble des opérations associées aux taboggans (e.g transfert de bagages)
  */
class Toboggan : public Element
{
    Q_OBJECT

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Toboggan(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_slcjoOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Toboggan();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_ZhHysO55Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void transfererBagage(Bagage* bagage);

        /**
         * @todo Définir une interface commune à Tapis et Toboggan pour cette méthode ? (IDestinationChariot ?)
         * @todo Commenter la méthode
         */
        Noeud::Chemin trouverChemin(Noeud* positionActuelle);


        /**
         * @todo Définir une interface commune à Tapis et Toboggan pour cette méthode ? (IDestinationChariot ?)
         * @todo commenter la méthode
         */
        bool estSupport (const Troncon* troncon) const;

        QPointF pointConnexion() const;
        void associerVol(Vol* vol);

        int nombreDeBagages() const;

        void nombreDeBagages(int);

    private:
        /**
         * @var compteur de bagages
         */
        int _nombreBagages;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_luU7wfCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Vol * _vol;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_hBPwkOspEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon * _tronconSupport;


};  //end class Toboggan


#endif
