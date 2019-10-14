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
    bool                bVal;
    char                cVal;
    int                 iVal;
    double              dVal;
    ulonglong           ullVal;
    size_t              sizeVal;
    PipString          *stringVal;
    PipVariantMap      *mapValue;
};
