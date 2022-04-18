#pragma once

#include "../Filter/filter_definition.h"
#include "fstream"
#include "unordered_map"

struct ParserResults {
    std::string input_file_path;
    std::string output_file_path;

    std::vector<FilterDefinition> filter_definitions;
};

class Parser {
public:
    ParserResults Parse(const int argc, const char *argv[]);
private:
    std::unordered_map<std::string, int> args_count_{{"-crop", 2},{"-gs", 0}, {"-neg", 0},
                                                       {"-sharp", 0}, {"-edge", 1}, {"-blur", 1},
                                                       {"-pxl", 1}, {"-rnd", 2}};
};
