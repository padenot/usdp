#include <QVector2D>

#include "Chariot.h"
#include "Troncon.h"
#include "Tapis.h"
#include "XmlConfigFactory.h"
#include "StrategiePilotageAuto.h"
#include "StrategiePilotageManuel.h"

const double Chariot::ACCELERATION_CHARIOT = 20; // m/s²
const double Chariot::DECELERATION_CHARIOT = 70; // m/s²
const double Chariot::MAX_DEPASSEMENT_VITESSEMAX = 0.3; // m/s

Chariot::Chariot(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
    ElementActif(indexParamValeur),
    _bagage (0),
    _tapisConnecte (0),
    _directionConseillee (GAUCHE),
    _typePilotage (AUTOMATIQUE),
    _pilote (0)
{
}

void Chariot::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    ElementActif::init(indexParamValeur,fabrique);
    Troncon* tronconActuel = 0;
    Tapis* tapisAssocie = 0;

    tronconActuel = dynamic_cast<Troncon*>(fabrique.elementParId(
        indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()
        ));
    tapisAssocie = dynamic_cast<Tapis*>(fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapisAssocie]].toInt()));

    _position = tronconActuel->position();
    _pilote = new StrategiePilotageAuto(*this, tronconActuel, tapisAssocie);
}

Chariot::~Chariot()
{
    // _bagage est détruit par le prototype
    // La stratégie est un QObject, détruit automatiquement à
    // la destruction de ce chariot.
}

void Chariot::chargerBagage(Bagage* bagage)
{
    _bagage = bagage;
    // TODO : positionner le bagage exactement sur le chariot
}

Bagage* Chariot::dechargerBagage()
{
    Bagage* bagage = _bagage;
    _bagage = 0;
    return bagage;
}

void Chariot::connecter (Tapis* tapis)
{
    if (_tapisConnecte == 0 && tapis != 0)
    {
        _tapisConnecte = tapis;
        tapis->connecter(this);
    }
}

void Chariot::deconnecter ()
{
    if (_tapisConnecte != 0)
    {
        Tapis* tapis = _tapisConnecte;
        _tapisConnecte = 0;
        tapis->deconnecter();
    }
}

void Chariot::avancer(double dt, QPointF destination)
{
    QVector2D deplacement(destination - _position);
    deplacement.normalize();

    if (_estActif)
    {
        if (_vitesse < _vitesseMax)
        {
            _vitesse += ACCELERATION_CHARIOT*dt;
            emit vitesseModifiee(_vitesse);
        }
        else if(_vitesse > (_vitesseMax + MAX_DEPASSEMENT_VITESSEMAX))
        {
            _vitesse -= DECELERATION_CHARIOT*dt;
            emit vitesseModifiee(_vitesse);
        }
    }
    else
    {
        if (_vitesse > 0.0)
        {
            _vitesse -= DECELERATION_CHARIOT*dt;
            emit vitesseModifiee(_vitesse);
        }
        else if (_vitesse < 0.0)
        {
            _vitesse = 0.0;
        }
    }

    if (_vitesse > 0)
    {
        deplacement *= _vitesse * dt;
        _position += deplacement.toPointF();
        if (_bagage != 0)
        {
            _bagage->simulerDeplacement(deplacement);
        }
    }
}

void Chariot::maj(double dt)
{
    avancer(dt,_pilote->piloter(dt,_bagage));
}

void Chariot::accelerer()
{
    deconnecter();
    ElementActif::accelerer();
}

Chariot::TypePilotage Chariot::typePilotage()
{
    return _typePilotage;
}

Direction Chariot::directionConseillee()
{
    return _directionConseillee;
}

double Chariot::distanceArret()
{
    // La décélération est linéaire
    return - _vitesse * _vitesse / (2 * -DECELERATION_CHARIOT);
}

void Chariot::modifierTypePilotage(TypePilotage type)
{
    StrategiePilotage* ancienPilote = _pilote;
    if (type != _typePilotage)
    {
        switch(type)
        {
            case AUTOMATIQUE :
                _pilote = new StrategiePilotageAuto(*_pilote);
                break;
            case MANUEL :
                _pilote = new StrategiePilotageManuel(*_pilote);
                break;
        }

        _typePilotage = type;

        delete ancienPilote;
    }
}

void Chariot::modifierDirectionConseillee(Direction direction)
{
    _directionConseillee = direction;
}
