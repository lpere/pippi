#include <unistd.h>
#include <stdio.h>

#include "PipConfigParser"
#include "PipRelay"

#define DEBUG
//#define WARNING
#include "pipdebug.h"

#define TERM_COLOR_NORMAL  "\033[0;39m"
#define TERM_COLOR_RED     "\033[91m"
#define TERM_COLOR_GREEN   "\033[92m"
#define TERM_COLOR_LIGHT_BLUE "\033[96m"
#define TERM_COLOR_PINK       "\033[95m"
#define TERM_COLOR_YELLOW     "\033[93m"
#define TERM_COLOR_BROWN      "\033[2m\033[38;5;215m"
#define TERM_COLOR_ORANGE     "\033[38;5;208m"
#define TERM_COLOR_DARK_GREY  "\033[2m\033[38;5;238m"


uint32_t last_tick = 0u;
unsigned int     n_ticks   = 0u;
bool             watch = false;

/**
 * \param tick Measured in microseconds.
 */
void gpio_callback(
        int gpio,
        int level,
        uint32_t tick)
{
    if (!watch)
    {
        last_tick = tick;
        return;
    }

#if 0
    ::printf("level: %s tick: %6u n: %3u\n", 
            level == 0 ? "¯\\_" : "_/¯", 
            tick - last_tick,
            n_ticks);
#else
    uint32_t diff = tick - last_tick;

    if (level == 0)
    {
        ::printf("%3u ", n_ticks);
        ::printf("%5u ", diff);
        if (diff > 200)
        {
            ::printf("_/¯¯¯¯¯¯\\\n");
        } else if (diff > 60)
        {
            ::printf("_/¯¯\\\n");
        } else if (diff > 15)
        {
            ::printf("_/¯\\\n");
        } else {
            ::printf("_|_\n");
        }
    }
#endif
    last_tick = tick;
    if (level == 0)
        n_ticks++;
}

void
printHeader()
{
    const char *normal = TERM_COLOR_NORMAL;
    const char *red    = TERM_COLOR_RED;
    const char *green  = TERM_COLOR_GREEN;
    const char *lblue  = TERM_COLOR_LIGHT_BLUE;
    const char *pink   = TERM_COLOR_PINK;
    const char *yellow = TERM_COLOR_YELLOW;
    const char *brown  = TERM_COLOR_BROWN;
    const char *orange = TERM_COLOR_ORANGE;
    const char *black  = TERM_COLOR_DARK_GREY;

    printf(" 3.3V Vcc %so%s %so%s 5V Vcc\n", brown, normal, red, normal);
    printf("   GPIO02 %so%s %so%s 5V Vcc\n", lblue, normal, red, normal);
    printf("   GPIO03 %so%s %so%s GND\n",    lblue, normal, black, normal);
    printf("   GPIO04 %so%s %so%s GPIO14\n", green, normal, orange, normal);
    printf("      GND %so%s %so%s GPIO15\n", black, normal, orange, normal);
    printf("   GPIO17 %so%s %so%s GPIO18\n", green, normal, green, normal);
    printf("   GPIO27 %so%s %so%s GND\n",    green, normal, black, normal);
    printf("   GPIO22 %so%s %so%s GPIO23\n", green, normal, green, normal);
    printf(" 3.3V Vcc %so%s %so%s GPIO24\n", brown, normal, green, normal);
    printf("   GPIO10 %so%s %so%s GND\n",    pink, normal, black, normal);
    printf("   GPIO09 %so%s %so%s GPIO25\n", pink, normal, green, normal);
    printf("   GPIO11 %so%s %so%s GPIO08\n", pink, normal, pink, normal);
    printf("      GND %so%s %so%s GPIO07\n", black, normal, pink, normal);
    printf("    ID_SD %so%s %so%s ID_SC\n",  yellow, normal, yellow, normal);
    printf("   GPIO05 %so%s %so%s GND\n",    green, normal, black, normal);
    printf("   GPIO06 %so%s %so%s GPIO12\n", green, normal, green, normal);
    printf("   GPIO13 %so%s %so%s GND\n",    green, normal, black, normal);
    printf("   GPIO19 %so%s %so%s GPIO16\n", green, normal, green, normal);
    printf("   GPIO26 %so%s %so%s GPIO20\n", green, normal, green, normal);
    printf("      GND %so%s %so%s GPIO21\n", black, normal, green, normal);
}

int main(
        int argc,
        char *argv[])
{
    PipConfigParser config;
    PipString       theConfigString;

    theConfigString =
"[gpio14]\n"
"  type = 'relay'\n"
"";

    config.parse(theConfigString);

    printHeader();

#if 0
    if (gpioInitialise() < 0)
    {
        PIP_WARNING(stderr, "pigpio initialisation failed");
        return 1;
    }
#endif

    PIP_DEBUG("Start");
#if 1
    //gpioSetMode(22, PI_OUTPUT);
    PipRelay relay(14);
    relay.on();
    sleep(1);
    relay.off();
#endif

#if 0
    int pin = 4;

    //gpioSetMode(pin, PI_OUTPUT);
    gpioSetPullUpDown(pin, PI_PUD_UP);

    gpioSetAlertFunc(pin, gpio_callback);

    while (true)
    {
        gpioSetMode(pin, PI_OUTPUT);
        gpioWrite(pin, 0);
        gpioDelay(18 * 1000);
        
        gpioSetMode(pin, PI_INPUT);
        watch = true;

        gpioDelay(180 * 1000);
    }
#endif

    return 0;
}

