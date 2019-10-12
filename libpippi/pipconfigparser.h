#pragma once

#include <PipString>

class PipConfigParser
{
    public:
        bool parse(const PipString &input);

    private:
        bool parse(
                const PipString &input,
                size_t          &location);

        bool parseConfigItem(
                const PipString &input,
                size_t          &location);

        bool parseSectionName(
                const PipString &input,
                size_t          &location);

        bool parseWhiteSpace(
                const PipString &input,
                size_t          &location);

        bool parseEof(
                const PipString &input,
                size_t          &location);

        bool parseAssignment(
                const PipString &input,
                size_t          &location);

        bool parseKey(
                const PipString &input,
                size_t          &location);

        bool parseAssignmentOperator(
                const PipString &input,
                size_t          &location);

        bool parseValue(
                const PipString &input,
                size_t          &location);
        
        bool parseSingleQuotedString(
                const PipString &input,
                size_t          &location);

    private:
        int        m_lineNumber;
        bool       m_parseError;
};

