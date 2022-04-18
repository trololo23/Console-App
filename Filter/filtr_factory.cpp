#include "filtr_factory.h"
#include "../Warnings/warnings.h"

bool IsFloat(const std::string& str)
{
    char* ptr;
    strtof(str.c_str(), &ptr);
    return (*ptr) == '\0';
}

std::shared_ptr<Filter>
FilterFactory::CreateFilter(const std::string &filter_name, const std::vector<std::string> &filter_params) {
    size_t numb = args_count_[filter_name];
    if (filter_name == "-crop") {
        int width = 0;
        int height = 0;

        if (std::all_of(filter_params[0].begin(), filter_params[0].end(), ::isdigit)) {
            width = std::stoi(filter_params[0]);
        } else {
            if (args_count_.contains(filter_params[0])) {
                throw NotEnoughFilterArgumentsException(0, filter_name, numb);
            } else {
                throw WrongFormatArgs(filter_name);
            }
        }

        if (std::all_of(filter_params[1].begin(), filter_params[1].end(), ::isdigit)) {
            height = std::stoi(filter_params[1]);
        } else {
            if (args_count_.contains(filter_params[1])) {
                throw NotEnoughFilterArgumentsException(1, filter_name, numb);
            } else {
                throw WrongFormatArgs(filter_name);
            }
        }

        if (width < 0 || height < 0) {
            throw WrongFormatArgs(filter_name);
        }

        return std::make_shared<Crop>(width, height);
    }
    if (filter_name == "-gs") {
        return std::make_shared<Grayscale>();
    }
    if (filter_name == "-neg") {
        return std::make_shared<Negative>();
    }
    if (filter_name == "-sharp") {
        return std::make_shared<Sharpening>();
    }
    if (filter_name == "-edge") {
        int threshold = 0;

        if (IsFloat(filter_params[0])) {
            threshold = std::stoi(filter_params[0]);
        } else {
            if (args_count_.contains(filter_params[0])) {
                throw NotEnoughFilterArgumentsException(0, filter_name, numb);
            } else {
                throw WrongFormatArgs(filter_name);
            }
        }

        if (threshold < 0) {
            throw WrongFormatArgs(filter_name);
        }

        return std::make_shared<EdgeDetection>(threshold);
    }
    if (filter_name == "-blur") {
        float sigma = 0;

        if (IsFloat(filter_params[0])) {
            sigma = std::stoi(filter_params[0]);
        } else {
            if (args_count_.contains(filter_params[0])) {
                throw NotEnoughFilterArgumentsException(0, filter_name, numb);
            } else {
                throw WrongFormatArgs(filter_name);
            }
        }

        if (sigma < 0) {
            throw WrongFormatArgs(filter_name);
        }

        return std::make_shared<Blur>(sigma);
    }
    if (filter_name == "-pxl") {
        int pixel_amount = 0;

        if (std::all_of(filter_params[0].begin(), filter_params[0].end(), ::isdigit)) {
            pixel_amount = std::stoi(filter_params[0]);
        } else {
            if (args_count_.contains(filter_params[0])) {
                throw NotEnoughFilterArgumentsException(0, filter_name, numb);
            } else {
                throw WrongFormatArgs(filter_name);
            }
        }

        if (pixel_amount < 0) {
            throw WrongFormatArgs(filter_name);
        }

        return std::make_shared<Pixellate>(pixel_amount);
    }
    if (filter_name == "-rnd") {
        int shuffle = std::stoi(filter_params[0]);
        int pix_numb = std::stoi(filter_params[1]);

        return std::make_shared<RandomFilter>(shuffle, pix_numb);
    }
    throw std::runtime_error("There is not existing filter");
}

std::vector<std::shared_ptr<Filter>>
FilterFactory::CreateFilters(const std::vector<FilterDefinition> &filter_definitions) {
    std::vector<std::shared_ptr<Filter>> filters;
    filters.reserve(filter_definitions.size());
    for (const auto& definition: filter_definitions) {
        filters.push_back(CreateFilter(definition.name, definition.params));
    }
    return filters;
}
