#include "bmp_structure.h"
#include "../Warnings/warnings.h"

void BMP::Read(const std::string& in_file_name) {
    std::ifstream input(in_file_name, std::ios_base::binary);
    if (!input.good()) {
        throw FileOpenFailedException(in_file_name);
    }

    input.read(reinterpret_cast<char*>(&file_header_), sizeof(file_header_));

    if (file_header_.type != 0x4D42) {
        throw WrongFileFormat("File is not BMP-format ");
    }

    input.read(reinterpret_cast<char*>(&file_info_header_), sizeof(file_info_header_));

    if (file_info_header_.header_size != 40) {
        throw WrongFileFormat("Incorrect info header ");
    } else if (file_header_.offset - file_info_header_.header_size != 14) {
        throw WrongFileFormat("Incorrect header ");
    } else if (file_info_header_.bits_numb != 24) {
        throw WrongFileFormat("Not 24-BMP file ");
    } else if (file_info_header_.compression != 0) {
        throw WrongFileFormat("Expected image without compression ");
    }

    image_.Height() = file_info_header_.height;
    image_.Width() = file_info_header_.width;
    image_.GetData().resize(image_.Height(), std::vector<Pixel>(image_.Width()));

    auto bytes_in_row = image_.Width() * 3;
    if (bytes_in_row % 4  == 0) {
        for (size_t i = 0; i < image_.Height(); ++i) {
            input.read(reinterpret_cast<char*>(image_[i].data()), bytes_in_row);
        }
    } else {
        auto bytes_in_file_row = bytes_in_row;
        while (bytes_in_file_row % 4 != 0) {
            ++bytes_in_file_row;
        }
        auto remind = bytes_in_file_row - bytes_in_row;
        std::vector<uint8_t> buffer(remind);
        for (size_t i = 0; i < file_info_header_.height; ++i) {
            input.read(reinterpret_cast<char*>(image_[i].data()), bytes_in_row);
            input.read(reinterpret_cast<char*>(buffer.data()), remind);
        }
    }

}
