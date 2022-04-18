#pragma once

#include "../Filter/filtr_interface.h"
#include "../Grayscale/grayscale.h"

class EdgeDetection: public Filter{
public:
    EdgeDetection(int32_t threshold): threshold_(threshold) {};

    void ApplyFilter(Image& image) override;

private:
    int32_t threshold_;
};
