//#include "../../../contrib/catch/catch.hpp"
//#include "filtr_factory.h"
//#include "../Warnings/warnings.h"
//
//TEST_CASE("Factory_Test_1") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"some_str", "1000"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_2") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"1000", "some_str"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_3") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"some_str", "some_str"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_4") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"1000", "-1000"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_5") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"-1000", "1000"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_6") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"-1000", "-1000"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_7") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"1000", "1000"};
//    REQUIRE_NOTHROW(factory.CreateFilter(filter_name, filter_params));
//}
//
//TEST_CASE("Factory_Test_8") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"1000,5", "1000"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_9") {
//    FilterFactory factory;
//    std::string filter_name = "-crop";
//    std::vector<std::string> filter_params{"1000", "1000,5"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_10") {
//    FilterFactory factory;
//    std::string filter_name = "-blur";
//    std::vector<std::string> filter_params{"some_str"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_11") {
//    FilterFactory factory;
//    std::string filter_name = "-blur";
//    std::vector<std::string> filter_params{"-3"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_12") {
//    FilterFactory factory;
//    std::string filter_name = "-blur";
//    std::vector<std::string> filter_params{"5"};
//    REQUIRE_NOTHROW(factory.CreateFilter(filter_name, filter_params));
//}
//
//TEST_CASE("Factory_Test_13") {
//    FilterFactory factory;
//    std::string filter_name = "-edge";
//    std::vector<std::string> filter_params{"some_str"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_14") {
//    FilterFactory factory;
//    std::string filter_name = "-edge";
//    std::vector<std::string> filter_params{"-15"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_15") {
//    FilterFactory factory;
//    std::string filter_name = "-edge";
//    std::vector<std::string> filter_params{"15"};
//    REQUIRE_NOTHROW(factory.CreateFilter(filter_name, filter_params));
//}
//
//TEST_CASE("Factory_Test_16") {
//    FilterFactory factory;
//    std::string filter_name = "-pxl";
//    std::vector<std::string> filter_params{"some_str"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_17") {
//    FilterFactory factory;
//    std::string filter_name = "-pxl";
//    std::vector<std::string> filter_params{"-15"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
//
//TEST_CASE("Factory_Test_18") {
//    FilterFactory factory;
//    std::string filter_name = "-pxl";
//    std::vector<std::string> filter_params{"15"};
//    REQUIRE_NOTHROW(factory.CreateFilter(filter_name, filter_params));
//}
//
//TEST_CASE("Factory_Test_19") {
//    FilterFactory factory;
//    std::string filter_name = "-pxl";
//    std::vector<std::string> filter_params{"15,5"};
//    REQUIRE_THROWS_AS(factory.CreateFilter(filter_name, filter_params), WrongFormatArgs);
//}
