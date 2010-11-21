#include <limits>
#include<QVector2D>

#include "Noeud.h"
//Begin section for file Noeud.cpp
//TODO: Add definitions that you want preserved
//End section for file Noeud.cpp

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
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

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Noeud::~Noeud()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_bT8WAPD8Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon* Noeud::trouverProchainTroncon(Troncon* destination)
{
    if(destination == 0)
    {
        return 0;
    }
    else if (_tronconsSuivants.size()==1)
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << *this << "dit : aucun choix possible, continuer";
#endif
        return _tronconsSuivants.first();
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        Troncon* resultat = calculChemin(destination).first;
        qDebug() << *this << "dit : il faut aller a"
                << (resultat == _tronconsSuivants.first() ? "gauche" : "droite")
                << ", sur" << *resultat;
        return resultat;
#else
        return calculChemin(destination).first;
#endif

    }
}

Troncon* Noeud::trouverProchainTroncon(Direction direction)
{
    if (_tronconsSuivants.size() == 1)
    {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << "dit : aucun choix possible, continuer";
#endif
        return _tronconsSuivants.first();
    }
    else
    {
        if (direction == GAUCHE)
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << "dit : tu veux aller à gauche, va sur"
                    << *_tronconsSuivants[0];
#endif
            return _tronconsSuivants[0];
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << "dit : tu veux aller à droite, va sur"
                    << *_tronconsSuivants[1];
#endif
            return _tronconsSuivants[1];
        }
    }
}


QPair<Troncon*, double> Noeud::calculChemin(Troncon* destination)
{
    // TODO : implémenter un algorithme plus efficace
    // TODO : calculer tout le chemin plutôt que déterminer seulement le prochain tronçon
    //        (tenir une liste des tronçons à emprunter)
    // TODO : Proposition à discuter (pas forcément idéal) :
    //        Lorsqu'un tronçon est inaccessible (à cause de tronçons hors service), continuer
    //        à avancer jusqu'à être VRAIMENT bloqué, pour libérer les voies. Actuellement on
    //        s'arrête dès qu'on détecte que le chemin est bloqué.

    if(_visite)
    {
        return qMakePair(reinterpret_cast<Troncon*>(0),
                         std::numeric_limits<double>::infinity());
    }
    else
    {
        double tailleCheminMin = std::numeric_limits<double>::infinity();
        Troncon* tronconMin = 0;

        _visite = true;

        foreach(Troncon* troncon, _tronconsSuivants)
        {
            if (troncon->etat() != Troncon::HORS_SERVICE)
            {
                if (troncon == destination)
                {
                    tronconMin = troncon;
                    tailleCheminMin = 0;
                    break;
                }
                else
                {
                    QPair<Troncon*, double> paireRetour = troncon->noeudFin()->calculChemin(destination);
                    double tailleChemin = paireRetour.second + QVector2D(troncon->noeudFin()->position()
                                                                       - _position).length();

                    if(tailleChemin < tailleCheminMin)
                    {
                        tronconMin = troncon;
                        tailleCheminMin = tailleChemin;
                    }
                }
            }
        }

        _visite = false;

        return qMakePair(tronconMin,tailleCheminMin);
    }

}

