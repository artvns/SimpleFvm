#include "ExpectedResultDefaultIter2.h"

namespace coeffs_p {

ExpectedResultDefaultIter2::ExpectedResultDefaultIter2() {
    size_t cells_ = 6;

    Aw_.resize(cells_);
    Ae_.resize(cells_);
    An_.resize(cells_);
    As_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter2::getAw(size_t step) {
    return Aw_.at(step);
}

double ExpectedResultDefaultIter2::getAe(size_t step) {
    return Ae_.at(step);
}

double ExpectedResultDefaultIter2::getAn(size_t step) {
    return An_.at(step);
}

double ExpectedResultDefaultIter2::getAs(size_t step) {
    return As_.at(step);
}


void ExpectedResultDefaultIter2::createResVector() {
    addDataRow(0, 0.231273,  0.17401, 0.231356, 0.174033);
    addDataRow(1,  0.17401, 0.173898, 0.231939, 0.173954);
    addDataRow(2, 0.173898, 0.232608, 0.232525, 0.173876);
    addDataRow(3, 0.231274, 0.173977, 0.174033, 0.173984);
    addDataRow(4, 0.173977, 0.173932, 0.173954, 0.173954);
    addDataRow(5, 0.173932, 0.232608, 0.173876, 0.173924);
}

void ExpectedResultDefaultIter2::addDataRow(
                size_t step, double Aw, double Ae, double An, double As) {
                    
    Aw_[step] = Aw;
    Ae_[step] = Ae;
    An_[step] = An;
    As_[step] = As;
}

}