#include "random_filter.h"

RandomFilter::RandomFilter(int shuffle, int pix_numb): shuffle_(shuffle), pix_numb_(pix_numb) {}

void RandomFilter::ApplyFilter(Image &image) {
    for (size_t x = 0; x < image.Height(); ++x) {
        for (size_t y = 0; y < image.Width(); ++y) {
            int left = std::max(0, static_cast<int>(y - shuffle_));
            int right = std::min(image.Width() - 1, y + shuffle_);
            int bottom = std::max(0, static_cast<int>(x - shuffle_));
            int up = std::min(image.Height() - 1, x + shuffle_);

            int width = right - left;
            int height = up - bottom;

            std::vector<std::pair<int, int>> cells(width * height);
            for (int i = left; i <= right; ++i) {
                for (int j = bottom; j <= up; ++j) {
                    cells.push_back({j, i});
                }
            }

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<size_t> dist(0, width * height - 1);

            std::shuffle(cells.begin(), cells.end(), gen);

            double aver_r = 0;
            double aver_g = 0;
            double aver_b = 0;

            for (int i = 0; i < pix_numb_; ++i) {
                aver_r += image.GetPixel(cells[i].first, cells[i].second).red;
                aver_g += image.GetPixel(cells[i].first, cells[i].second).green;
                aver_b += image.GetPixel(cells[i].first, cells[i].second).blue;
            }

            aver_r /= pix_numb_;
            aver_g /= pix_numb_;
            aver_b /= pix_numb_;

            image.GetPixel(x, y).red = int(aver_r);
            image.GetPixel(x, y).green = int(aver_g);
            image.GetPixel(x, y).blue = int(aver_b);
        }
    }
}
