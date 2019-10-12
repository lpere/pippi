#ifdef DEBUG_ALL
#  ifndef DEBUG
#    define DEBUG
#  endif
#  ifndef WARNING
#    define DEBUG
#  endif
#  ifndef MESSAGE
#    define DEBUG
#  endif
#endif

#ifdef PUBLIC_RELEASE
#  ifdef DEBUG
#    undef DEBUG
#  endif
#  ifdef WARNING
#    undef WARNING
#  endif
#endif
#undef PIP_DEBUG
#ifdef DEBUG

/**
 * The PIP_DEBUG macro is used to print normal debug messages to be seen only
 * during the development.
 */
#  define PIP_DEBUG(...) pip_print_message (\
        DebugMsg, \
        __func__, \
        __VA_ARGS__)
#else

/**
 * The PIP_DEBUG macro is used to print normal debug messages to be seen only
 * during the development.
 */
#  define PIP_DEBUG(...) { /* Nothing... */ }
#endif

#undef PIP_WARNING
#ifdef WARNING
/**
 * The PIP_WARNING is used to print warning messages to be seen only during the
 * development.
 */
#  define PIP_WARNING(...) pip_print_message (\
        WarningMsg, \
        __func__, \
        __VA_ARGS__)
#else
/**
 * The PIP_WARNING is used to print warning messages to be seen only during the
 * development.
 */
#  define PIP_WARNING(...) { /* Nothing... */ }
#endif

/**
 * 
 */
typedef enum PipMessageLevel
{
    DebugMsg,
    WarningMsg
} PipMessageLevel;

#ifndef PIPDEBUG_H
#define PIPDEBUG_H
/** Clear until the end of line.*/
#define TERM_ERASE_EOL "\033[K"

#define TERM_CURSOR_OFF "\033[?25l"
#define TERM_CURSOR_ON  "\033[?25h"

#define TERM_AUTOWRAP_OFF "\033[?7l"
#define TERM_AUTOWRAP_ON  "\033[?7h"

#define TERM_HOME "\033[H"
/** Clear the entire screen.*/
#define TERM_CLEAR_SCREEN "\033[2J"
/** Yellow terminal color sequence. */
#define TERM_RED  "\033[38;5;9m" 
/** Red terminal color sequence. */
#define TERM_YELLOW     "\033[1;33m" 
/** Green terminal color sequence. */
#define TERM_GREEN   "\033[38;5;10m"
/** Blue terminal color sequence. */
#define TERM_BLUE    "\033[38;5;4m"
/** Terminal reset sequence. */
#define TERM_NORMAL  "\033[0;39m"
/** Turns the terminal to bold. */
#define TERM_BOLD    "\033[1m"
/** Inverse color terminal sequence.*/
#define TERM_INVERSE "\033[7m"
/** Turns underline in the terminal. */
#define TERM_UNDERLINE    "\033[4m"

#define TERM_SCREEN_TITLE  TERM_NORMAL "\033[2m\033[48;5;17m"
#define TERM_SCREEN_TITLE_BOLD TERM_NORMAL "\033[1m\033[48;5;17m"

#define TERM_SCREEN_HEADER "\033[1m\033[48;5;239m"

