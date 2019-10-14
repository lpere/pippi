#pragma once

#include <PipVariantMap>

class PipObject
{
    public:
        PipObject();
        PipObject(const PipString &className);
        PipObject(const PipObject &orig);

        bool hasProperty(const PipString &key) const;
        PipVariant property(const PipString &name) const;
        void setProperty(const PipString &name, const PipVariant &value);
        void unsetProperty(const PipString &name);
        
        virtual const PipVariantMap &toVariantMap() const;
#if 0
        PipString toJsonString(
                const PipFormatFlags &formatFlags = PipFormatNormal) const; 
#endif
    private:
        PipVariantMap  m_properties;
};
