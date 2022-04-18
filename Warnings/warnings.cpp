#include "warnings.h"

FileOpenFailedException::FileOpenFailedException(const std::string& path)
    : message_(std::string("failed to open file: ") + path + " ") {
}

const char *FileOpenFailedException::what() const noexcept {
    return message_.c_str();
}

NotEnoughFilterArgumentsException::NotEnoughFilterArgumentsException(int argc, const std::string &name, int required) {
    message_ = "Not enough " + std::to_string(argc) + " arguments for " + name +
               ".\n"
               "Must be " +
               std::to_string(required) + " arguments ";
}

const char *NotEnoughFilterArgumentsException::what() const noexcept {
    return message_.c_str();
}

WrongFormatArgs::WrongFormatArgs(const std::string &name) {
    message_ = "Wrong format args for filter " + name + " ";
}

const char *WrongFormatArgs::what() const noexcept {
    return message_.c_str();
}

const char *Help::what() const noexcept {
    return message_.c_str();
}

WrongFileFormat::WrongFileFormat(const std::string &text) {
    message_ = text;
}

const char *WrongFileFormat::what() const noexcept {
    return message_.c_str();
}