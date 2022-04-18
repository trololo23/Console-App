#include "filtr_interface.h"

void Filter::ApplyMatrix(const std::vector<std::vector<int>> &matrix, Image& image) {
    std::vector<std::vector<Pixel>> new_data(image.Height());
    for (size_t x = 0; x < image.Height(); ++x) {
        for (size_t y = 0; y < image.Width(); ++y) {
            int32_t r_c = 0;
            int32_t g_c = 0;
            int32_t b_c = 0;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    r_c += image.GetPixel(x + j, y + i).red * matrix[i + 1][j + 1];
                    g_c += image.GetPixel(x + j, y + i).green * matrix[i + 1][j + 1];
                    b_c += image.GetPixel(x + j, y + i).blue * matrix[i + 1][j + 1];
                }
            }

            uint8_t r_col = std::min(255, std::max(0, r_c));
            uint8_t g_col = std::min(255, std::max(0, g_c));
            uint8_t b_col = std::min(255, std::max(0, b_c));
            new_data[x].push_back({r_col, g_col, b_col});
        }
    }
    image.GetData() = new_data;
}
