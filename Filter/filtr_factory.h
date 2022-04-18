#pragma once

#include "../BmpStructure/bmp_structure.h"
#include "../Crop/crop.h"
#include "../Grayscale/grayscale.h"
#include "../Negative/negative.h"
#include "../Sharpening/sharpening.h"
#include "../EdgeDetection/edge_detection.h"
#include "memory"
#include "filter_definition.h"
#include "../Blur/blur.h"
#include "../Pixellate/pixellate.h"
#include "unordered_map"
#include "../Random/random_filter.h"


class FilterFactory {
public:
    std::shared_ptr<Filter> CreateFilter(const std::string &filter_name, const std::vector<std::string> &filter_params);

    std::vector<std::shared_ptr<Filter>> CreateFilters(const std::vector<FilterDefinition>& filter_definitions);

private:
    std::unordered_map<std::string, int> args_count_{{"-crop", 2},{"-gs", 0}, {"-neg", 0},
                                                     {"-sharp", 0}, {"-edge", 1}, {"-blur", 1},
                                                     {"-pxl", 1}};
};
