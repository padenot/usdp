#include <limits>
#include<QVector2D>

#include "Noeud.h"

Noeud::Noeud(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _tronconsSuivants(),
        _visite(false)
{
    //TODO Auto-generated method stub
}

void Noeud::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    Troncon* suivantDroit = 0;
    Element::init(indexParamValeur,fabrique);
    _tronconsSuivants.push_back(dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::suivantGauche]].toInt())));

    suivantDroit = dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::suivantDroit]].toInt()));
    if (suivantDroit != 0)
    {
        _tronconsSuivants.push_back(suivantDroit);
    }
}

Noeud::~Noeud()
{
    //TODO Auto-generated method stub
}

Noeud::Chemin Noeud::trouverChemin(Troncon* destination)
{
    Chemin chemin;

    if(destination != 0)
    {
        chemin = calculChemin(destination).first;
#ifdef DEBUG_ACHEMINEMENT
        if (chemin.empty())
        {
            qDebug() << *this << "Aucun chemin !";
        }
        else
        {
            //qDebug() << *this << "Chemin :" << chemin;
        }
#endif
    }

    return chemin;
}

Noeud::Chemin Noeud::trouverChemin(Direction direction)
{
    Chemin chemin;

    if (_tronconsSuivants.size() == 1)
    {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << "dit : aucun choix possible, continuer";
#endif
        chemin.push(_tronconsSuivants.first());
    }
    else
    {
        if (direction == GAUCHE)
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << ": tu veux aller à gauche, va sur"
                    << *_tronconsSuivants[0];
#endif
            chemin.push(_tronconsSuivants[0]);
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << ": tu veux aller à droite, va sur"
                    << *_tronconsSuivants[1];
#endif
            chemin.push(_tronconsSuivants[1]);
        }
    }

    return chemin;
}


QPair<Noeud::Chemin, double> Noeud::calculChemin(Troncon* destination)
{
    QPair<Chemin, double> paireMin = qMakePair(Chemin(),
                                   std::numeric_limits<double>::infinity());

    if(!_visite)
    {
        _visite = true;

        foreach(Troncon* troncon, _tronconsSuivants)
        {
            if (troncon->etat() != Troncon::HORS_SERVICE)
            {
                if (troncon == destination)
                {
                    paireMin = qMakePair(Chemin(),0.0);
                    paireMin.first.push(troncon);
                    paireMin.second = 0.0;
                    break;
                }
                else
                {
                    QPair<Chemin, double> paireCandidate(troncon->noeudFin()->calculChemin(destination));
                    paireCandidate.second += QVector2D(troncon->noeudFin()->position()
                                                 - _position).length();

                    if(paireCandidate.second < paireMin.second)
                    {
                        paireMin = paireCandidate;
                        paireMin.first.push(troncon);
                    }
                }
            }
        }

        _visite = false;
    }

    return paireMin;
}

