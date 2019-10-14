#include "pipobject.h"

//#define DEBUG
//#define WARNING
#include "pipdebug.h"

PipObject::PipObject()
{
}

/**
 * \param className The name of the class to be stored as the "class_name"
 * property.
 */
PipObject::PipObject(
        const PipString &className)
{
    m_properties["class_name"] = className;
}


/**
 * The copy constructor.
 */
PipObject::PipObject(
        const PipObject &orig)
{
    m_properties = orig.m_properties;
}

/**
 * \returns True if a property with the given key exists and set.
 */
bool
PipObject::hasProperty(
        const PipString &key) const
{
    return m_properties.contains(key);
}

/**
 * \returns The value of the property with the given name or the invalid
 *   PipVariant object if the property is not set.
 */
PipVariant
PipObject::property(
        const PipString &name) const
{
    if (m_properties.contains(name))
        return m_properties.at(name);

    return PipVariant();
}

void
PipObject::setProperty(
        const PipString  &name,
        const PipVariant &value)
{
    m_properties[name] = value;
}

void 
PipObject::unsetProperty(
        const PipString &name)
{
    m_properties.erase(name);
}

const PipVariantMap &
PipObject::toVariantMap() const
{
    return m_properties;
}

#if 0
PipString
PipObject::toJsonString(
        const PipFormatFlags &formatFlags) const
{
    return toVariantMap().toJsonString(formatFlags);
}
#endif
