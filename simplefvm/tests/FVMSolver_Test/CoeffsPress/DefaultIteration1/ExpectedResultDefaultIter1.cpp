#include "ExpectedResultDefaultIter1.h"

namespace coeffs_p {

ExpectedResultDefaultIter1::ExpectedResultDefaultIter1() {
    size_t cells_ = 6;

    Aw_.resize(cells_);
    Ae_.resize(cells_);
    An_.resize(cells_);
    As_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter1::getAw(size_t step) {
    return Aw_.at(step);
}

double ExpectedResultDefaultIter1::getAe(size_t step) {
    return Ae_.at(step);
}

double ExpectedResultDefaultIter1::getAn(size_t step) {
    return An_.at(step);
}

double ExpectedResultDefaultIter1::getAs(size_t step) {
    return As_.at(step);
}


void ExpectedResultDefaultIter1::createResVector() {
    addDataRow(0, 0.231939, 0.173954, 0.231939, 0.173954);
    addDataRow(1, 0.173954, 0.173954, 0.231939, 0.173954);
    addDataRow(2, 0.173954, 0.231939, 0.231939, 0.173954);
    addDataRow(3, 0.231939, 0.173954, 0.173954, 0.173954);
    addDataRow(4, 0.173954, 0.173954, 0.173954, 0.173954);
    addDataRow(5, 0.173954, 0.231939, 0.173954, 0.173954);
}

void ExpectedResultDefaultIter1::addDataRow(size_t step, double Aw, double Ae, double An, double As) {
    Aw_[step] = Aw;
    Ae_[step] = Ae;
    An_[step] = An;
    As_[step] = As;
}

}