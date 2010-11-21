/**
  * @file Element.h
  * @author H4203
  */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <QPointF>
#ifdef DEBUG_ACHEMINEMENT
#include <QDebug>
#endif


#include "XmlConfigFactory.h"

//class Zone; //Dependency Generated Source:Element Target:Zone

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
/**
  * @todo
  */
class Element : public QObject
{
    Q_OBJECT
    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Element(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Element();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_h21_IPD4Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual QPointF position() const;

#ifdef DEBUG_ACHEMINEMENT
        friend QDebug operator<<(QDebug dbg, const Element &element);
#endif

    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_ncu9YOsVEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //Zone * zone;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_YHgIwPG4Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        QPointF _position;

#ifdef DEBUG_ACHEMINEMENT
        int _id;
        QString _typeElement;
#endif

};  //end class Element
#endif
