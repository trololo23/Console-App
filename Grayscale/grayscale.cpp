#include "grayscale.h"
#include "iostream"

void Grayscale::ApplyFilter(Image& image) {
    const double r_coef = 0.299;
    const double g_coef = 0.587;
    const double b_coef = 0.114;
    for (size_t x = 0; x < image.Height(); ++x) {
        for (size_t y = 0; y < image.Width(); ++y) {
            uint8_t color = r_coef * image.GetPixel(x, y).red + g_coef * image.GetPixel(x, y).green +
                    b_coef * image.GetPixel(x, y).blue;
            image.GetPixel(x, y) = {color, color, color};
        }
    }
}