#pragma once

#include "../Filter/filtr_interface.h"

class Crop: public Filter{
public:
    Crop(size_t x_cut, size_t y_cut);

    void ApplyFilter(Image& image) override;

private:
    int32_t x_cut_;
    int32_t y_cut_;
};
