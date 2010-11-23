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

class StrategiePilotage : public QObject
{
    Q_OBJECT

    public:
        StrategiePilotage(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        StrategiePilotage(const StrategiePilotage& modele);

        QPointF piloter (Bagage* bagageTransporte);

    protected slots :
        virtual void mettreAJourChemin();

    protected:
        virtual void calculerNouveauChemin() = 0;

        /** Tente de faire passer le chariot sur un autre troncon.
         * @param[in] nouveauTroncon Troncon sur lequel le chariot va passer. Si nul,
         *                           on considère que l'arrêt est nécessaire.
         */
        void changerTroncon(Troncon* nouveauTroncon);

        /** Anticipe le changement de tronçon du chariot sur un autre troncon.
         * @param[in] nouveauTroncon Troncon sur lequel le chariot va passer. Si nul,
         *                           on considère que l'arrêt est nécessaire.
         */
        void preparerChangementTroncon(Troncon* nouveauTroncon);

        /** Pilote le chariot lorsqu'il vient de recevoir un bagage.
         */
        virtual void pilotageBagageRecu(Bagage* bagageRecu);

        /** Pilote le chariot lorsqu'il atteint le noeud de fin du tronçon.
         * "bagage" doit être nul s'il n'y en a pas.
         * @param[in] bagage TODO
         * @param TODO
         */
        virtual void pilotageNoeudProche();

        /** Pilote le chariot lorsqu'il atteint le noeud de fin du tronçon.
         * "bagage" doit être nul s'il n'y en a pas.
         * @param[in] bagage TODO
         * @param TODO
         */
        virtual void pilotageNoeudAtteint();

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
         */
        Situation situation(Bagage* bagageTransporte) const;

        Chariot& _chariot;
        /// Chariot piloté.

        Bagage * _bagage;

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

#endif // STRATEGIEPILOTAGE_H
