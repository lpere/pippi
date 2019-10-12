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

    m_lineNumber = 1;
    m_parseError = false;
    retval = parse(input, location);

    PIP_DEBUG("*** retval = %s", STR_BOOL(retval));
    return retval;
}
        
bool 
PipConfigParser::parse(
        const PipString &input,
        size_t          &location)
{
    for (;;)
    {
        size_t oldLocation = location;

        parseWhiteSpace(input, location);

        if (parseEof(input, location))
        {
            PIP_DEBUG("End of configuration found.");
            return true;
        }

        if (!parseSectionName(input, location))
            parseConfigItem(input, location);

        if (location == oldLocation)
        {
            PIP_WARNING("Error in line %d: the parser stuck.", m_lineNumber);
            return false;
        }
    }
    
    return true;
}

bool 
PipConfigParser::parseWhiteSpace(
        const PipString &input,
        size_t          &location)
{
    for (;;)
    {
        char c = input[location];

        if (c == '\n')
        {
            ++m_lineNumber;
            ++location;
            continue;
        } else if (c == ' ' || c == '\t')
        {
            ++location;
            continue;
        }

        break;
    }

    return true;
}

bool
PipConfigParser::parseEof(
        const PipString &input,
        size_t          &location)
{
    if (input[location] == '\0')
        return true;

    return false;
}


bool 
PipConfigParser::parseConfigItem(
        const PipString &input,
        size_t          &location)
{
    if (parseSectionName(input, location))
        return true;

    if (parseAssignment(input, location))
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

bool 
PipConfigParser::parseAssignment(
        const PipString &input,
        size_t          &location)
{
    if (!parseKey(input, location))
        return false;

    if (!parseAssignmentOperator(input, location))
    {
        PIP_WARNING("Error in line %d: '=' expected.", m_lineNumber);
        m_parseError = true;
        return false;
    }
    
    if (!parseValue(input, location))
    {
        PIP_WARNING(
                "Error in line %d: configuration value expected.", 
                m_lineNumber);

        m_parseError = true;
        return false;
    }

    return true;
}

bool 
PipConfigParser::parseValue(
        const PipString &input,
        size_t          &location)
{
    parseWhiteSpace(input, location);

    if (input[location] == '\'')
        return parseSingleQuotedString(input, location);

    return false;
}

bool 
PipConfigParser::parseSingleQuotedString(
        const PipString &input,
        size_t          &location)
{
    PipString value;
    if (input[location] == '\'')
    {
        ++location;

        for (;;)
        {
            if (input[location] == '\'')
            {
                ++location;
                PIP_DEBUG("Single quoted string '%s' parsed.", STR(value));
                return true;
            }

            value += input[location];
            ++location;
        }
    }

    return false;
}

bool 
PipConfigParser::parseKey(
        const PipString &input,
        size_t          &location)
{
    PipString key;

    parseWhiteSpace(input, location);

    for (;;)
    {
        char c = input[location];

        if (c == ' ' || c == '\t')
        {
            PIP_DEBUG("Key '%s' parsed.", STR(key));
            return true;
        }

        key += c;
        ++location;
    }

    return true;
}

bool 
PipConfigParser::parseAssignmentOperator(
        const PipString &input,
        size_t          &location)
{
    parseWhiteSpace(input, location);
    if (input[location] == '=')
    {
        PIP_DEBUG("Assignment operator parsed.");
        ++location;
        return true;
    }

    return false;
}
