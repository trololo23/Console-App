#include "blur.h"

#include "iostream"

void Blur::ApplyFilter(Image &image) {
    std::vector<std::vector<Pixel>> vertical_blur(image.Height());
    for (int i = 0; i < static_cast<int>(image.Height()); ++i) {
        for (int j = 0; j < static_cast<int>(image.Width()); ++j) {
            double r_summ = 0;
            double g_summ = 0;
            double b_summ = 0;
            size_t down = std::max(0, i - int(3*sigma_ + 1));
            size_t up = std::min(static_cast<int>(image.Height()) - 1, i + int(3*sigma_ + 1));
            double matrix_summ = 0;
            for (size_t t = down; t <= up; ++t) {
                double coeff = FormulaCoeff(i, j, t, j);
                matrix_summ += coeff;
                r_summ += image.GetPixel(t, j).red * coeff;
                g_summ += image.GetPixel(t, j).green * coeff;
                b_summ += image.GetPixel(t, j).blue * coeff;
            }
            r_summ /= matrix_summ;
            g_summ /= matrix_summ;
            b_summ /= matrix_summ;
            uint8_t r_col = std::min(255, std::max(0, int(r_summ)));
            uint8_t g_col = std::min(255, std::max(0, int(g_summ)));
            uint8_t b_col = std::min(255, std::max(0, int(b_summ)));
            vertical_blur[i].push_back({r_col, g_col, b_col});
        }
    }

    std::vector<std::vector<Pixel>> horizontal_blur(image.Height());

    for (int i = 0; i < static_cast<int>(image.Height()); ++i) {
        for (int j = 0; j < static_cast<int>(image.Width()); ++j) {
            double r_summ = 0;
            double g_summ = 0;
            double b_summ = 0;
            size_t left = std::max(0, j - int(3*sigma_ + 1));
            size_t right = std::min(static_cast<int>(image.Width()) - 1, j + int(3*sigma_ + 1));
            double matrix_summ = 0;
            for (size_t t = left; t <= right; ++t) {
                double coeff = FormulaCoeff(i, j, i, t);
                matrix_summ += coeff;
                r_summ += vertical_blur[i][t].red * coeff;
                g_summ += vertical_blur[i][t].green * coeff;
                b_summ += vertical_blur[i][t].blue * coeff;
            }
            r_summ /= matrix_summ;
            g_summ /= matrix_summ;
            b_summ /= matrix_summ;
            uint8_t r_col = std::min(255, std::max(0, int(r_summ)));
            uint8_t g_col = std::min(255, std::max(0, int(g_summ)));
            uint8_t b_col = std::min(255, std::max(0, int(b_summ)));
            horizontal_blur[i].push_back({r_col, g_col, b_col});
        }
    }

    image.GetData() = horizontal_blur;
}
