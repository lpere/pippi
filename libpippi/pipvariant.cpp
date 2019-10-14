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
