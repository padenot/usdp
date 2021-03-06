#include <QXmlSimpleReader>
#include <QFile>
#include <QXmlInputSource>
#include <QDebug>

#include "Prototype.h"
#include "XmlConfigFactory.h"


//Begin section for file Prototype.cpp
//TODO: Add definitions that you want preserved
//End section for file Prototype.cpp


const int Prototype::INTERVALLE_RAFRAICHISSEMENT_MODELE = 10; // En ms

const int Prototype::ID_BAGAGE_GENERE_INITIAL = 1000;


Prototype::Prototype(const QString& xmlfilepath) :
        QObject(0),
        _elementsParType(),
        _mode_generation_bagage(AUTOMATIQUE),
        _id_bagage_genere(ID_BAGAGE_GENERE_INITIAL),
        _dt (INTERVALLE_RAFRAICHISSEMENT_MODELE / 1000.0)
{
    qsrand(time(0));
    // Désérialise le fichier XML.
    // Extrait et classe par type des pointeurs d'éléments.
    XmlConfigFactory handler;
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);

    QFile file(xmlfilepath);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Cannot read XML file." << endl;
        exit(1);
    }

    QXmlInputSource xmlInputSource(&file);
    if (reader.parse(xmlInputSource))
    {
        _elementsParType = handler.resultat();
    }

    _horloge.setInterval(INTERVALLE_RAFRAICHISSEMENT_MODELE);

    connect(&_horloge, SIGNAL(timeout()), this, SLOT(maj()));
}

Prototype::~Prototype()
{
    foreach(QVector<Element*> tabElements, _elementsParType)
    {
        foreach(Element* element, tabElements)
        {
            delete element;
        }
    }
}

Bagage* Prototype::ajouterBagage(Tapis* tapis, Vol* vol)
{
    Bagage* bagage = new Bagage(vol,tapis->position());

#ifdef DEBUG_ACHEMINENEMENT
    // TODO : sert à quoi ?
    XmlConfigFactory::IndexParamValeur parametres;
    parametres[XmlConfigFactory::NodeName_String[XmlConfigFactory::typeElement]] = XmlConfigFactory::NodeName_String[XmlConfigFactory::bagage];
    parametres[XmlConfigFactory::NodeName_String[XmlConfigFactory::id]] = _id_bagage_genere++;
#endif

    if(!tapis->ajouterBagage(bagage))
    {
        delete bagage;
        return 0;
    }

    connect(bagage,SIGNAL(destroyed(QObject*)),
            this,SLOT(destructionBagage(QObject*))/*,Qt::BlockingQueuedConnection*/);

    _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::bagage]].append(bagage);

    return bagage;
}


Bagage* Prototype::ajouterBagageAleatoire()
{
    int nbvol = _modelVols.rowCount(QModelIndex());
    // On peut pas générer de bagage s'il n'y a pas de vol
    if(nbvol != 0)
    {
        // Le nouveau bagage choisi un vol au hasard.
        Vol* vol = 0;
        vol = _modelVols.at(qrand() % nbvol);
        if(vol != 0)
        {
            if(vol->tobogganAssocie())
            {
                int nbtapis = _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]].size();
                Tapis* tapis = dynamic_cast<Tapis*>(_elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]][qrand()%nbtapis]);
                return ajouterBagage(tapis,vol);
            }
        }
    }
    return 0;
}

void Prototype::changementModeAjoutBagage(ModeSimulation mode)
{
    if(mode == AUTOMATIQUE)
    {
        connect(&_horloge, SIGNAL(timeout()), this, SLOT(ajouterBagageAleatoire()));
    }
    else if(mode == MANUEL)
    {
        disconnect(this, SLOT(ajouterBagageAleatoire()));
    }
}

void Prototype::commencerSimulation()
{
     _horloge.start();
}

void Prototype::arreterSimulation()
{
    _horloge.stop();
}

int Prototype::changerVitesse(int pourcentage)
{
    if (pourcentage < 0)
    {
        pourcentage = 0;
    }
    _dt = Prototype::INTERVALLE_RAFRAICHISSEMENT_MODELE / 1000.0 * pourcentage / 100.0;

    return pourcentage;
}

bool Prototype::estEnMarche()
{
    return _horloge.isActive();
}

const XmlConfigFactory::IndexTypesElements &Prototype::elements()
{
    return _elementsParType;
}

void Prototype::destructionBagage(QObject* bagage)
{
    int index = _elementsParType
          [XmlConfigFactory::NodeName_String[XmlConfigFactory::bagage]].indexOf(
                  reinterpret_cast<Bagage*>(bagage));

    if (index >= 0)
    {
        _elementsParType
                  [XmlConfigFactory::NodeName_String[XmlConfigFactory::bagage]]
                  .remove(index);
    }
}

void Prototype::maj()
{
    foreach(Element* chariot,
            _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::chariot]])
    {
        dynamic_cast<Chariot*>(chariot)->maj(_dt);
    }

    foreach(Element* tapis,
            _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]])
    {
        dynamic_cast<Tapis*>(tapis)->maj(_dt);
    }
}

ModelVols* Prototype::modelVols()
{
    return &_modelVols;
}

// Return false si y'a toujours des bagage
bool Prototype::retirerVol(int i)
{
    foreach(Element* b, _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::bagage]])
    {
        Bagage* bagage = dynamic_cast<Bagage*>(b);
        if(bagage->volAssocie() == modelVols()->at(i))
        {
            return false;
        }
    }

    _modelVols.retirerVol(i);
    return true;
}

void Prototype::ajouterVol(Vol* vol)
{
    _modelVols.ajouterVol(vol);
}

Vol* Prototype::vol(int index)
{
    return _modelVols.at(index);
}
