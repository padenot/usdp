#ifndef STATEGIEPILOTAGE_H
#define STATEGIEPILOTAGE_H

#include <QtGlobal>
#include <QPointF>
#include "Direction.h"

class Chariot;
class Bagage;
class Troncon;
class Tapis;

class StrategiePilotage
{
    public:
        StrategiePilotage(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        StrategiePilotage(const StrategiePilotage& modele);

        QPointF piloter (Direction directionConseillee, Bagage* bagageTransporte);

    protected:
        /** Tente de faire passer le chariot sur un autre troncon.
         * @param[in] nouveauTroncon Troncon sur lequel le chariot va passer. Si nul,
         *                           rien ne se passera.
         * @return Vrai si le passage a pu se faire, faux sinon.
         */
        bool changerTroncon(Troncon* nouveauTroncon);

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
        virtual void pilotageNoeudAtteint(
                Direction directionConseillee, Bagage* bagage) = 0;

        /** Pilote le chariot lorsqu'il est proche du toboggan objectif.
         */
        virtual void pilotageTobogganProche(Bagage* bagage);

        /** Pilote le chariot lorsqu'il atteint le toboggan objectif.
         */
        virtual void pilotageTobogganAtteint(Bagage* bagage);

        /** Pilote le chariot lorsqu'il est proche du tapis objectif.
         */
        virtual void pilotageTapisProche();

        /** Pilote le chariot lorsqu'il atteint le tapis objectif.
         */
        virtual void pilotageTapisAtteint();

        enum Situation
        {
                //ARRET,
                EN_CHEMIN,
                NOEUD_ATTEINT,
                TAPIS_PROCHE,
                TAPIS_ATTEINT,
                TOBOGGAN_PROCHE,
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

        static const double RAYON_PROXIMITE_TAPIS;
        /// Distance avec un tapis en dessous de laquelle le chariot est
        /// considéré comme étant proche du tapis (début du ralentissement).

        static const double RAYON_PROXIMITE_TOBOGGAN;
        /// Distance avec un toboggan en dessous de laquelle le chariot est
        /// considéré comme étant proche du toboggan (début du ralentissement).


        static const double RAYON_ACTION_NOEUD;
        /// Distance avec un noeud en dessous de laquelle le chariot est
        /// considéré comme étant sur le noeud.

        static const double RAYON_ACTION_TAPIS;
        /// Distance avec un tapis en dessous de laquelle le chariot est
        /// considéré comme étant à portée du tapis.

        static const double RAYON_ACTION_TOBOGGAN;
        /// Distance avec un toboggan en dessous de laquelle le chariot est
        /// considéré comme étant à portée du toboggan.


};

#endif // STATEGIEPILOTAGE_H
