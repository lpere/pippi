#include "ut_pipvariant.h"

#include <limits.h>

#include "PipVariant"
#include "PipVariantMap"

//#define DEBUG
#define WARNING
#include "pipdebug.h"

UtPipVariant::UtPipVariant()
{
    PIP_DEBUG("");
}

UtPipVariant::~UtPipVariant()
{
}

bool
UtPipVariant::runTest(const char *testName)
{
    bool retval = true;
    PERFORM_TEST(testCreate,         retval);

    return retval;
}

bool
UtPipVariant::testCreate()
{
#if 0
    PipVariant   invalidVariant;
    PipVariant   integerVariant(42);
    PipVariant   stringVariant("42");

    PIP_VERIFY(invalidVariant.isInvalid());

    PIP_VERIFY(!integerVariant.isInvalid());
    PIP_VERIFY(integerVariant.isInteger());
    PIP_COMPARE(integerVariant.toInt(), 42);
    
    PIP_VERIFY(!stringVariant.isInvalid());
    PIP_VERIFY(!stringVariant.isInteger());
    PIP_VERIFY(stringVariant.isString());
#endif
    return true;
}

PIP_UNIT_TEST_MAIN(UtPipVariant)


