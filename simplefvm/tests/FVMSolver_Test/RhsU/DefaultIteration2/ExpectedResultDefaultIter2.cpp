#include "ExpectedResultDefaultIter2.h"

namespace rhs_u {

ExpectedResultDefaultIter2::ExpectedResultDefaultIter2() {
    size_t cells_ = 20;
    
    rhs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter2::getRhsValue(size_t step) {
    return rhs_.at(step);
}


void ExpectedResultDefaultIter2::createResVector() {
    addDataRow(0  , -2.56651e-07  );
    addDataRow(1  , -3.12543e-07  );
    addDataRow(2  , -3.12543e-07  );
    addDataRow(3  , -2.56679e-07  );
    addDataRow(4  , -1.57521e-07  );
    addDataRow(5  , -2.70689e-07  );
    addDataRow(6  , -2.70707e-07  );
    addDataRow(7  , -1.57351e-07  );
    addDataRow(8  , -9.52378e-08  );
    addDataRow(9  , -1.93009e-07  );
    addDataRow(10 , -1.93015e-07  );
    addDataRow(11 , -9.51181e-08  );
    addDataRow(12 ,  1.96768e-06  );
    addDataRow(13 ,  2.23786e-06  );
    addDataRow(14 ,  2.23841e-06  );
    addDataRow(15 ,  1.97474e-06  );
    addDataRow(16 , -7.72356e-08  );
    addDataRow(17 , -1.66139e-07  );
    addDataRow(18 ,  -1.6614e-07  );
    addDataRow(19 , -7.71731e-08  );
}


void ExpectedResultDefaultIter2::addDataRow(size_t step, double rhs) {
    rhs_[step] = rhs;
}

}