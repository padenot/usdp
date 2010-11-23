#ifndef ELEMENTACTIF_H
#define ELEMENTACTIF_H
//Begin section for file ElementActif.h
//TODO: Add definitions that you want preserved
//End section for file ElementActif.h

#include "Element.h"

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
/**
  * @class ElementActif
  * @brief Classe mère de tous les éléments dynamiques ( Chariot et Tapis)
  */
class ElementActif : public Element
{
    Q_OBJECT

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        ElementActif(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~ElementActif();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_v0pDgO_3Ed-KganxdgdPew"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	/**
	  * @brief Ordonne à l'élément dynamique de s'arrêter le plus vite possible en respectant les contraintes physiques liées au mobile (décélération maximale)
	  */
        virtual void arreter();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_tl7KgPD6Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	/**
	  * @brief Ordonne à l'élément dynamique de s'arrêter le plus vite possible en respectant les contraintes physiques liées au mobile (décélération maximale)
	/**
	  * @brief Ordonne à l'élément dynamique de démarrer le plus vite possible en respectant les contraintes physiques liées au mobile (accélération maximale)
	  */
        virtual void demarrer();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_M4WU0PIdEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //virtual void modifierVitesse(double nouvelleVitesse);

	/**
	  * @brief Accessur sur l'état ( en mouvement ou pas) de l'élément dynamique
	  */
        virtual bool estActif ();

	/**
	  * @brief Accessur la vitesse de l'élément dynamique
	  */
        virtual double vitesse();

	/**
	  * @brief Accessur la vitesse maximale de l'élément dynamique
	  */
        virtual double vitesseMax ();

    public slots :
        virtual void modifierVitesseMax(double nouvelleVitesseMax);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_41riIO52Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"

        /** Met à jour l'élément actif (position, ...)
         * @param[in] dt Intervalle de temps écoulé depuis la dernière mise à jour, en unités de temps.
         */
        virtual void maj(double dt) = 0;

    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_je1NYPG4Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        double _vitesse;
        double _vitesseMax;

        static const double VITESSE_DEFAUT;
        static const double VITESSE_MAX_DEFAUT;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_UiLRIPIWEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        bool _estActif;

};  //end class ElementActif

#endif
