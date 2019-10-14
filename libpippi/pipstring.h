#pragma once

#include <string>
#include <stdarg.h>

/**
 * A string class that is based on std::string and adds a number of extra
 * methods for convenience.
 */
class PipString : public std::string
{
    public:
        PipString();
        PipString(const char *theString);

        void sprintf(const char *formatString, ...);
        void vsprintf(const char *formatString, va_list arguments);
        void aprintf(const char *formatString, ...);

        void replace(const PipString &from, const PipString &to);
        PipString &replace(size_t position, size_t length, const PipString &to);
};

