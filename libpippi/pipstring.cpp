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

void
PipString::sprintf(
        const char *formatString,
        ...)
{
    va_list arguments;

    va_start(arguments, formatString);
    vsprintf(formatString, arguments);
    va_end(arguments);
}

/**
 * 
 */
void
PipString::aprintf(
        const char *formatString,
        ...)
{
    PipString  toAppend;
    va_list    arguments;

    va_start(arguments, formatString);
    toAppend.vsprintf(formatString, arguments);
    va_end(arguments);

    *this += toAppend;
}

void
PipString::vsprintf(
        const char *formatString,
        va_list     arguments)
{
    int     nPrinted;
    size_t  bufferLength = 512;
    char   *buffer = (char *) malloc(bufferLength);

    va_list argsCopy;
    va_copy(argsCopy, arguments);

    nPrinted = vsnprintf(buffer, bufferLength, formatString, arguments);

    if (nPrinted >= (int)bufferLength)
    {
        buffer = (char *) realloc(buffer, nPrinted + 1);
        bufferLength = nPrinted + 1;

        vsnprintf(buffer, bufferLength, formatString, argsCopy);
    }

    va_end(argsCopy);

    *this = buffer;

    if (buffer)
        free(buffer);
}

void
PipString::replace(
        const PipString &from,
        const PipString &to)
{
    size_t start_pos = 0;

    while ((start_pos = find(from, start_pos)) != std::string::npos) 
    {
        std::string::replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
}

PipString &
PipString::replace(
        size_t           position,
        size_t           length,
        const PipString &to)
{
    std::string::replace(position, length, to);
    return *this;
}

