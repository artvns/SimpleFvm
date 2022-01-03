#include "ExpectedResultDefaultIter2.h"

namespace rhs_v {

ExpectedResultDefaultIter2::ExpectedResultDefaultIter2() {
    size_t cells_ = 20;
    
    rhs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter2::getRhsValue(size_t step) {
    return rhs_.at(step);
}


void ExpectedResultDefaultIter2::createResVector() {
    addDataRow(0  ,  1.94385e-07  );
    addDataRow(1  ,  1.39301e-07  );
    addDataRow(2  , -2.10025e-23  );
    addDataRow(3  , -6.01549e-24  );
    addDataRow(4  , -1.94457e-07  );
    addDataRow(5  , -1.39013e-07  );
    addDataRow(6  ,  1.25282e-07  );
    addDataRow(7  ,  -1.0335e-23  );
    addDataRow(8  ,   -1.253e-07  );
    addDataRow(9  ,  4.22194e-08  );
    addDataRow(10 ,  1.54154e-24  );
    addDataRow(11 , -4.22607e-08  );
    addDataRow(12 ,  4.21921e-07  );
    addDataRow(13 ,  5.07879e-07  );
    addDataRow(14 ,  2.29215e-07  );
    addDataRow(15 ,  7.36473e-08  );
    addDataRow(16 , -4.20927e-07  );
    addDataRow(17 , -5.00171e-07  );
    addDataRow(18 , -2.29043e-07  );
    addDataRow(19 , -7.36942e-08  );
}


void ExpectedResultDefaultIter2::addDataRow(size_t step, double rhs) {
    rhs_[step] = rhs;
}

}