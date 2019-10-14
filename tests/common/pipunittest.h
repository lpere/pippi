#pragma once

#include <stdio.h>

#include <PipString>
#include <PipMap>
//#include <PipOutput>
#include <PipException>

#define PIP_UNIT_TEST_MAIN(classname) \
int main (int argc, char *argv[]) \
{\
    classname object; \
    int retval = object.execute(argc, argv); \
    return retval;\
}

#define PIP_COMPARE(actual,required) \
    { \
        if (!compare(__FILE__, __LINE__, #actual, required, actual)) \
            return false; \
    }

#define PIP_VERIFY(value) \
    PIP_COMPARE(value, true)

#define PERFORM_TEST(functionName,resultvariable) \
{ \
    m_errorString.clear(); \
    if (m_argvElements.empty() || m_argvElements.contains(#functionName)) \
    { \
        setRunningTestName(#functionName); \
        if (haveTerminal()) \
            printf ("  %-24s: RUNNING ", #functionName); \
        fflush(stdout); \
        try { \
            if (!functionName()) { \
                testFunctionEnded(false); \
                failed(); \
                resultvariable = false; \
                resetCounters(); \
            } else { \
                testFunctionEnded(true); \
                resetCounters(); \
                fflush(stdout); \
            } \
            setRunningTestName(""); \
        }\
        catch (const PipException error) \
        { \
            error.printMessage(); \
            testFunctionEnded(false); \
            failed(); \
            resultvariable = false; \
            resetCounters(); \
        }\
    } \
}

/**
 * Base class for all the unit tests with various helper functions and macros.
 */
class PipUnitTest
{
    public:
        PipUnitTest();
        virtual ~PipUnitTest();
      
        bool  isVerbose() const;

        int execute(int argc, char *argv[]);

        void failed();
        int failedCounter() const;

        int nChecks() const;
        void resetCounters();
        bool haveTerminal();

        virtual void printHelp();
        virtual void printHelpAndExit (int exitCode);

        PipString testName() const;
        void setTestName(const PipString &name);
        PipString testCase() const;
        void setTestCase(const PipString &name);
        bool prepareToRun();
        bool finalizeRun();
        void setRunningTestName(const PipString name);
        time_t testFunctionStartTime() const;
        void message(const char *formatString, ...);
        void incrementChecks();
        void testFunctionEnded(bool success);

        virtual bool runTest(const char *testName = NULL);
        
        bool compare (
                const char *fileName,
                const int   lineNumber,
                const char *varName,
                const int   value1,
                const int   value2);
        
        bool compare (
                const char *fileName,
                const int   lineNumber,
                const char *varName,
                size_t      value1,
                size_t      value2);

        bool compare (
                const char *fileName,
                const int   lineNumber,
                const char *varName,
                bool        value1,
                bool        value2);

        bool compare (
                const char *fileName,
                const int   lineNumber,
                const char *varName,
                const std::string value1,
                const std::string value2);

        bool compare (
                const char *fileName,
                const int   lineNumber,
                const char *varName,
                const double      value1,
                const double      value2);

        bool compare (
                const char *fileName,
                const int   lineNumber,
                const char *varName,
                const unsigned long long value1,
                const unsigned long long value2);

    protected:
        PipString               m_errorString;
        PipString               m_argv0;
        PipMap<PipString, bool> m_argvElements;
        //PipOutput               m_output;

    private:
        PipString   m_testName;
        PipString   m_commandLine;
        bool        m_verbose;
        bool        m_isLoop;
        int         m_untilMinutes;
        char       *m_basename;
        int         m_failedCounter;
        int         m_nChecks;
        PipString   m_runningTestName;
        time_t      m_testFunctionStartTime;
        PipString   m_testCase;
        bool        m_updateExamples;
        bool        m_noHalt;
};



