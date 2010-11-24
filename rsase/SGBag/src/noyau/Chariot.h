#ifndef CHARIOT_H
#define CHARIOT_H

#include <QMap>

#include "ElementActif.h"
#include "Bagage.h"
#include "Direction.h"

class StrategiePilotage;
class Troncon;
class Tapis;

/**
 * \class Chariot
 * \brief Modèle de données du chariot. Contient aussi toutes les fonctions associées aux déplacement de celui-ci.
 */
class Chariot : public ElementActif
{
    Q_OBJECT

    public:
        static const double ACCELERATION_CHARIOT;
        static const double DECELERATION_CHARIOT;
        static const double VITESSE_NULLE;
        static const double MAX_DEPASSEMENT_VITESSEMAX;


        enum TypePilotage
        {
            AUTOMATIQUE,
            MANUEL
        };

        /**
         * \param indexParamValeur : 
         */
        Chariot(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        /**
         * @todo TODO Destructeur de chariot
         */
        virtual ~Chariot();

        /** Charge un bagage sur le chariot.
         * Déconnecte automatiquement le chariot du tapis.
         * Ne doit être appelé que si le chariot ne contient pas déjà un bagage.
         * Etant donné que le chariot se déconnecte du tapis dès qu'il reçoit un bagage,
         * on ne devrait jamais recevoir de deuxième bagage de toute façon.
	 * @param[int] bagage : Bagage à charger dans le chariot. 
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
         * @param[in] dt : Intervalle de temps écoulé depuis la dernière mise à jour, en unités de temps.
         */
        virtual void maj(double dt);

        // TODO
        // Émet le signal "activationModifiee" si c'est le cas.
        virtual void accelerer();

        /** Fait avancer le chariot vers la destination donnée.
         * Prend en compte la vitesse.
         * Ne vérifie pas si le chariot est à l'arrêt. TODO : changer, décrémentation de la vitesse
         * @param[in] destination Point vers lequel avancera le chariot
         */
        void avancer(double dt, QPointF destination);

	/**
	  * Accesseur sur le type de pilotage du chariot.
	  */
        TypePilotage typePilotage();

	/**
	  * Accesseur sur la direction conseillée du chariot.
	  */
        Direction directionConseillee();

	/**
	  * Accesseur sur la distance d'arrêt du chariot.
	  */
        double distanceArret();

        void connecter (Tapis* tapis);
        void deconnecter ();

    public slots :
        void modifierTypePilotage(TypePilotage type);
        void modifierDirectionConseillee(Direction direction);

    signals :
        void vitesseModifiee(double nouvelleVitesse);

    protected:
        void dechargerBatterie();

        Bagage * _bagage; /// Bagage transporté par le chariot.

        Tapis * _tapisConnecte;
        /// Tapis auquel le chariot est connecte.
        /// Doit être averti (deconnecter()) si le chariot
        /// part sans avoir reçu de bagage.

        Direction _directionConseillee;
        TypePilotage _typePilotage;
        StrategiePilotage * _pilote; /// Pilote du chariot

};  //end class Chariot

#endif
