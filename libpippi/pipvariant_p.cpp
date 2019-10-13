#include "pipvariant_p.h"

#include "PipString"

PipVariantPrivate::~PipVariantPrivate()
{
    switch (m_type)
    {
        case String:
            if (m_union.stringVal)
                delete m_union.stringVal;
            break;

        default:
            // Nothing.
            break;
    }
}

