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

};

