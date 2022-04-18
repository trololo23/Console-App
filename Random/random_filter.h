#pragma once

#include <random>
#include "../Filter/filtr_interface.h"

class RandomFilter: public Filter{
public:
    RandomFilter(int shuffle, int pix_numb);

    void ApplyFilter(Image &image) override;

private:
    int shuffle_;
    int pix_numb_;
};
