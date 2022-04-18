#include "crop.h"

void Crop::ApplyFilter(Image& image) {
    image.Width() = std::min(x_cut_, static_cast<int>(image.Width() - 1));
    image.Height() = std::min(y_cut_, static_cast<int>(image.Height() - 1));
    std::reverse(image.GetData().begin(), image.GetData().end());
    image.GetData().resize(image.Height(), std::vector<Pixel>(image.Width()));
    std::reverse(image.GetData().begin(), image.GetData().end());
}

Crop::Crop(size_t x_cut, size_t y_cut): x_cut_(x_cut), y_cut_(y_cut) {}
