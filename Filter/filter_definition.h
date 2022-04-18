#pragma once

#include "vector"
#include "string"

struct FilterDefinition {
    std::string name;
    std::vector<std::string> params;
};
