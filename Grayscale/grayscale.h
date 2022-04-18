#pragma once

#include "../Filter/filtr_interface.h"

class Grayscale: public Filter{
public:
    Grayscale() {};

    void ApplyFilter(Image& image) override;
};
