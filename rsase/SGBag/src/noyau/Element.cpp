#ifdef DEBUG_ACHEMINEMENT
#include <QDebug>
#include <QString>
#endif

#include "Element.h"
#include "XmlConfigFactory.h"

Element::Element(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        _position(indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::x]].toFloat(),
                  indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::y]].toFloat()),
        _id (indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::id]].toInt())
#ifdef DEBUG_ACHEMINEMENT
        ,
        _typeElement(indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::typeElement]])
#endif
{
    // Vide
}

void Element::init (const XmlConfigFactory::IndexParamValeur& /*indexParamValeur*/,
                   XmlConfigFactory& /*fabrique*/)
{
    // Vide
}

Element::~Element()
{
    //TODO Auto-generated method stub
}

QPointF Element::position() const
{
    return _position;
}

#ifdef DEBUG_ACHEMINEMENT
QDebug operator<<(QDebug dbg, const Element &element)
{
    dbg.nospace() << element._typeElement.toAscii().data() << "(" << element._id << ")";

    return dbg.space();
}
#endif

int Element::id()
{
    return _id;
}
