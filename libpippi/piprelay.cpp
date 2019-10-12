#include "piprelay.h"

#include <pigpio.h>

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
   gpioSetMode(m_pin, PI_OUTPUT);
   gpioWrite(m_pin, 1); 
}

void
PipRelay::off()
{
   gpioSetMode(m_pin, PI_OUTPUT);
   gpioWrite(m_pin, 0); 
}
