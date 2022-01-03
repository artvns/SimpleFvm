#include "ExpectedResultDefaultIter2.h"

namespace rhs_p {

ExpectedResultDefaultIter2::ExpectedResultDefaultIter2() {
    size_t cells_ = 6;
    
    rhs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter2::getRhsValue(size_t step) {
    return rhs_.at(step);
}


void ExpectedResultDefaultIter2::createResVector() {
    addDataRow(0,  1.33542e-06);
    addDataRow(1, -8.49614e-06);
    addDataRow(2, -1.74117e-05);
    addDataRow(3, -5.07209e-06);
    addDataRow(4, -3.07793e-06);
    addDataRow(5,   1.7278e-07);
}


void ExpectedResultDefaultIter2::addDataRow(size_t step, double rhs) {
    rhs_[step] = rhs;
}

}