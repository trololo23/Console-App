#pragma once

#include "../Filter/filtr_interface.h"
#include "cmath"
#include "math.h"
#include "iostream"

class Blur: public Filter{
public:
    Blur(float sigma): sigma_(sigma) {};

    void ApplyFilter(Image &image) override;

    double FormulaCoeff(size_t x, size_t y, size_t x_0, size_t y_0) {
        int dist = (x - x_0) * (x - x_0) + (y - y_0) * (x - x_0);
        double coeff = 1/sqrt(2 * M_PI * sigma_ * sigma_);
        return coeff * exp(-dist/(2 * sigma_ * sigma_));
    }

private:
    float sigma_;
};
