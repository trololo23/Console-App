#include "parser.h"
#include "../Warnings/warnings.h"

ParserResults Parser::Parse(const int argc, const char *argv[]) {
    ParserResults result;

    const std::string filters_list = " -crop, -gs, -neg, -sharp, -edge, -blur, -pxl ";
    if (argc == 1) {
        throw Help();
    } else if (argc == 2) {
        throw std::invalid_argument("The output file direction is missing ");
    }
    result.input_file_path = argv[1];
    result.output_file_path = argv[2];

    if (argc > 3) {
        int it = 3;
        std::vector<std::string> args{};
        while (it < argc) {
            std::string filtr_name = argv[it];
            if (!args_count_.contains(filtr_name)) {
                throw std::invalid_argument("The filter with the name " + filtr_name +
                                         " doesn't exist \n"
                                         "Available filters:" +
                                         filters_list);
            }

            int numb = args_count_[filtr_name];
            if (it + numb >= argc) {
                throw NotEnoughFilterArgumentsException(argc - it - 1, filtr_name, numb);
            }

            if (numb == 2) {
                if (args_count_.contains(argv[it + 1])) {
                    throw NotEnoughFilterArgumentsException(0, filtr_name, numb);
                } else if (args_count_.contains(argv[it + 2])) {
                    throw NotEnoughFilterArgumentsException(1 , filtr_name, numb);
                }
                args.push_back(argv[it + 1]);
                args.push_back(argv[it + 2]);
            } else if (numb == 1) {
                if (args_count_.contains(argv[it + 1])) {
                    throw NotEnoughFilterArgumentsException(0, filtr_name, numb);
                }
                args.push_back(argv[it + 1]);
            }

            it += numb + 1;

            result.filter_definitions.push_back({filtr_name, args});
            args.clear();
        }
    }
    return result;
}
