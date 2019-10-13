#pragma once

#include <map>

#include "PipVector"

template <typename Key, typename T>
class PipMap : public std::map<Key, T>
{
    public:
        bool contains(const Key &key) const;
        PipVector<Key> keys() const;
};

template <typename Key, typename T>
inline bool PipMap<Key, T>::contains(
        const Key &key) const
{
    return this->find(key) != this->end();
}

template <typename Key, typename T>
PipVector<Key> PipMap<Key, T>::keys() const
{
    PipVector<Key> retval;

    for (typename std::map<Key, T>::const_iterator it = this->begin(); it != this->end(); ++it) 
    {
        retval.push_back(it->first);
    }

    return retval;
}
