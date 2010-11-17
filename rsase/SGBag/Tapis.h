/**
 * @file Tapis.h
 * @author Martin Richard (martin.richard@insa-lyon.fr)
 */

#ifndef TAPIS_H
#define TAPIS_H
//Begin section for file Tapis.h
//TODO: Add definitions that you want preserved
#include <vector>
//End section for file Tapis.h

#include "ElementActif.h"
#include "Bagage.h"
#include "Chariot.h"


class Troncon; //Dependency Generated Source:Tapis Target:Troncon

/**
 * Un tapis est un point d'entrée de bagages dans le circuit SGBag.
 *
 */
//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Tapis : ElementActif
{

    //Begin section for Tapis
    //TODO: Add attributes that you want preserved
    //End section for Tapis

    private:
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_tziQ8eshEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        std::vector<Bagage*> bagage;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_fSJGQeswEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Chariot * chariotConnecte;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_TYtfcfDpEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon * tronconSupport;

    protected:

        /**
         * Met le tapis en action (déplace les bagages).
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_4ChQwPDwEd-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void deroulerTapis();

        /**
         * Teste si le bagage bagage est sorti du tapis.
         * @param[in] bagage Bagage à tester
         */
        bool bagageEstSorti(Bagage* bagage);

    public:

        /**
         * Constructeur de tapis.
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Tapis();

        /**
         * Destructeur de tapis.
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Tapis();

        /**
         * Opération de mise à jour en cascade de l'objet.
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_JpFKsO5zEd-X2qSx1xpmxg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void maj();

        /**
         * Ajoute le bagage bagageEntrant sur le tapis.
         * @param[in] bagageEntrant
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_wD2mgO5-Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void ajouterBagage(Bagage* bagageEntrant);

        /**
         * Connecte un chariot au tapis.
         * @param[in,out] chariot Chariot arrivant et attendant un bagage.
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__9W_YPD7Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void connecter(Chariot* chariot);

        /**
         * @todo commenter la méthode
         */
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__aB14PIZEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon* trouverObjectifImmediat();

        /**
         * Modifie la vitesse.
         */
        void modifierVitesse();

};  //end class Tapis

#endif
