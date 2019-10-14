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
        PipVariant(const size_t value);
        PipVariant(const PipString &value);
        PipVariant(const PipVariantMap &value);
        
        PipVariant &operator=(const bool value);
        PipVariant &operator=(const int value);
        PipVariant &operator=(const ulonglong value);
        PipVariant &operator=(const double value);
        PipVariant &operator=(const size_t value);
        PipVariant &operator=(const PipString &value);
        PipVariant &operator=(const char *value);

        PipString toString() const;
        
    private:
        void clearValue();
        
    private:
        std::shared_ptr<PipVariantPrivate> m_priv;
};
