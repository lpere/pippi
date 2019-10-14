#include "pipexception.h"

//#define DEBUG
//#define WARNING
#include "pipdebug.h"

PipException::PipException(
        const char *file, 
        const int   line, 
        const char *formatString,
        ...) :
    m_file(file),
    m_line(line)
{
    va_list        args;

    va_start (args, formatString);
    m_message.vsprintf(formatString, args);
    va_end(args);
}

void
PipException::printMessage() const
{
    ::fprintf(stderr, "%s:%d: %s\n",
            STR(m_file),
            m_line,
            STR(m_message));
}

PipString 
PipException::message() const
{
    PipString retval;

    retval.sprintf(
            "%s:%d: %s\n",
            STR(m_file),
            m_line,
            STR(m_message));

    return retval;
}


