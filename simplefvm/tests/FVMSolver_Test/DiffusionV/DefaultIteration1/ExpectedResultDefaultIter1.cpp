#include "ExpectedResultDefaultIter1.h"

namespace diffusion_v {

ExpectedResultDefaultIter1::ExpectedResultDefaultIter1() {
    size_t cells_ = 20;

    Dw_.resize(cells_);
    De_.resize(cells_);
    Dn_.resize(cells_);
    Ds_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter1::getDw(size_t step) {
    return Dw_.at(step);
}

double ExpectedResultDefaultIter1::getDe(size_t step) {
    return De_.at(step);
}

double ExpectedResultDefaultIter1::getDn(size_t step) {
    return Dn_.at(step);
}

double ExpectedResultDefaultIter1::getDs(size_t step) {
    return Ds_.at(step);
}


void ExpectedResultDefaultIter1::createResVector() {
    addDataRow(0, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(1, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(2, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(3, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(4, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(5, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(6, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(7, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(8, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(9, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(10, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(11, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(12, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(13, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(14, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(15, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(16, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(17, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(18, 0.001004, 0.001004, 0.001004, 0.001004);
    addDataRow(19, 0.001004, 0.001004, 0.001004, 0.001004);
}


void ExpectedResultDefaultIter1::addDataRow(
            size_t step, double Dw, double De, double Dn, double Ds) {

    Dw_[step] = Dw;
    De_[step] = De;
    Dn_[step] = Dn;
    Ds_[step] = Ds;
}

}