#pragma once

#include <vector>
#include <algorithm>
#include <assert.h>

template <typename T>
class PipVector : public std::vector<T>
{
    public:
        bool contains(const T &item) const;

        PipVector<T> &operator=(const std::vector<T> &rhs);
        PipVector<T> &operator<<(const T &item);
        PipVector<T> &operator<<(const PipVector<T> &toInsert);

        void append(const PipVector<T> &toInsert);
        void append(const std::vector<T> &toInsert);

        void sort();

        T takeLast();
        T takeFirst();
};

/**
 * Takes the items found in rhs and copies them into this vector. The original
 * content of this vector are removed.
 */
template <typename T>
PipVector<T> &
PipVector<T>::operator=(
        const std::vector<T> &rhs)
{
    if (&rhs == this)
        return *this;

    this->clear();

    for (auto it = rhs.begin; it != rhs.end(); ++it)
        this->push_back(*it);

    return *this;
}

template <typename T>
bool PipVector<T>::contains(
        const T &item) const
{
    for (auto it = this->begin(); it != this->end (); it++) 
    {
        if (item == *it)
            return true;
    }

    return false;
}

template <typename T>
PipVector<T> &PipVector<T>::operator<<(
        const T &item)
{
    this->push_back(item);
    return *this;
}

template <typename T>
PipVector<T> &PipVector<T>::operator<<(
        const PipVector<T> &toInsert)
{
    this->insert(this->end(), toInsert.begin(), toInsert.end());
    return *this;
}

template <typename T>
void PipVector<T>::append(
        const PipVector<T> &toInsert)
{
    this->insert(this->end(), toInsert.begin(), toInsert.end());
}

template <typename T>
void PipVector<T>::append(
        const std::vector<T> &toInsert)
{
    this->insert(this->end(), toInsert.begin(), toInsert.end());
}

template <typename T>
T PipVector<T>::takeLast()
{
    assert(!this->empty());

    T retval = this->back();
    this->pop_back();
    return retval;
}

template <typename T>
T PipVector<T>::takeFirst()
{
    assert(!this->empty());

    T retval = this->front();
    this->erase(this->begin());
    return retval;
}


template <typename T>
void
PipVector<T>::sort()
{
    std::sort(this->begin(), this->end());
}

