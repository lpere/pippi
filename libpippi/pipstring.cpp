#include "pipstring.h"

#define DEBUG
//#define WARNING
#include "pipdebug.h"

PipString::PipString() :
    std::string()
{
}

PipString::PipString(
        const char *theString) :
    std::string(theString)
{
}
