#ifndef STRATEGIEPILOTAGE_H
#define STRATEGIEPILOTAGE_H
#include <QObject>
#include <QPointF>
#include "Direction.h"
#include "Noeud.h"

class Chariot;
class Bagage;
class Troncon;
class Tapis;

/**
  * @class StrategiePilotage
  * @brief Régit les différentes stratégie de pilotage, prend les décision de marche ou d'arrêt des chariots.
  */
class StrategiePilotage : public QObject
{
    Q_OBJECT

    public:
        StrategiePilotage(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        StrategiePilotage(const StrategiePilotage& modele);

        /** Pilote le chariot.
         * Déclenche les accélérations/décélérations en fonction de la situation
         * actuelle du chariot
         * @param[in] dt Durée écoulée depuis le dernier appel de "piloter"
         * @return La direction que doit suivre le chariot
         */
        virtual QPointF piloter (double dt, Bagage* bagageTransporte);

    protected slots :
        virtual void mettreAJourChemin();

    protected:
        /** Calcule le nouveau chemin vers la destination du chariot.
         * Défini dans les classes filles (design pattern patron de méthode)
         */
        virtual void calculerNouveauChemin() = 0;

        /** Pilote le chariot lorsqu'il vient de recevoir un bagage.
         */
        virtual void pilotageBagageRecu(Bagage* bagageRecu);

        /** Pilote le chariot lorsqu'il atteint le noeud de fin du tronçon.
         */
        virtual void pilotageNoeudProche();

        /** Pilote le chariot lorsqu'il atteint le noeud de fin du tronçon.
         * @param[in] dt Durée écoulée depuis le dernier appel de "piloter"
         */
        virtual void pilotageNoeudAtteint(double dt);

        /** Pilote le chariot lorsqu'il est proche du toboggan objectif.
         */
        virtual void pilotageTobogganProche();

        /** Pilote le chariot lorsqu'il atteint le toboggan objectif.
         */
        virtual void pilotageTobogganAtteint();

        /** Pilote le chariot lorsqu'il est proche du tapis objectif.
         */
        virtual void pilotageTapisProche();

        /** Pilote le chariot lorsqu'il atteint le tapis objectif.
         */
        virtual void pilotageTapisAtteint();

        enum Situation
        {
                EN_CHEMIN,
                BAGAGE_RECU,
                NOEUD_PROCHE,
                NOEUD_ATTEINT,
                TAPIS_PROCHE,
                TAPIS_ATTEINT,
                TOBOGGAN_PROCHE,
                TOBOGGAN_ATTEINT
        };

        /** Retourne la situation actuelle du chariot.
         * Permet de déterminer les actions à effectuer lors d'une demande
         * de pilotage.
         * @param[in] bagageTransporte Bagage transporté par le chariot.
         *                             Nul s'il n'y en a pas.
         */
        Situation situation(Bagage* bagageTransporte) const;

        Chariot& _chariot;
        /// Chariot piloté.

        Bagage * _bagage;
        /// Bagage transporté

        Troncon * _tronconActuel;
        /// Troncon sur lequel se déplace actuellement le chariot.
        /// Ne doit jamais être nul.
        Troncon * _tronconReserveSuivant;
        /// Prochain tronçon sur lequel ira le chariot,
        /// déjà réservé.

        Noeud::Chemin _chemin;

        Tapis * _tapisAssocie;
        /// Tapis auquel le chariot devra revenir.
        /// Ne doit jamais être nul.

        double _tempsDepuisDerniereTentativeDeblocage;
        /// Utilisé pour essayer périodiquement de se débloquer

        static const double RAYON_ACTION_NOEUD;
        /// Distance avec un noeud en dessous de laquelle le chariot est
        /// considéré comme étant sur le noeud.

        static const double RAYON_ACTION_TAPIS;
        /// Distance avec un tapis en dessous de laquelle le chariot est
        /// considéré comme étant à portée du tapis.

        static const double RAYON_ACTION_TOBOGGAN;
        /// Distance avec un toboggan en dessous de laquelle le chariot est
        /// considéré comme étant à portée du toboggan.

        static const double INTERVALE_TENTATIVE_DEBLOCAGE;
        /// Intervalle durant lequel un chariot attend avant de tenter
        /// de recalculer un chemin vers sa destination, s'il est bloqué
};

#endif // STRATEGIEPILOTAGE_H
