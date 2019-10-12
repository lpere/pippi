#include "pipconfigparser.h"

#define DEBUG
//#define WARNING
#include "pipdebug.h"

        
bool 
PipConfigParser::parse(
        const PipString &input)
{
    size_t location = 0;
    bool    retval;

    retval = parse(input, location);
    PIP_DEBUG("*** retval = %s", STR_BOOL(retval));
    return retval;
}
        
bool 
PipConfigParser::parse(
        const PipString &input,
        size_t          &location)
{
    if (parseConfigItem(input, location))
        return true;

    return true;
}

bool 
PipConfigParser::parseConfigItem(
        const PipString &input,
        size_t          &location)
{
    if (parseSectionName(input, location))
        return true;

    return true;
}

bool 
PipConfigParser::parseSectionName(
        const PipString &input,
        size_t          &location)
{
    if (input[location] == '[')
    {
        PipString sectionName;

        for (;;)
        {
            
            ++location;
            if (input[location] == ']')
            {
                PIP_DEBUG("Parsed section name '%s'.", STR(sectionName));
                ++location;
                return true;
            }

            sectionName += input[location];
        }
    }

    return false;
}

