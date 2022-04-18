#include "Filter/filtr_factory.h"
#include "Parser/parser.h"
#include "iostream"

int main(int argc, const char *argv[]) {
    Parser parser;
    FilterFactory factory;
    BMP picture;
    try {
        ParserResults parser_results = parser.Parse(argc, argv);

        picture.Read(parser_results.input_file_path);

        std::vector<std::shared_ptr<Filter>> apply_filters = factory.CreateFilters(parser_results.filter_definitions);

        for (auto filter_ptr: apply_filters) {
            filter_ptr->ApplyFilter(picture.GetImage());
        }

        picture.Write(parser_results.output_file_path);

    } catch (const std::exception& e) {
        std::cerr << e.what();
        exit(0);
    }

    return 0;
}
