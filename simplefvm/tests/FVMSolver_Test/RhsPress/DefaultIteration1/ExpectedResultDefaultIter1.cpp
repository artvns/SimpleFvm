#include "ExpectedResultDefaultIter1.h"

namespace rhs_p {

ExpectedResultDefaultIter1::ExpectedResultDefaultIter1() {
    size_t cells_ = 6;
    
    rhs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter1::getRhsValue(size_t step) {
    return rhs_.at(step);
}


void ExpectedResultDefaultIter1::createResVector() {
    addDataRow(0,  1.72289e-05);
    addDataRow(1,          0.0);
    addDataRow(2, -1.72289e-05);
    addDataRow(3,   6.9141e-06);
    addDataRow(4,          0.0);
    addDataRow(5,  -6.9141e-06);
}


void ExpectedResultDefaultIter1::addDataRow(size_t step, double rhs) {
    rhs_[step] = rhs;
}

}