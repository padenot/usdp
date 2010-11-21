#ifndef CHARIOT_H
#define CHARIOT_H
//Begin section for file Chariot.h
//TODO: Add definitions that you want preserved
//End section for file Chariot.h

#include <QMap>

#include "ElementActif.h"
#include "Bagage.h"


class StrategiePilotage;
class Troncon; //Dependency Generated Source:Chariot Target:Troncon
class Tapis; //Dependency Generated Source:Chariot Target:Tapis

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
/**
 * Modèle de données du chariot.
 */
class Chariot : public ElementActif
{
    Q_OBJECT

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		/**
		 * @todo TODO Constructeur de chariot
		 */
        Chariot(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * @todo TODO Destructeur de chariot
         */
        virtual ~Chariot();
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /** Charge un bagage sur le chariot.
         * Déconnecte automatiquement le chariot du tapis.
         * Ne doit être appelé que si le chariot ne contient pas déjà un bagage.
         * Etant donné que le chariot se déconnecte du tapis dès qu'il reçoit un bagage,
         * on ne devrait jamais recevoir de deuxième bagage de toute façon.
         */
        void chargerBagage(Bagage* bagage);


        /** Décharge le bagage du chariot.
         * @return 0 si le chariot ne contient pas de bagage, un pointeur vers le bagage déchargé sinon.
         */
        Bagage* dechargerBagage();

        /**
         * Met à jour le chariot.
         * Selon la situation :
         *  - Avance sur le tronçon
         *  - Décharge le bagage
         *  - Change de tronçon
         *  - ...
         */
        virtual void maj();


        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_r3Lz8PD-Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /** Fait avancer le chariot vers la destination donnée.
         * Prend en compte la vitesse.
         * Ne vérifie pas si le chariot est à l'arrêt. TODO : changer, décrémentation de la vitesse
         * @param[in] destination Point vers lequel avancera le chariot
         */
        void avancer(QPointF destination);


    //Begin section for Chariot
    //TODO: Add attributes that you want preserved
    //End section for Chariot

    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pgh1sO55Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void dechargerBatterie();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_klhKcOybEd-q55IxPzNK8w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage * _bagage; /// Bagage transporté par le chariot.

        StrategiePilotage * _pilote; /// Pilote du chariot

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_alMHUO5DEd-dcpIgUje6-w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //Troncon * _tronconActuel;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1bIQYPDzEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //Tapis * _tapisAssocie;

};  //end class Chariot

#endif
