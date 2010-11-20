#include <QVector2D>

#include "Chariot.h"
#include "Noeud.h"
#include "Tapis.h"
#include "Toboggan.h"
#include "XmlConfigFactory.h"


//Begin section for file Chariot.cpp
//TODO: Add definitions that you want preserved
//End section for file Chariot.cpp

const qreal Chariot::RAYON_PROXIMITE_NOEUD = 0.1;
const qreal Chariot::RAYON_PROXIMITE_TAPIS = 0.1;
const qreal Chariot::RAYON_PROXIMITE_TOBOGGAN = 0.1;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::Chariot(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
    ElementActif(indexParamValeur),
    _bagage (0),
    _tronconActuel (0),
    _tapisAssocie (0)
{
}

void Chariot::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    ElementActif::init(indexParamValeur,fabrique);
    _tronconActuel = dynamic_cast<Troncon*>(fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()
            ));
    _position = _tronconActuel->position();
    _tapisAssocie = dynamic_cast<Tapis*>(fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapisAssocie]].toInt()
            ));
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::~Chariot()
{
    delete _bagage;
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_XNzMkO52Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::chargerBagage(Bagage* bagage)
{
    _bagage = bagage;
    // TODO : positionner le bagage exactement sur le chariot
    _tapisAssocie->deconnecter();
    demarrer();
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pgh1sO55Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::dechargerBatterie()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_r3Lz8PD-Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::avancer()
{
    QVector2D deplacement(_tronconActuel->noeudFin()->position() - _position);
    deplacement.normalize();
    deplacement *= _vitesse;

    _position += deplacement.toPointF();
    if (_bagage != 0)
    {
        _bagage->simulerDeplacement(deplacement);
    }
}


void Chariot::maj()
{
    switch (situation())
    {
        case ARRET :                    majArret(); break;
        case EN_CHEMIN :                majEnChemin(); break;
        case APPROCHE_OBJECTIF_FINAL :  majApprocheObjectifFinal(); break;
        case NOEUD_ATTEINT :            majNoeudAtteint(); break;
        case TOBOGGAN_ATTEINT :         majTobogganAtteint(); break;
        case TAPIS_ATTEINT :            majTapisAtteint(); break;
    }
}


Chariot::Situation Chariot::situation() const
{
    if (!_estActif)
    {
        return ARRET;
    }
    else if (QVector2D(_position - _tronconActuel->noeudFin()->position()).length()
        < RAYON_PROXIMITE_NOEUD)
    {
        // On est sur le noeud de fin du tronçon actuel
        return NOEUD_ATTEINT;
    }
    else if (_bagage != 0)
    {
        // Livraison de bagage en cours
        if (_bagage->objectifFinal()->estSupport(_tronconActuel))
        {
            if (QVector2D(_position - _tronconActuel->position()).length()
                < RAYON_PROXIMITE_TOBOGGAN)
            {
                return TOBOGGAN_ATTEINT;
            }
            else
            {
                return APPROCHE_OBJECTIF_FINAL;
            }
        }
        else
        {
            return EN_CHEMIN;
        }
    }
    else
    {
        // Retour au tapis en cours
        if (_tapisAssocie->estSupport(_tronconActuel))
        {
            if (QVector2D(_position - _tronconActuel->position()).length()
                < RAYON_PROXIMITE_TAPIS)
            {
                return TAPIS_ATTEINT;
            }
            else
            {
                return APPROCHE_OBJECTIF_FINAL;
            }
        }
        else
        {
            return EN_CHEMIN;
        }
    }
}

void Chariot::majArret()
{
    // Rien   faire
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << this << "à l'arrêt.";
#endif
}

void Chariot::majEnChemin()
{
#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << this << "avance avec" << _bagage;
#endif
    avancer();
}

void Chariot::majNoeudAtteint()
{
    Troncon* troncon;

#ifdef DEBUG_ACHEMINEMENT
    qDebug() << this << "sur" << _tronconActuel << ", arrive sur" << _tronconActuel->noeudFin();
#endif

    if(_bagage != 0)
    {
        troncon = _bagage->objectifFinal()->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }
    else
    {
        troncon = _tapisAssocie->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }

    if(troncon != 0 && troncon->occuper())
    {
        _tronconActuel->liberer();
        _tronconActuel = troncon;
        avancer();
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << this << "passe sur" << troncon;
#endif
    }
#ifdef DEBUG_ACHEMINEMENT
    else
    {
        qDebug() << this << "attend son tour pour passer sur" << troncon;
    }
#endif
}

void Chariot::majApprocheObjectifFinal()
{
#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << this << "retourne sur" << _tapisAssocie;
#endif
    // TODO
    avancer();
}

void Chariot::majTapisAtteint()
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << this << "a atteint son tapis" << _tapisAssocie;
#endif
    _tapisAssocie->connecter(this);
    arreter();
}

void Chariot::majTobogganAtteint()
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << this << "donne son bagage à" << _bagage->objectifFinal();
#endif
    _bagage->objectifFinal()->transfererBagage(_bagage);
    _bagage = 0;
}

#ifdef DEBUG_ACHEMINEMENT
QDebug operator<<(QDebug dbg, const Chariot *chariot)
{
    dbg.nospace() << "Chariot(" << chariot->id() << ")";

    return dbg.space();
}
#endif
