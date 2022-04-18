#pragma once

#include "../Image/image.h"

class Filter {
public:
    virtual void ApplyFilter(Image& image) = 0;

    void ApplyMatrix(const std::vector<std::vector<int>>& matrix, Image& image);
};
