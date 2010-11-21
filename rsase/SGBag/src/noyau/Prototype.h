#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <QMap>
#include <QVector>
#include <QTimer>
#include <QObject>
#include "Tapis.h"
#include "Vol.h"
#include "modelvols.h"

//Begin section for file Prototype.h
//TODO: Add definitions that you want preserved
//End section for file Prototype.h


class Element; //Dependency Generated Source:Prototype Target:Element

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"

/**
 * Prototype de la simulation : classe d'entrée de la simulation.
 */
class Prototype : public QObject
{
    Q_OBJECT

    public:

        /**
         * Pour les fonctionnalités qui peuvent avoir un comportement
         * automatique ou manuel, cette enumération permet d'en connaitre
         * l'état.
         */
        enum ModeSimulation
        {
            MANUEL,
            AUTOMATIQUE
        };


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


    public slots:
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_oCLrkO59Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * @brief Passage en mode manuel.
         * @param mode Nouveau mode.
         * Si mode est égal au mode actuel, cet apppel n'effectue rien.
         */
        void changementMode(ModeSimulation mode);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_0yUWMO59Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * @brief Ajout d'un bagage dans la simulation.
         * Le bagage est crée, et est placé sur le tapis.
         * @param tapis Le tapis d'origine du bagage : là où il apparaitra.
         * @param vol Le vol de destination du bagage : là où il sortira.
         */
        void ajouterBagage(Tapis* tapis, Vol* vol);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Eq-X8PCiEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * @brief Changer de mode pour l'ajout de bagages
         * Les bagages peuvent être générés par le prototype, ou alors
         * ajoutés manuellement. Cette méthode permet de changer le
         * comportement du système.
         * @param mode Le nouveau mode de fonctionnement d'arrivée des bagages.
         */
        void changementModeAjoutBagage(ModeSimulation mode);

        /**
         * @brief Ajoute des bagages de manières aléatoire.
         */
        void ajouterBagageAleatoire();


        /**
         * @brief Commencer la simulation
         */
        void commencerSimulation();
        /**
         * @brief Arreter la simulation
         */
        void arreterSimulation();
        /**
         * @brief Changer la vitesse de la simulation, sans arrêter la
         *        simulation.
         * @param pourcentage Pourcentage de la vitesse maximale.
         *                    Si hors bornes (<0 ou >100), il est ramené à
         *                    la borne la plus proche.
         */
        void changerVitesse(int pourcentage);

        /**
         * @brief Récupérer l'intervalle de temps dt entre deux états simulés.
         */
        const int acqVitesse();

        /**
         * @brief Récupérer la liste des éléments présents.
         */
        const XmlConfigFactory::IndexTypesElements &elements();
        /**
         * Donner le model aux vues.
         */
        ModelVols* modelVols();
        void ajouterVol(Vol* vol);

    protected slots:
        /**
         * Met à jour le modèle.
         */
        void maj();

        void retirerVol(int i);

    protected:
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pf5ngOygEd-0NvPstdZN1w"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /**
         * Map des types sur les vecteurs d'éléments
         */
        XmlConfigFactory::IndexTypesElements _elementsParType;

        /**
         * Tous les vols présents dans la simulation sont dans ce vector.
         */
        ModelVols _modelVols;
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_qtglIPG5Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //int _vitesseSimulation;

        /**
         * Cette horloge règle la vitesse de la simulation, il envoie un évènement à chaque tick.
         */
        QTimer _horloge;
        /**
         * Mode de la génération de bagage : automatique ou manuel.
         */
        ModeSimulation _mode_generation_bagage;

        /**
         * ID des bagages générés. Commence à 1000 et est incrémenté pour chaque bagage.
         */
        int _id_bagage_genere;

        /**
         * Intervalle de temps donné au modèle à chaque tick d'horloge
         * lors de la simulation.
         */
        qreal _dt;

        static const int INTERVALLE_RAFRAICHISSEMENT_MODELE;
        static const qreal INTERVALLE_SIMULATION_DEFAUT;
        static const qreal INTERVALLE_SIMULATION_MAX;
        static const qreal INTERVALLE_SIMULATION_MIN;

        static const int ID_BAGAGE_GENERE_INITIAL;
};  //end class Prototype

#endif
