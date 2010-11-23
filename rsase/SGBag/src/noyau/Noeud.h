#ifndef NOEUD_H
#define NOEUD_H
//Begin section for file Noeud.h
//TODO: Add definitions that you want preserved
//End section for file Noeud.h

#include <QMap>
#include <QVector>
#include <QPair>
#include <QStack>

#include "Element.h"
#include "Troncon.h"
#include "Direction.h"

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Noeud : public Element
{
    Q_OBJECT

    public:
        typedef QStack<Troncon*> Chemin;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Noeud(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Noeud();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_bT8WAPD8Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        /** Tente de trouver le troncon offrant le plus court chemin vers la destination en partant de ce noeud.
          TODO
         * @param[in] destination Le troncon à atteindre en une distance minimale.
         *                        Si le pointeur est nul, le troncon
         *                        est considéré comme inaccessible.
         */
        Chemin trouverChemin(Troncon* destination);

        QPair<Chemin, double> calculChemin(Troncon* destination);

        Chemin trouverChemin(Direction direction);

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_5utnsOtcEd-6Qct7MaUvyw"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        QVector<Troncon *> _tronconsSuivants;

        bool _visite;

};  //end class Noeud

#endif
