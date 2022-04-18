#include "bmp_structure.h"


void BMP::Write(const std::string& out_file_name) {

    file_info_header_.size_image = image_.Height() * image_.Width() * 3;
    file_header_.file_size = file_info_header_.size_image + file_header_.offset; // ещё с не кратными 4 сделать
    file_info_header_.width = image_.Width();
    file_info_header_.height = image_.Height();

    std::ofstream output(out_file_name, std::ios_base::binary);
    output.write(reinterpret_cast<char*>(&file_header_), sizeof(file_header_));

    output.write(reinterpret_cast<char*>(&file_info_header_), sizeof(file_info_header_));

    int32_t bytes_in_row = file_info_header_.width * 3;

    if (bytes_in_row % 4 == 0) {
        for (size_t i = 0; i < file_info_header_.height; ++i) {
            output.write(reinterpret_cast<char*>(image_[i].data()), bytes_in_row);
        }
    } else {
        auto bytes_in_file_row = bytes_in_row;
        while (bytes_in_file_row % 4 != 0) {
            ++bytes_in_file_row;
        }
        auto remind = bytes_in_file_row - bytes_in_row;
        std::vector<uint8_t> buffer(remind);
        for (size_t i = 0; i < file_info_header_.height; ++i) {
            output.write(reinterpret_cast<char*>(image_[i].data()), bytes_in_row);
            output.write(reinterpret_cast<char*>(buffer.data()), remind);
        }
    }

}
