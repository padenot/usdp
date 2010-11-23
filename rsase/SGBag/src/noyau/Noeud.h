#ifndef NOEUD_H
#define NOEUD_H
/**
  * \file Noeud.h
  * \author Adenot Paul, Brodu Etienne, GOlumbeanu Monica, Richar Martin, Rodière Yoann
  */

#include <QMap>
#include <QVector>
#include <QPair>

#include "Element.h"
#include "Troncon.h"
#include "Direction.h"

/**
  * \class Noeud
  * \brief Classe gérant un noeud du graphe de tapis, c'est à dire l'intersection entre deux tronçons.
  */
class Noeud : public Element
{
    Q_OBJECT

    public:
        Noeud(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** 
	  * \brief Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        virtual ~Noeud();

        /** 
	 * \brief Tente de trouver le troncon offrant le plus court chemin vers la destination en partant de ce noeud.
         * \param destination: Le troncon à atteindre en une distance mdinimale. Si le pointeur est nul, le troncon
         *                     est considéré comme inaccessible.
         * \return Le troncon optimal, ou 0 si aucun troncon n'est accessible.
         */
        Troncon* trouverProchainTroncon(Troncon* destination);

	/**
	  * \brief : Cette fonction est une fonction intermédaire au calcul du plus court chemin.
	  * Elle permet de trouver la distance avec un tronçon passé en paramètre.
	  * \param destination : C'est le tronçons de destination. C'est à dire le tronçons sur lequel va se baser le calcul de distance.
	  * \return : Une paire <Noeud, distance> indiquant le tronçons passé en paramètre ainsi que la distance par rapport au tronçon courrant.
	  */
        QPair<Troncon*, double> calculChemin(Troncon* destination);

	/**
	  * \param direction : Direction dans laquelle la recherche du noeud doit s'effectuer.
	  * \return Renvoie une paire <Tronçon, distance> représentant le noeud le plus proche menant dans le direction passée en paramètre.
        */
	Troncon* trouverProchainTroncon(Direction direction);

    private:
        QVector<Troncon *> _tronconsSuivants;
        bool _visite;

};  //end class Noeud

#endif
