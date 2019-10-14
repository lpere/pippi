#pragma once

#include <PipString>

class PipException
{
    public:
        PipException(
                const char      *file, 
                const int        line, 
                const char *formatString,
                ...);

        void printMessage() const;
        PipString message() const;

    private:
        PipString    m_file;
        int          m_line;
        PipString    m_message;
};


#define PIP_EXCEPTION(...) \
    PipException(__FILE__, __LINE__, __VA_ARGS__)

