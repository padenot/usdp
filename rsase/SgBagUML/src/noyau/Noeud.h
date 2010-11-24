#ifndef NOEUD_H
#define NOEUD_H
/**
  * \file Noeud.h
  * \author Adenot Paul, Brodu Etienne, GOlumbeanu Monica, Richar Martin, Rodière Yoann
  */

#include <QMap>
#include <QVector>
#include <QPair>
#include <QStack>

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
        typedef QStack<Troncon*> Chemin;

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
         * \return Le chemin optimal, éventuellement vide si la destination
		 * n'est pas accessible.
         */
        Chemin trouverChemin(Troncon* destination);

	/**
	  * \brief Cette fonction est une fonction intermédaire au calcul du plus court chemin.
	  * Elle permet de trouver la distance avec un tronçon passé en paramètre.
	  * \param destination Le tronçons de destination. C'est à dire le
	  * tronçon sur lequel va se baser le calcul de distance.
	  * \return Une paire <Chemin, distance> contenant le plus court chemin
	  * calculé ainsi que sa longueur.
	  */
        QPair<Chemin, double> calculChemin(Troncon* destination);

	/**
	  * \param direction : Direction dans laquelle la recherche du noeud doit s'effectuer.
	  * \return Un chemin contenant uniquement le tronçon dans la direction indiquée
	  * juste après le noeud.
	  */
        Chemin trouverChemin(Direction direction);

    private:
        QVector<Troncon *> _tronconsSuivants;
        bool _visite;

};  //end class Noeud

#endif
