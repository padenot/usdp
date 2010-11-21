#ifndef STATEGIEPILOTAGE_H
#define STATEGIEPILOTAGE_H

#include <QObject>

class Chariot;
class Bagage;
class Troncon;
class Tapis;

class StrategiePilotage : public QObject
{
    public:
        StrategiePilotage(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        void piloter (Bagage* bagageTransporte);

    protected:

        /** Pilote le chariot lorsqu'il est à l'arrêt
         * (Ne fait donc a priori rien).
         */
        virtual void pilotageArret();

        /** Pilote le chariot lorsqu'il est en chemin vers un tapis ou un toboggan.
         */
        virtual void pilotageEnChemin();

        /** Pilote le chariot lorsqu'il atteint le noeud de fin du tronçon.
         * "bagage" doit être nul s'il n'y en a pas.
         * @param[in] bagage TODO
         */
        virtual void pilotageNoeudAtteint(Bagage* bagage) = 0;

        /** Pilote le chariot lorsqu'il atteint le toboggan objectif.
         */
        virtual void pilotageTobogganAtteint(Bagage* bagage);

        /** Pilote le chariot lorsqu'il atteint le tapis objectif.
         */
        virtual void pilotageTapisAtteint();

        enum Situation
        {
                ARRET,
                EN_CHEMIN,
                NOEUD_ATTEINT,
                TAPIS_ATTEINT,
                TOBOGGAN_ATTEINT
        };

        /** Retourne la situation actuelle du chariot.
         * Permet de déterminer les actions à effectuer lors d'une demande
         * de pilotage.
         */
        Situation situation(Bagage* bagage) const;

        Chariot& _chariot;
        /// Chariot piloté.

        Troncon * _tronconActuel;
        /// Troncon sur lequel se déplace actuellement le chariot.
        /// Ne doit jamais être nul.
        Tapis * _tapisAssocie;
        /// Tapis auquel le chariot devra revenir.
        /// Ne doit jamais être nul.

        static const qreal RAYON_PROXIMITE_NOEUD;
        /// Distance avec un noeud en dessous de laquelle le chariot est
        /// considéré comme étant sur le noeud.

        static const qreal RAYON_PROXIMITE_TAPIS;
        /// Distance avec un tapis en dessous de laquelle le chariot est
        /// considéré comme étant à portée du tapis.

        static const qreal RAYON_PROXIMITE_TOBOGGAN;
        /// Distance avec un toboggan en dessous de laquelle le chariot est
        /// considéré comme étant à portée du toboggan.

};

#endif // STATEGIEPILOTAGE_H
