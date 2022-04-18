#pragma once

#include "../Filter/filtr_interface.h"

class Sharpening: public Filter{
public:
    Sharpening() {};

    void ApplyFilter(Image& image) override;
};