/** Dark red. */
#define XTERM_COLOR_1 "\033[38;5;1m"
/** Dark green. */
#define XTERM_COLOR_2 "\033[38;5;2m"
/** Dark orange. */
#define XTERM_COLOR_3 "\033[38;5;3m"
/** Dark blue. */
#define XTERM_COLOR_4 "\033[38;5;4m"
/** Brown. */
#define XTERM_COLOR_5 "\033[38;5;5m"
/** Greenish blue. */
#define XTERM_COLOR_6 "\033[38;5;6m"
/** Dark grey. */
#define XTERM_COLOR_7 "\033[38;5;8m"
/** Red color. */
#define XTERM_COLOR_8 "\033[38;5;9m"
/** Green color. */
#define XTERM_COLOR_9 "\033[38;5;10m"
/** Blue color. */
#define XTERM_COLOR_10 "\033[38;5;12m"
/** Light brown color. */
#define XTERM_COLOR_11 "\033[38;5;13m"
/** Light blue color. */
#define XTERM_COLOR_12 "\033[38;5;14m"
/** Terminal custom color. */
#define XTERM_COLOR_13 "\033[38;5;17m"
/** Clear dark blue terminal color sequence. */
#define XTERM_COLOR_14 "\033[38;5;21m"
/** Blackish blue terminal color sequence. */
#define XTERM_COLOR_15 "\033[38;5;19m"
/** Neon color terminal color sequence. */
#define XTERM_COLOR_16 "\033[38;5;93m"
/** Neon purple */
#define XTERM_COLOR_17 "\033[38;5;171m"

#define XTERM_COLOR_RED          "\033[0;31m"
#define XTERM_COLOR_GREEN        "\033[0;32m"
#define XTERM_COLOR_ORANGE       "\033[0;33m"
#define XTERM_COLOR_BLUE         "\033[0;34m"
#define XTERM_COLOR_PURPLE       "\033[0;35m"
#define XTERM_COLOR_CYAN         "\033[0;36m"
#define XTERM_COLOR_LIGHT_GRAY   "\033[0;37m"
#define XTERM_COLOR_DARK_GRAY    "\033[1;30m"
#define XTERM_COLOR_LIGHT_RED    "\033[1;31m"
#define XTERM_COLOR_LIGHT_GREEN  "\033[1;32m"
#define XTERM_COLOR_YELLOW       "\033[1;33m"
#define XTERM_COLOR_LIGHT_BLUE   "\033[1;34m"
#define XTERM_COLOR_LIGHT_PURPLE "\033[1;35m"
#define XTERM_COLOR_LIGHT_CYAN   "\033[1;36m"
#define XTERM_COLOR_WHITE        "\033[1;37m"

#define XTERM_COLOR_USER         "\033[38;5;166m"
#define XTERM_COLOR_SERVER       "\033[92m"
#define XTERM_COLOR_NODE         "\033[2m\033[33m"
#define XTERM_COLOR_IP           "\033[1;2m\033[38;5;176m"
#define XTERM_COLOR_NIC_UP       "\033[1;2m\033[38;5;40m"
#define XTERM_COLOR_NIC_NOLINK   "\033[1;2m\033[38;5;184m"
#define XTERM_COLOR_DIR          "\033[1;2m\033[38;5;27m"
#define XTERM_COLOR_FOLDER       "\033[93m"
#define XTERM_COLOR_FILESYSTEM   "\033[1;2m\033[38;5;13m"
#define XTERM_COLOR_BDEV         "\033[38;5;11m"
#define XTERM_COLOR_NUMBER       "\033[1m"
#define XTERM_COLOR_DATABASE     "\033[38;5;202m"
#define XTERM_COLOR_CLASS        "\033[96m"
#define XTERM_COLOR_SUBCLASS     "\033[38;5;123m"
#define XTERM_COLOR_TAG          "\033[38;5;69m"
#define XTERM_COLOR_REGION_OK    "\033[2m\033[38;5;50m"
#define XTERM_COLOR_REGION_FAIL  "\033[1m\033[38;5;9m"
#define XTERM_COLOR_SELECTION    "\033[1m\033[48;5;4m"

#define TERM_COLOR_BOOLEAN       "\033[38;5;203m"
#define TERM_COLOR_NUMERIC       "\033[38;5;83m"
#define TERM_COLOR_STRING        "\033[38;5;166m"
#define TERM_COLOR_NULL          "\033[38;5;160m"

void 
pip_print_message (
        PipMessageLevel  type,
        const char       *function,
        const char       *formatstring,
        ...);

/**
 * A macro to print booleans.
 */
#define PIP_BOOL(_boolval) ((_boolval ? "true" : "false"))
#define STR(_stringval) ((_stringval).c_str())
#endif

