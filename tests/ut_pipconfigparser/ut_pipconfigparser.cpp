#include "ut_pipconfigparser.h"

#include <limits.h>

#include "PipConfigParser"

//#define DEBUG
#define WARNING
#include "pipdebug.h"

UtPipConfigParser::UtPipConfigParser()
{
    PIP_DEBUG("");
}

UtPipConfigParser::~UtPipConfigParser()
{
}

bool
UtPipConfigParser::runTest(
        const char *testName)
{
    bool retval = true;
    PERFORM_TEST(testCreate,         retval);
    PERFORM_TEST(testParseNoSection, retval);
    PERFORM_TEST(testParseSimple,    retval);

    return retval;
}

bool
UtPipConfigParser::testCreate()
{
    return true;
}

bool
UtPipConfigParser::testParseNoSection()
{
    PipConfigParser parser;
    PipString       input = 
"key1 = 'value1'\n"
"key2 = 'value2'\n";

    PIP_VERIFY(parser.parse(input));
    PIP_COMPARE(parser.configValue("key1").toString(), "value1");
    PIP_COMPARE(parser.configValue("key2").toString(), "value2");
    return true;
}

bool
UtPipConfigParser::testParseSimple()
{
    PipConfigParser parser;
    PipString       input = 
"[section]\n"
"  key = 'value'\n";

    PIP_VERIFY(parser.parse(input));

    return true;
}

PIP_UNIT_TEST_MAIN(UtPipConfigParser)



