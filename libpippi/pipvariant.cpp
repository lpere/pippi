#include "pipvariant.h"
#include "pipvariant_p.h"

#include "PipString"
#include "PipVariantMap"

#define DEBUG
#define WARNING
#include "pipdebug.h"

PipVariant::PipVariant() 
{
    m_priv = std::make_shared<PipVariantPrivate>();

    m_priv->m_type = Invalid;
}

PipVariant::PipVariant(
        const bool value)
{
    m_priv = std::make_shared<PipVariantPrivate>();
    
    m_priv->m_type = Bool;
    m_priv->m_union.bVal = value;
}

PipVariant::PipVariant(
        const int value) 
{
    m_priv = std::make_shared<PipVariantPrivate>();
    
    m_priv->m_type = Integer;
    m_priv->m_union.iVal = value;
}

PipVariant::PipVariant(
        const ulonglong value) 
{
    m_priv = std::make_shared<PipVariantPrivate>();
    
    m_priv->m_type         = Ulonglong;
    m_priv->m_union.ullVal = value;
}

PipVariant::PipVariant(
        const double value) 
{
    m_priv = std::make_shared<PipVariantPrivate>();
    
    m_priv->m_type       = Double;
    m_priv->m_union.dVal = value;
}

PipVariant::PipVariant(
        const PipString &value) 
{
    m_priv = std::make_shared<PipVariantPrivate>();
    
    m_priv->m_type = String;
    m_priv->m_union.stringVal = new PipString(value);
}

PipVariant::PipVariant(
        const size_t value) 
{
    m_priv = std::make_shared<PipVariantPrivate>();
    
    m_priv->m_type = SizeT;
    m_priv->m_union.sizeVal = value;
}

PipVariant::PipVariant(
        const PipVariantMap &value)
{
    m_priv = std::make_shared<PipVariantPrivate>();

    m_priv->m_type = Map;
    m_priv->m_union.mapValue = new PipVariantMap(value);
}

PipVariant &
PipVariant::operator=(
        const bool value)
{
    clearValue();
     
    m_priv->m_type       = Bool;
    m_priv->m_union.bVal = value;

    return *this;
}

PipVariant &
PipVariant::operator=(
        const int value)
{
    clearValue();
     
    m_priv->m_type       = Integer;
    m_priv->m_union.iVal = value;

    return *this;
}

PipVariant &
PipVariant::operator=(
        const ulonglong value)
{
    clearValue();
     
    m_priv->m_type         = Ulonglong;
    m_priv->m_union.ullVal = value;

    return *this;
}

PipVariant &
PipVariant::operator=(
        const double value)
{
    clearValue();
     
    m_priv->m_type       = Double;
    m_priv->m_union.dVal = value;

    return *this;
}

PipVariant &
PipVariant::operator=(
        const size_t value) 
{
    clearValue();

    m_priv->m_type = SizeT;
    m_priv->m_union.sizeVal = value;

    return *this;
}

PipVariant &
PipVariant::operator=(
        const PipString &value) 
{
    clearValue();
    
    m_priv->m_type = String;
    m_priv->m_union.stringVal = new PipString(value);
    return *this;
}

PipVariant &
PipVariant::operator=(
        const char *value) 
{
    clearValue();
    
    m_priv->m_type = String;
    m_priv->m_union.stringVal = new PipString(value);
    return *this;
}

/**
 * This method will convert the value in the variant to a string. The string
 * created here is not a JSon compliant string, it doesn't have double quotes
 * for example.
 */
PipString
PipVariant::toString() const
{
    PipString  retval;

    switch (m_priv->m_type)
    {
        case Invalid:
            retval = "null";
            break;

        case Bool:
            retval = m_priv->m_union.bVal ? "true" : "false";
            break;

        case Integer:
            retval.sprintf("%d", m_priv->m_union.iVal);
            break;

        case Ulonglong:
            retval.sprintf("%llu", m_priv->m_union.ullVal);
            break;

        case Double:
            retval.sprintf("%g", m_priv->m_union.dVal);
            break;
        
        case SizeT:
            retval.sprintf("%zu", m_priv->m_union.sizeVal);
            break;
        
        case Char:
            retval.sprintf("%c", m_priv->m_union.cVal);
            break;

        case String:
            retval = *m_priv->m_union.stringVal;
            break;
        
        case Map:
            retval = "map";
            break;
    }

    return retval;
}


/**
 * Drops the value from the variant and sets it to "Invalid". This is a private
 * method that we call when the value is changed (e.g. in assignment operators).
 */
void
PipVariant::clearValue()
{
    switch (m_priv->m_type)
    {
        case Invalid:
        case Bool:
        case Char:
        case Integer:
        case Ulonglong:
        case Double:
        case SizeT:
            break;
        
        case Map:
            delete m_priv->m_union.mapValue;
            break;
        
        case String:
            delete m_priv->m_union.stringVal;
            break;    
    }

    m_priv->m_type = Invalid;    
}

