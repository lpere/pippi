#pragma once

#include <PipObject>
#include <PipString>

class PipConfigParser : public PipObject
{
    public:
        PipConfigParser();
        virtual ~PipConfigParser();

        PipVariant configValue(const PipString &key) const;

        bool parse(const PipString &input);

    private:
        bool parse(
                const PipString &input,
                size_t          &location);

        bool parseSectionName(
                const PipString &input,
                size_t          &location,
                PipString       &sectionName);

        bool parseWhiteSpace(
                const PipString &input,
                size_t          &location);

        bool parseEof(
                const PipString &input,
                size_t          &location);

        bool parseAssignment(
                const PipString &input,
                size_t          &location,
                PipString       &key,
                PipVariant      &value);

        bool parseKey(
                const PipString &input,
                size_t          &location,
                PipString       &key);

        bool parseAssignmentOperator(
                const PipString &input,
                size_t          &location);

        bool parseValue(
                const PipString &input,
                size_t          &location,
                PipVariant      &value);
        
        bool parseSingleQuotedString(
                const PipString &input,
                size_t          &location,
                PipVariant      &value);

    private:
        int           m_lineNumber;
        bool          m_parseError;
        PipVariantMap m_valuesNoSection;
};

