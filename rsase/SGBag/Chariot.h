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
/**
 * Modèle de données du chariot.
 */
class Chariot : public ElementActif
{
    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		/**
		 * @todo TODO Constructeur de chariot
		 */
        Chariot();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		/**
		 * @todo TODO Destructeur de chariot
		 */
        virtual ~Chariot();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_XNzMkO52Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		/** Charge un bagage sur le chariot.
		 * Ne doit être appelé que si le chariot ne contient pas déjà un chariot.
		 * Etant donné que le chariot se déconnecte du tapis dès qu'il reçoit un bagage,
		 * on ne devrait jamais recevoir de deuxième bagage de toute façon.
		 */
        void chargerBagage(Bagage* bagage);

		/**
		 * Arrête le chariot (arrêt instantané).
		 * @todo Rendre l'arrêt progressif
		 */
        virtual void arreter();

		/**
		 * Démarre le chariot (démarrage instantané).
		 * @todo Rendre l'arrêt progressif
		 */
        virtual void demarrer();

		/**
		 * Met à jour le chariot.
		 * Selon la situation :
		 *  - Avance sur le tronçon
		 *  - Décharge le bagage
		 *  - Change de tronçon
		 *  - ...
		 */
        virtual void maj();


    //Begin section for Chariot
    //TODO: Add attributes that you want preserved
    //End section for Chariot

    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pgh1sO55Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void dechargerBatterie();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_r3Lz8PD-Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		/** Fait avancer le chariot vers le bout du tronçon.
		 * Prend en compte la vitesse.
		 * Ne vérifie pas si le chariot est à l'arrêt.
		 */
        void avancer();

    private:

		enum Etat
		{
			ARRET,
			RETOUR_TAPIS,
			LIVRAISON_BAGAGE,
			APPROCHE_DESTINATION,
			TAPIS_ATTEINT,
			TOBOGGAN_ATTEINT
		};

		/** Retourne l'état actuel du chariot.
		 * Utile pour déterminer les actions à effectuer lors d'une mise à jour.
		 * (Un chariot est une machine à états)
		 */
		Etat etat();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_klhKcOybEd-q55IxPzNK8w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage * _bagage; /// Bagage transporté par le chariot.

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_alMHUO5DEd-dcpIgUje6-w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon * _troncon; /// Troncon sur lequel se déplace actuellement le chariot.

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_1bIQYPDzEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Tapis * _tapisAssocie; /// Tapis auquel le chariot devra revenir.



};  //end class Chariot

#endif
