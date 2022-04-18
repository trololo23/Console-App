#include "pixellate.h"
#include "iostream"

void Pixellate::ApplyFilter(Image &image) {
    size_t x_range = int((image.Width() - 1) / pixel_size_) + 1;
    size_t y_range = int((image.Height() - 1) /  pixel_size_) + 1;
    for (size_t x = 1; x <= x_range; ++x) {
        for (size_t y = 1; y <= y_range; ++y) {
            size_t left_b = (x - 1) * pixel_size_;
            size_t right_b = std::min(image.Width(), x * pixel_size_);
            size_t bottom_b = (y - 1) * pixel_size_;
            size_t up_b = std::min(image.Height(), y * pixel_size_);
            double aver_r = 0;
            double aver_g = 0;
            double aver_b = 0;
            for (size_t i = bottom_b; i < up_b; ++i) {
                for (size_t j = left_b; j < right_b; ++j) {
                    aver_r += image.GetPixel(i, j).red;
                    aver_g += image.GetPixel(i, j).green;
                    aver_b += image.GetPixel(i, j).blue;
                }
            }
            size_t rect_sq = (right_b - left_b) * (up_b - bottom_b);
            aver_r /= rect_sq;
            aver_g /= rect_sq;
            aver_b /= rect_sq;
            for (size_t i = bottom_b; i < up_b; ++i) {
                for (size_t j = left_b; j < right_b; ++j) {
                    image.GetPixel(i, j).red = aver_r;
                    image.GetPixel(i, j).green = aver_g;
                    image.GetPixel(i, j).blue = aver_b;
                }
            }
        }
    }
}
