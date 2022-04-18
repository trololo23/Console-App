#pragma once

#include "../Filter/filtr_interface.h"

class Pixellate: public Filter{
public:
    Pixellate(size_t pixel_size): pixel_size_(pixel_size) {};

    void ApplyFilter(Image &image) override;

private:
    size_t pixel_size_;
};
