/**
 * @file Tapis.cpp
 * @author Martin Richard (martin.richard@insa-lyon.fr)
 */

#include <QPointF>

#include "Tapis.h"
#include "Noeud.h"
//Begin section for file Tapis.cpp
using namespace std;
//End section for file Tapis.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Tapis::Tapis(const QMap<QString,QString>& mapParam)
    :ElementActif(mapParam), _chariotConnecte(0), _longueur(5)
{
    // Constructeur
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Tapis::~Tapis()
{
    // Destructeur
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_JpFKsO5zEd-X2qSx1xpmxg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::maj()
{
    // si un chariot est connecté au tapis
    if(_chariotConnecte != 0)
    {
        // Déroule le tapis (fait avancer les objets).
        deroulerTapis();
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_wD2mgO5-Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::ajouterBagage(Bagage* bagageEntrant)
{
    // Connexion du bagage
    _bagage.push_back(bagageEntrant);
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_4ChQwPDwEd-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::deroulerTapis()
{
    // Pour chaque bagage sur le tapis
    Bagage* b;
    for(unsigned int i = 0; i < _bagage.size(); ++i)
    {
        b = _bagage[i];

        // TODO faut vérifier, le modèle est pas clair, je calcule la direction en prenant
        // _position pour point de départ et la position du "noeudFin" comme point final.
        QPointF posFin = _tronconSupport->noeudFin()->position();
        b->simulerDeplacement(
                (posFin.x() - _position.x())*_vitesse,
                (posFin.y() - _position.y())*_vitesse
        );

        if(bagageEstSorti(b))
            _chariotConnecte->chargerBagage(b);
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

bool Tapis::estObjectifFinal (const Troncon* troncon)
{
    return _tronconSupport == troncon;
}

/**
 * Compare les coordonnées du bagage aux coordonnées du tronçon suivant.
 */
bool Tapis::bagageEstSorti(Bagage *bagage)
{
    // On teste si la position du bagage est comprise entre la position du tapis et la position
    // du noeud suivant.

    qreal posGauche, posDroite;
    QPointF posFin = _tronconSupport->noeudFin()->position();
    QPointF posBagage = bagage->position();

    if(posFin.x() > _position.x())
    {
        posGauche = _position.x();
        posDroite = posFin.x();
    }
    else
    {
        posGauche = posFin.x();
        posDroite = _position.x();
    }

    if(posBagage.x() <= posGauche && posBagage.x() >= posDroite)
        return true;

    if(posFin.y() > _position.y())
    {
        posGauche = _position.y();
        posDroite = posFin.y();
    }
    else
    {
        posGauche = posFin.y();
        posDroite = _position.y();
    }

    if(posBagage.y() <= posGauche && posBagage.y() >= posDroite)
        return true;

    return false;
}
