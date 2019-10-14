#pragma once

#include "pipunittest.h"

class UtPipVariant : public PipUnitTest
{
    public:
        UtPipVariant();
        virtual ~UtPipVariant();
        virtual bool runTest(const char *testName = 0);

    protected:
        bool testCreate();
};

