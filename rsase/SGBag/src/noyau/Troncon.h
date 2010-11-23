#ifndef TRONCON_H
#define TRONCON_H
//Begin section for file Troncon.h
//TODO: Add definitions that you want preserved
//End section for file Troncon.h

#include <QMap>

#include "Element.h"
#include "XmlConfigFactory.h"


class Noeud;
class Chariot; //Dependency Generated Source:Troncon Target:Chariot

/**
  * @class Troncon
  * @brief Classe conteneur regroupant les différentes propriétés d'un tronçon
  */
class Troncon : public Element
{
    Q_OBJECT

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Troncon(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__FeJQOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Troncon();

	/** @param[in] chariotCandidat : Chariot voulant occuper le tronçon
	* @return Vrai si un chariot peut devenir "propriétaire du troncon", faux sinon (e.g. si le tronçon ets hors service ou déjà occupé).	
	*/
        bool occuper(Chariot* chariotCandidat);

	/** Libère le tronçon du chariot propriétaire de celui-ci. */
        void liberer();

	/** Met le troçon hors service, i.e. que plus aucun chariot ne pourra circuler sur celui-ci.
	   */
        bool mettreHorsService();
	
	/** Remet le troçon en service, i.e. que les chariots pourront à nouveau circuler sur celui-ci.
	   */
        void reparer();

	/** Accesseur sur le noeud de fin du tronçon */
        Noeud* noeudFin();

	/** Accessur sur le noeud de début du tronçon */
        Noeud* noeudDebut();

        /** Décrit l'état du tronçons, i.e. En service : libre, occupé, ou Hors-service. */
	enum EtatTroncon
        {
            LIBRE,
            OCCUPE,
            HORS_SERVICE
        };

	/** Accesseur sur l'état du tronçon. */
        EtatTroncon etat();

protected:
    Chariot* _chariotProprietaire;
    /// Chariot occupant actuellement le tronçon

    //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_5u8RMOtcEd-6Qct7MaUvyw"
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    Noeud * _noeudDebut;

    //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_0QxHMOsuEd-oy8D834IawQ"
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    Noeud * _noeudFin;

    //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_bOJUIPG5Ed-XFOLnxrkHLA"
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    //unsigned long longueur;

    bool _estHorsService;
};  //end class Troncon

#endif
