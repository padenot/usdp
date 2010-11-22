/**
 * @file Tapis.cpp
 * @author Martin Richard (martin.richard@insa-lyon.fr)
 */

#include <QPointF>
#include <QVector2D>

#include "Tapis.h"
#include "Noeud.h"

#include "XmlConfigFactory.h"

//Begin section for file Tapis.cpp
//End section for file Tapis.cpp

const double Tapis::RAYON_PROXIMITE_TRONCON = 0.5;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Tapis::Tapis(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        ElementActif(indexParamValeur),
        _bagages(),
        _chariotConnecte(0),
        _tronconSupport(0)
{
    // Constructeur
}

void Tapis::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                  XmlConfigFactory& fabrique)
{
    ElementActif::init(indexParamValeur,fabrique);
    Element::init(indexParamValeur,fabrique);
    _tronconSupport = dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()));
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Tapis::~Tapis()
{
    // Destructeur
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_JpFKsO5zEd-X2qSx1xpmxg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::maj(double dt)
{
    // TODO : dérouler même si aucun chariot n'est connecté, en évitant de faire sortir le bagage ?
    //        Faisable avec deux rayons de proximité : un pour "bagage sur le bord" et l'autre pour
    //        "bagage sorti"


    // si un chariot est connecté au tapis
    if(_chariotConnecte != 0)
    {
        // Déroule le tapis (fait avancer les objets).
        deroulerTapis(dt);
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_wD2mgO5-Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool Tapis::ajouterBagage(Bagage* bagageEntrant)
{
    bagageEntrant->positionInitiale(*this);
    if(!_bagages.empty())
    {
        Bagage* dernierBagage = _bagages.last();
        // Vérifier la présence d'un bagage juste devant...
        if(QVector2D(dernierBagage->position()-bagageEntrant->position()).length() < Bagage::TAILLE)
            return false;
    }

    // Connexion du bagage
    _bagages.push_back(bagageEntrant);
    return true;
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_4ChQwPDwEd-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::deroulerTapis(double dt)
{
    QVector2D deplacement(_tronconSupport->position() - _position);
    deplacement.normalize();
    deplacement *= _vitesse*dt;

    // Pour chaque bagage sur le tapis
    for (QVector<Bagage*>::iterator it = _bagages.begin() ;
        it != _bagages.end() && _chariotConnecte != 0;
        ++it)
    {
        (*it)->simulerDeplacement(deplacement);

        // TODO : gérer le cas où deux bagages sont ajoutés en même temps
        //        Ils auront alors la même position et sortiront en même temps.
        //        Même avec la condition _chariotConnecte != 0 plus haut, on risque
        //        de faire avancer certains bagages plus que d'autres sur le tapis,
        //        et donc de leur donner une position différente sur le chariot.
        //        L'interdire ?
        if(bagageEstSorti(*it))
        {
            _chariotConnecte->chargerBagage(*it);
            _bagages.erase(it);
            deconnecter();
        }
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__9W_YPD7Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::connecter(Chariot* chariot)
{
    // On sait qu'il ne peut pas y avoir d'autre chariot puisque le
    // test est effectué niveau tronçon support
    _chariotConnecte = chariot;
}

void Tapis::deconnecter()
{
    _chariotConnecte = 0;
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__aB14PIZEd-TbK1o_cJlKw"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon* Tapis::trouverObjectifImmediat(Noeud* positionActuelle)
{
    return positionActuelle->trouverProchainTroncon(_tronconSupport);
}

bool Tapis::estSupport (const Troncon* troncon) const
{
    return _tronconSupport == troncon;
}

/**
 * Compare les coordonnées du bagage aux coordonnées du tronçon suivant.
 */
bool Tapis::bagageEstSorti(Bagage *bagage)
{
    return QVector2D(bagage->position() - _tronconSupport->position()).length()
            < RAYON_PROXIMITE_TRONCON;
}

QPointF Tapis::pointConnexion() const
{
    return _tronconSupport->position();
}
