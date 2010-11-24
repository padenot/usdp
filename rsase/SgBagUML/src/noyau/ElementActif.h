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
        ElementActif(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        virtual ~ElementActif();

		/**
		  * @brief Ordonne à l'élément dynamique de décélérer autant que possible
		  * en respectant les contraintes physiques liées au mobile (décélération
		  * maximale)
		  * Émet le signal "activationModifiee" si l'élément n'était pas déjà
		  * en train de décélérer.
		  */
        virtual void freiner();

		/**
		  * @brief Ordonne à l'élément dynamique d'accélérer autant que possible
		  * en respectant les contraintes physiques liées au mobile (accélération
		  * maximale)
		  * Émet le signal "activationModifiee" si l'élément n'était pas déjà
		  * en train d'accélérer.
		  */
        virtual void accelerer();

	/**
	  * @brief Accesseur sur l'état ( en mouvement ou pas) de l'élément dynamique
	  */
        virtual bool estActif ();

	/**
	  * @brief Accesseur sur la vitesse de l'élément dynamique
	  */
        virtual double vitesse();

	/**
	  * @brief Accesseur sur la vitesse maximale de l'élément dynamique
	  */
        virtual double vitesseMax ();

    public slots :
        virtual void definirActivation (bool estActif);
        virtual void modifierVitesseMax(double nouvelleVitesseMax);

        /** Met à jour l'élément actif (position, ...)
         * @param[in] dt Intervalle de temps écoulé depuis la dernière mise à jour, en unités de temps.
         */
        virtual void maj(double dt) = 0;

        // N'envoie pas de signal pour notifier de l'activation / désactivation
        void activationModifiee(bool estActif);

    protected:

        double _vitesse;
        double _vitesseMax;

        static const double VITESSE_DEFAUT;
        static const double VITESSE_MAX_DEFAUT;

        bool _estActif;

};  //end class ElementActif

#endif
