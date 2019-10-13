#pragma once

#include <cstddef>

class PipString;
class PipVariantMap;

typedef unsigned long long int ulonglong;
typedef unsigned int uint;
typedef unsigned char byte;

enum PipType
{
    Invalid   = 0,

    Bool,
    Char,
    Integer,
    Ulonglong,
    Double,
    SizeT,

    String,
    Map,
};

union PipUnion 
{
    int                 iVal;
    double              dVal;
    bool                bVal;
    ulonglong           ullVal;
    size_t              sizeVal;
    PipString          *stringVal;
    PipVariantMap      *mapValue;
};
