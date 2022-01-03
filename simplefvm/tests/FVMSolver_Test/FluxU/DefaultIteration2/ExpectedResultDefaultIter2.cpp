#include "ExpectedResultDefaultIter2.h"

namespace flux_u {

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
    addDataRow(0,  1.86292e-06 ,  2.20141e-06 ,  8.23209e-05 ,  6.34579e-05 );
    addDataRow(1,  2.20141e-06 ,  6.76984e-07 ,  2.21502e-05 ,  2.32101e-05 );
    addDataRow(2,  6.76984e-07 ,  2.20141e-06 , -2.21502e-05 , -2.32101e-05 );
    addDataRow(3,  2.20141e-06 ,  1.86292e-06 , -8.23209e-05 , -6.34579e-05 );
    addDataRow(4,  -1.1397e-05 , -3.20839e-05 ,  6.34579e-05 ,  3.68401e-05 );
    addDataRow(5, -3.20839e-05 , -4.13738e-05 ,  2.32101e-05 ,  1.49573e-05 );
}


void ExpectedResultDefaultIter2::addDataRow(
            size_t step, double Fw, double Fe, double Fn, double Fs) {
                
    Fw_[step] = Fw;
    Fe_[step] = Fe;
    Fn_[step] = Fn;
    Fs_[step] = Fs;
}

}