#include "ExpectedResultDefaultIter2.h"

namespace flux_v {

ExpectedResultDefaultIter2::ExpectedResultDefaultIter2() {
    size_t cells_ = 6;

    Fw_.resize(cells_);
    Fe_.resize(cells_);
    Fn_.resize(cells_);
    Fs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter2::getFw(size_t step) {
    return Fw_.at(step);
}

double ExpectedResultDefaultIter2::getFe(size_t step) {
    return Fe_.at(step);
}

double ExpectedResultDefaultIter2::getFn(size_t step) {
    return Fn_.at(step);
}

double ExpectedResultDefaultIter2::getFs(size_t step) {
    return Fs_.at(step);
}


void ExpectedResultDefaultIter2::createResVector() {
    addDataRow(0, -9.53412e-06 , -2.03484e-05 ,  4.53602e-05 ,  3.81674e-05 );
    addDataRow(1,  0.000129232 ,  0.000145464 ,  2.21502e-05 ,  4.53602e-05 );
    addDataRow(2, -2.03484e-05 , -2.03484e-05 ,  -3.4648e-21 , -3.74108e-21 );
    addDataRow(3,  0.000145464 ,  0.000145464 , -9.57508e-22 ,  -3.4648e-21 );
    addDataRow(4, -2.03484e-05 , -9.53412e-06 , -4.53602e-05 , -3.81674e-05 );
    addDataRow(5,  0.000145464 ,  0.000129232 , -2.21502e-05 , -4.53602e-05 );
}


void ExpectedResultDefaultIter2::addDataRow(
            size_t step, double Fw, double Fe, double Fn, double Fs) {
                
    Fw_[step] = Fw;
    Fe_[step] = Fe;
    Fn_[step] = Fn;
    Fs_[step] = Fs;
}

}