#ifndef TRONCON_H
#define TRONCON_H

#include <QMap>

#include "Element.h"
#include "XmlConfigFactory.h"


class Noeud;
class Chariot;

class Troncon : public Element
{
    Q_OBJECT

    public:

        Troncon(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        virtual ~Troncon();

	/** @param[in] chariotCandidat : Chariot voulant occuper le tronçon
	* @return Vrai si le chariot est devenu "propriétaire du troncon",
	* faux sinon (e.g. si le tronçon ets hors service ou déjà occupé).
	*/
        bool occuper(Chariot* chariotCandidat);

	/** Libère le tronçon du chariot propriétaire de celui-ci. */
        void liberer();

	/** Met le troçon hors service, i.e. fait en sorte que plus aucun chariot
	 * ne puisse occuper celui-ci.
	 * Ne fonctionne que si le tronçon n'est pas déjà occupé.
	 * @return Vrai si la mise hors service a fonctionné, faux sinon.
	   */
        bool mettreHorsService();
	/** Remet le troçon en service, i.e. fait en sorte que les chariots
	 * puissent à nouveau circuler sur celui-ci.
	   */
        void reparer();

	/** Accesseur sur le noeud de début du tronçon */
        Noeud* noeudDebut();

	/** Accesseur sur le noeud de fin du tronçon */
        Noeud* noeudFin();

        /** Décrit l'état du tronçons, i.e. En service : libre, occupé, ou Hors-service. */
        enum EtatTroncon
        {
            LIBRE,
            OCCUPE,
            HORS_SERVICE
        };

	/** Accesseur sur l'état du tronçon. */
        EtatTroncon etat();

    signals :
        /**
         * Envoyé lorsque le tronçon est mis hors service ou réparé
         */
        void etatModifie ();

    protected:
        Chariot* _chariotProprietaire;
        /// Chariot occupant actuellement le tronçon

        Noeud * _noeudDebut;

        Noeud * _noeudFin;

    bool _estHorsService;
};  //end class Troncon

#endif

