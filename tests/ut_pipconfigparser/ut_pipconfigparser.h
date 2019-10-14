#pragma once

#include "pipunittest.h"

class UtPipConfigParser : public PipUnitTest
{
    public:
        UtPipConfigParser();
        virtual ~UtPipConfigParser();
        virtual bool runTest(const char *testName = 0);

    protected:
        bool testCreate();
        bool testParseNoSection();
        bool testParseSimple();
};

