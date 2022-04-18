#pragma once
#include "../Image/image.h"
#include "string"

#pragma pack(push, 1)

struct BitMapFileHeader {
    uint16_t type{0x4D42};
    uint32_t file_size{0};
    uint16_t res1{0};
    uint16_t res2{0};
    uint32_t offset{0};
};

struct BitMapInfoHeader {
    uint32_t header_size{0};
    uint32_t width{0};
    uint32_t height{0};
    uint16_t planes{1};
    uint16_t bits_numb{0};
    uint32_t compression{0};
    uint32_t size_image{0};
    int32_t x_pixels_per_meter{0};
    int32_t y_pixels_per_meter{0};
    uint32_t colors_used{0};
    uint32_t colors_important{0};
};

#pragma pack(pop)

class BMP {
public:
    BMP();

    void Read(const std::string& in_file_name);

    void Write(const std::string& out_file_name);

    Image& GetImage();


private:
    BitMapFileHeader file_header_;
    BitMapInfoHeader file_info_header_;
    Image image_;
};
