#include "negative.h"

void Negative::ApplyFilter(Image& image) {
    for (size_t x = 0; x < image.Height(); ++x) {
        for (size_t y = 0; y < image.Width(); ++y) {
            uint8_t red_col = 255 - image.GetPixel(x, y).red;
            uint8_t green_col = 255 - image.GetPixel(x, y).green;
            uint8_t blue_col = 255 - image.GetPixel(x, y).blue;
            image.GetPixel(x, y) = {red_col, green_col, blue_col};
        }
    }
}
