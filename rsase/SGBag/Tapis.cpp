/**
 * @file Tapis.cpp
 * @author Martin Richard (martin.richard@insa-lyon.fr)
 */

#include "Tapis.h"
#include <QVector2D>
//Begin section for file Tapis.cpp
using namespace std;
//End section for file Tapis.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_9b-b4OsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Tapis::Tapis(const QMap<QString,QString>& mapParam)
    :ElementActif(mapParam), chariotConnecte(NULL)
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
    if(chariotConnecte != NULL)
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
    bagage.push_back(bagageEntrant);
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_4ChQwPDwEd-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::deroulerTapis()
{
    // Pour chaque bagage sur le tapis
    Bagage* b;
    QPointF positionActuelle = _position;
    QVector2D vector;
    for(unsigned int i = 0; i < bagage.size(); ++i)
    {
        b = this->bagage[i];
        b->simulerDeplacement(positionActuelle.x()*_vitesse, positionActuelle.y()*_vitesse);

        if(bagageEstSorti(b))
            chariotConnecte->chargerBagage(b);
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__9W_YPD7Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Tapis::connecter(Chariot* chariot)
{
    // On sait qu'il ne peut pas y avoir d'autre chariot puisque le
    // test est effectué niveau tronçon support
    chariotConnecte = chariot;
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#__aB14PIZEd-TbK1o_cJlKw"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon* Tapis::trouverObjectifImmediat()
{
    // TODO WTFDID?
    return 0;
}

/**
 * Compare les coordonnées du bagage aux coordonnées du tronçon suivant.
 */
bool Tapis::bagageEstSorti(Bagage *bagage)
{
    // TODO
    return false;
}
