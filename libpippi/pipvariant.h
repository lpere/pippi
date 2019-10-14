#pragma once

#include <memory>
#include <PipTypes>

class PipVariantPrivate;
class PipString;
class PipVariantMap;

class PipVariant
{
    public:
        PipVariant();
        PipVariant(const PipVariant &orig) = default;

        PipVariant(const bool value);
        PipVariant(const int value);
        PipVariant(const ulonglong value);
        PipVariant(const double value);
        PipVariant(const PipString &value);
        PipVariant(const size_t value);
        PipVariant(const PipVariantMap &value);
        
    private:
        std::shared_ptr<PipVariantPrivate> m_priv;
};
