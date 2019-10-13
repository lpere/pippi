#pragma once

#include "PipTypes"

class PipVariantPrivate
{
    public:
        virtual ~PipVariantPrivate();

    private:
        PipType    m_type;
        PipUnion   m_union;

    friend class PipVariant;
};
