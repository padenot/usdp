#include <QXmlSimpleReader>
#include <QFile>
#include <QXmlInputSource>
#include <QDebug>

#include "Prototype.h"
#include "XmlConfigFactory.h"


//Begin section for file Prototype.cpp
//TODO: Add definitions that you want preserved
//End section for file Prototype.cpp

const int NOMBRE_CHANCE_BAGAGE_PAR_TICK = 1000;

const int Prototype::INTERVALLE_RAFRAICHISSEMENT_MODELE = 10; // En ms

const int Prototype::ID_BAGAGE_GENERE_INITIAL = 1000;


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
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

        qDebug() << _elementsParType;
    }

    _horloge.setInterval(INTERVALLE_RAFRAICHISSEMENT_MODELE);

    connect(&_horloge, SIGNAL(timeout()), this, SLOT(ajouterBagageAleatoire()));
    connect(&_horloge, SIGNAL(timeout()), this, SLOT(maj()));
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
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

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_oCLrkO59Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Prototype::changementMode(ModeSimulation mode)
{
    // TODO
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_0yUWMO59Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
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


void Prototype::ajouterBagageAleatoire()
{
    /*
    // Un bagage doit être généré
    int generated = qrand()%NOMBRE_CHANCE_BAGAGE_PAR_TICK;
    if( ! generated)
    {
        qDebug() << "Ajout de bagage !";
        if( ! _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::vol]].empty())
        {
            // Le nouveau bagage choisi un vol au hasard.
            Vol* vol = 0;
            while( ! (vol = _modelVols[qrand() % _vols.size()]))
            {
                if(vol->tobogganAssocie())
                {
                    break;
                }
            }
            // Et un tapis au hasard aussi
            int nbtapis = _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::vol]].size();
            Tapis* tapis = dynamic_cast<Tapis*>(_elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::vol]][qrand()%nbtapis]);

            ajouterBagage(tapis,vol);
            // TODO : ajouter la vue... ?
        }
    }
    */
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Eq-X8PCiEd-54vpurc77FA"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Prototype::changementModeAjoutBagage(ModeSimulation mode)
{
    //TODO Auto-generated method stub
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
