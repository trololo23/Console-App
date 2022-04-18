cmake_minimum_required(VERSION 3.16)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
    image_processor.cpp BmpStructure/write.cpp "Filter/filtr_interface.cpp" Crop/crop.cpp
        BmpStructure/bmp_structure.cpp Grayscale/grayscale.cpp "Negative/negative.cpp" "Sharpening/sharpening.cpp"
        EdgeDetection/edge_detection.cpp BmpStructure/read.cpp Image/image.cpp "Parser/parser.cpp"
        "Filter/filtr_factory.cpp" "Warnings/warnings.cpp" Blur/blur.cpp Pixellate/pixellate.cpp
        "Filter/test_filter_factory.cpp" Random/random_filter.cpp Random/random_filter.h)

#add_catch(test_parser Parser/parser_test.cpp Parser/parser.cpp Warnings/warnings.cpp)

#add_catch(test_factory Filter/test_filter_factory.cpp BmpStructure/write.cpp "Filter/filtr_interface.cpp" Crop/crop.cpp
#        BmpStructure/bmp_structure.cpp Grayscale/grayscale.cpp "Negative/negative.cpp" "Sharpening/sharpening.cpp"
#        EdgeDetection/edge_detection.cpp BmpStructure/read.cpp Image/image.cpp "Parser/parser.cpp"
#        "Filter/filtr_factory.cpp" "Warnings/warnings.cpp" Blur/blur.cpp Pixellate/pixellate.cpp)
