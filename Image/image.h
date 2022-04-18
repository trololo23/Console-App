#pragma once

#include <fstream>
#include <vector>

#pragma pack(push, 1)
struct Pixel {
    uint8_t red{0};
    uint8_t green{0};
    uint8_t blue{0};
};

#pragma pack(pop)

class Image {
public:
    size_t& Height();

    size_t& Width();

    Pixel& GetPixel(int32_t x, int32_t y);

    std::vector<Pixel>& operator[](size_t x);

    std::vector<std::vector<Pixel>>& GetData();

private:
    std::vector<std::vector<Pixel>> pixel_data_;
    size_t width_;
    size_t height_;
};
