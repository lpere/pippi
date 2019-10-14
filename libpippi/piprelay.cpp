#include "piprelay.h"

#ifdef HAVE_PIGPIO
#  include <pigpio.h>
#endif

#define DEBUG
//#define WARNING
#include "pipdebug.h"

PipRelay::PipRelay(
        const int pin) :
    m_pin(pin)
{
}

PipRelay::~PipRelay()
{
}

void
PipRelay::on()
{
#ifdef HAVE_PIGPIO
   gpioSetMode(m_pin, PI_OUTPUT);
   gpioWrite(m_pin, 1); 
#endif
}

void
PipRelay::off()
{
#ifdef HAVE_PIGPIO
   gpioSetMode(m_pin, PI_OUTPUT);
   gpioWrite(m_pin, 0); 
#endif
}
