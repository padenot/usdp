#ifndef ELEMENTACTIF_H
#define ELEMENTACTIF_H
//Begin section for file ElementActif.h
//TODO: Add definitions that you want preserved
//End section for file ElementActif.h

#include "Element.h"

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Pu31cPGuEd-1y9a3HOSRUA"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
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

        // TODO
        // Émet le signal "activationModifiee" si c'est le cas.
        virtual void freiner();

        // TODO
        // Émet le signal "activationModifiee" si c'est le cas.
        virtual void accelerer();

        virtual bool estActif();

        virtual double vitesse();
        virtual double vitesseMax ();

    public slots :
        virtual void definirActivation (bool estActif);
        virtual void modifierVitesseMax(double nouvelleVitesseMax);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_41riIO52Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"

        /** Met à jour l'élément actif (position, ...)
         * @param[in] dt Intervalle de temps écoulé depuis la dernière mise à jour, en unités de temps.
         */
        virtual void maj(double dt) = 0;

    signals :
        // N'envoie pas de signal pour notifier de l'activation / désactivation
        void activationModifiee(bool estActif);

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
