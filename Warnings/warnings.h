#pragma once
#include "exception"
#include "string"

class FileOpenFailedException : public std::exception {
public:
    FileOpenFailedException(const std::string& path);

    const char* what() const noexcept override;

private:
    std::string message_;
};

class NotEnoughFilterArgumentsException : public std::exception {
public:
    NotEnoughFilterArgumentsException(int argc, const std::string& name, int required);

    const char* what() const noexcept override;

private:
    std::string message_;
};

class WrongFormatArgs : public std::exception {
public:
    WrongFormatArgs(const std::string& name);

    const char* what() const noexcept override;
private:
    std::string message_;
};

class Help : public std::exception {
public:

    const char* what() const noexcept override;

private:
    std::string message_ = "The first two launch parameters must be the names of the file to be read and written\n"
                           "Available commands: \n "
                           "1. To apply Crop filter: -crop width(arg_1) height(arg_2) \n"
                           "2. To apply Grayscale filter: -gs \n"
                           "3. To apply Negative filter: -neg \n"
                           "4. To apply Sharpening filter: -sharp \n"
                           "5. To apply Edge Detection filter: -edge threshold(arg_1) \n"
                           "6. To apply Gaussian Blur filter: -blur sigma(arg_1) \n"
                           "7. To apply Pixelation filter: -pxl scale(arg_1)";;
};

class WrongFileFormat : public std::exception {
public:
    WrongFileFormat(const std::string& text);

    const char* what() const noexcept override;
private:
    std::string message_;
};
