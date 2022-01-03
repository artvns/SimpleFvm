#include "ExpectedResultDefaultIter1.h"

namespace flux_v {

ExpectedResultDefaultIter1::ExpectedResultDefaultIter1() {
    size_t cells_ = 6;

    Fw_.resize(cells_);
    Fe_.resize(cells_);
    Fn_.resize(cells_);
    Fs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter1::getFw(size_t step) {
    return Fw_.at(step);
}

double ExpectedResultDefaultIter1::getFe(size_t step) {
    return Fe_.at(step);
}

double ExpectedResultDefaultIter1::getFn(size_t step) {
    return Fn_.at(step);
}

double ExpectedResultDefaultIter1::getFs(size_t step) {
    return Fs_.at(step);
}


void ExpectedResultDefaultIter1::createResVector() {
    addDataRow(0, 0.0, 0.0, 0.0, 0.0);
    addDataRow(1, 0.0, 0.0, 0.0, 0.0);
    addDataRow(2, 0.0, 0.0, 0.0, 0.0);
    addDataRow(3, 0.0, 0.0, 0.0, 0.0);
    addDataRow(4, 0.0, 0.0, 0.0, 0.0);
    addDataRow(5, 0.0, 0.0, 0.0, 0.0);
}


void ExpectedResultDefaultIter1::addDataRow(
            size_t step, double Fw, double Fe, double Fn, double Fs) {
                
    Fw_[step] = Fw;
    Fe_[step] = Fe;
    Fn_[step] = Fn;
    Fs_[step] = Fs;
}

}