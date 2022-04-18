#include "sharpening.h"

void Sharpening::ApplyFilter(Image& image) {
    ApplyMatrix({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}}, image);
}
