#pragma once

#include <string>
#include <stdarg.h>

class PipString : public std::string
{
    public:
        PipString();
        PipString(const char *theString);

};

