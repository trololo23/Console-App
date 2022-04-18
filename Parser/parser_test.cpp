#include "../../../contrib/catch/catch.hpp"
#include "parser.h"
#include "../Warnings/warnings.h"
#include "exception"

TEST_CASE("Parser_Test_1") {
    Parser parser;
    const int argc = 1;
    const char* argv[] = {"./image_processor"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), Help);
}

TEST_CASE("Parser_Test_2") {
    Parser parser;
    const int argc = 2;
    const char* argv[] = {"./image_processor", "not_existing_directory"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), std::invalid_argument);
}

TEST_CASE("Parser_Test_3") {
    Parser parser;
    const int argc = 3;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp"};
    ParserResults results{.input_file_path = "../example/example.bmp", .output_file_path = "../examples/res.bmp"};
    REQUIRE_NOTHROW(parser.Parse(argc, argv));
}

TEST_CASE("Parser_Test_4") {
    Parser parser;
    const int argc = 4;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "blur"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), std::invalid_argument);
}

TEST_CASE("Parser_Test_5") {
    Parser parser;
    const int argc = 4;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-blur"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), NotEnoughFilterArgumentsException);
}

TEST_CASE("Parser_Test_6") {
    Parser parser;
    const int argc = 5;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-crop", "1000"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), NotEnoughFilterArgumentsException);
}

TEST_CASE("Parser_Test_7") {
    Parser parser;
    const int argc = 6;
    const char* argv[] = {
        "./image_processor", "../example/example.bmp", "../examples/res.bmp", "-crop", "1000", "1000"};
    REQUIRE_NOTHROW(parser.Parse(argc, argv));
}

TEST_CASE("Parser_Test_8") {
    Parser parser;
    const int argc = 5;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-crop", "-pxl"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), NotEnoughFilterArgumentsException);
}

TEST_CASE("Parser_Test_9") {
    Parser parser;
    const int argc = 6;
    const char* argv[] = {
        "./image_processor", "../example/example.bmp", "../examples/res.bmp", "-crop", "1000", "-pxl"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), NotEnoughFilterArgumentsException);
}

TEST_CASE("Parser_Test_10") {
    Parser parser;
    const int argc = 7;
    const char* argv[] = {
        "./image_processor", "../example/example.bmp", "../examples/res.bmp", "-crop", "1000", "1000", "-gs"};
    REQUIRE_NOTHROW(parser.Parse(argc, argv));
}

TEST_CASE("Parser_Test_11") {
    Parser parser;
    const int argc = 4;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-sharp", "-gs"};
    REQUIRE_NOTHROW(parser.Parse(argc, argv));
}

TEST_CASE("Parser_Test_12") {
    Parser parser;
    const int argc = 5;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-edge", "-gs"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), NotEnoughFilterArgumentsException);
}

TEST_CASE("Parser_Test_13") {
    Parser parser;
    const int argc = 6;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-sharp", "-gs", "-neg"};
    REQUIRE_NOTHROW(parser.Parse(argc, argv));
}

TEST_CASE("Parser_Test_14") {
    Parser parser;
    const int argc = 6;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-sharp", "-edge", "-neg"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), NotEnoughFilterArgumentsException);
}

TEST_CASE("Parser_Test_15") {
    Parser parser;
    const int argc = 6;
    const char* argv[] = {"./image_processor", "../example/example.bmp", "../examples/res.bmp", "-sharp", "invalid_name", "-crop"};
    REQUIRE_THROWS_AS(parser.Parse(argc, argv), std::invalid_argument);
}
