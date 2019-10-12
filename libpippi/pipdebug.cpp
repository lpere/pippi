#include "pipdebug.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void
pip_print_message (
        PipMessageLevel   type,
        const char        *function,
        const char        *formatstring,
        ...)
{
    FILE          *stream = stderr;
    va_list        args;

    va_start (args, formatstring);
    switch (type) 
    {
        case DebugMsg:
            fprintf (stream, "%s%s%s: ", 
                    TERM_GREEN TERM_BOLD, function, TERM_NORMAL);
            vfprintf (stream, formatstring, args);
            break;

        case WarningMsg:
            fprintf (stream, "%s%s%s: ", TERM_RED, function, TERM_NORMAL);
            vfprintf (stream, formatstring, args);
            break;
    }
    va_end(args);
    fprintf(stream, "\n");
    fflush(stream);
}
