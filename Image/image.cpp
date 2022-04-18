#include "image.h"
#include "iostream"

size_t &Image::Height() {
    return height_;
}

size_t &Image::Width() {
    return width_;
}

Pixel &Image::GetPixel(int32_t x, int32_t y) {
    auto x_1 = std::min(static_cast<int32_t>(height_ - 1), std::max(0, x));
    auto y_1 = std::min(static_cast<int32_t>(width_ - 1), std::max(0, y));
    return pixel_data_[x_1][y_1];
}

std::vector<Pixel> &Image::operator[](size_t x) {
    return pixel_data_[x];
}

std::vector<std::vector<Pixel>> &Image::GetData() {
    return pixel_data_;
}
