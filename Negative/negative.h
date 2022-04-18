#pragma once

#include "../Filter/filtr_interface.h"

class Negative: public Filter{
public:
    Negative() {};

    void ApplyFilter(Image& image) override;

};
