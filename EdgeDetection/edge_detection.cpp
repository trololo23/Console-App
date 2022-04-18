#include "edge_detection.h"

void EdgeDetection::ApplyFilter(Image& image) {
    Grayscale filtr;
    filtr.ApplyFilter(image);
    ApplyMatrix({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}}, image);
    for (size_t x = 0; x < image.Height(); ++x) {
        for (size_t y = 0; y < image.Width(); ++y) {
            if (image.GetPixel(x, y).red > threshold_) {
                image.GetPixel(x, y) = {255, 255, 255};
            } else {
                image.GetPixel(x, y) = {0, 0, 0};
            }
        }
    }
}
