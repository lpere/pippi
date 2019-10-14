#include "pipconfigparser.h"

//#define DEBUG
//#define WARNING
#include "pipdebug.h"


PipConfigParser::PipConfigParser() :
    PipObject("PipConfigParser")
{
}

PipConfigParser::~PipConfigParser()
{
}

/**
 * \returns A "sectionless" value from the configuration by its key (name).
 */
PipVariant
PipConfigParser::configValue(
        const PipString &key) const
{
    if (m_valuesNoSection.contains(key))
        return m_valuesNoSection.at(key);

    return PipVariant();
}

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
    PipString sectionName;

    for (;;)
    {
        size_t     oldLocation = location;
        PipString  key;
        PipVariant value;

        parseWhiteSpace(input, location);

        if (parseEof(input, location))
        {
            PIP_DEBUG("End of configuration found.");
            return true;
        }

        if (parseSectionName(input, location, sectionName))
            continue;

        if (parseAssignment(input, location, key, value))
            m_valuesNoSection[key] = value;

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
PipConfigParser::parseSectionName(
        const PipString &input,
        size_t          &location,
        PipString       &sectionName)
{
    if (input[location] == '[')
    {
        PipString mySectionName;

        for (;;)
        {
            
            ++location;
            if (input[location] == ']')
            {
                sectionName = mySectionName;
                PIP_DEBUG("Parsed section name '%s'.", STR(sectionName));
                ++location;
                return true;
            }

            mySectionName += input[location];
        }
    }

    return false;
}

bool 
PipConfigParser::parseAssignment(
        const PipString &input,
        size_t          &location,
        PipString       &key,
        PipVariant      &value)
{
    PipString  myKey;
    PipVariant myValue;

    // First there is a key, a name.
    if (!parseKey(input, location, myKey))
        return false;

    // Then the assignment operator.
    if (!parseAssignmentOperator(input, location))
    {
        PIP_WARNING("Error in line %d: '=' expected.", m_lineNumber);
        m_parseError = true;
        return false;
    }
    
    // Then a value.
    if (!parseValue(input, location, myValue))
    {
        PIP_WARNING(
                "Error in line %d: configuration value expected.", 
                m_lineNumber);

        m_parseError = true;
        return false;
    }

    key = myKey;
    value = myValue;
    return true;
}

bool 
PipConfigParser::parseValue(
        const PipString &input,
        size_t          &location,
        PipVariant      &value)
{
    parseWhiteSpace(input, location);

    if (input[location] == '\'')
        return parseSingleQuotedString(input, location, value);

    return false;
}

bool 
PipConfigParser::parseSingleQuotedString(
        const PipString &input,
        size_t          &location,
        PipVariant      &value)
{
    PipString valueString;

    if (input[location] == '\'')
    {
        ++location;

        for (;;)
        {
            if (input[location] == '\'')
            {
                ++location;
                value = valueString;

                PIP_DEBUG(
                        "Single quoted string '%s' parsed.", 
                        STR(valueString));

                return true;
            }

            valueString += input[location];
            ++location;
        }
    }

    return false;
}

/**
 * 
 */
bool 
PipConfigParser::parseKey(
        const PipString &input,
        size_t          &location,
        PipString       &key)
{
    PipString myKey;

    parseWhiteSpace(input, location);

    for (;;)
    {
        char c = input[location];

        if (c == ' ' || c == '\t')
        {
            key = myKey;
            PIP_DEBUG("Key '%s' parsed.", STR(key));
            return true;
        }

        myKey += c;
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
