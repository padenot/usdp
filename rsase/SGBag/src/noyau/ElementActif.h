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
        virtual void arreter();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_tl7KgPD6Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual void demarrer();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_M4WU0PIdEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //virtual void modifierVitesse(qreal nouvelleVitesse);

        virtual bool estActif ();

    public slots :
        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_41riIO52Ed-Jn7v3SB1Zsg"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual void maj() = 0;


    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_je1NYPG4Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        qreal _vitesse;

        static const qreal VITESSE_DEFAUT;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_UiLRIPIWEd-TbK1o_cJlKw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        bool _estActif;

};  //end class ElementActif

#endif
