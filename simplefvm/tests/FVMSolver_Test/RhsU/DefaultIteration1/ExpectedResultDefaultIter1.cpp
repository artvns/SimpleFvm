#include "ExpectedResultDefaultIter1.h"

namespace rhs_u {

ExpectedResultDefaultIter1::ExpectedResultDefaultIter1() {
    size_t cells_ = 20;
    
    rhs_.resize(cells_);

    createResVector();
}


double ExpectedResultDefaultIter1::getRhsValue(size_t step) {
    return rhs_.at(step);
}


void ExpectedResultDefaultIter1::createResVector() {
    addDataRow(0  ,       0.0  );
    addDataRow(1  ,       0.0  );
    addDataRow(2  ,       0.0  );
    addDataRow(3  ,       0.0  );
    addDataRow(4  ,       0.0  );
    addDataRow(5  ,       0.0  );
    addDataRow(6  ,       0.0  );
    addDataRow(7  ,       0.0  );
    addDataRow(8  ,       0.0  );
    addDataRow(9  ,       0.0  );
    addDataRow(10 ,       0.0  );
    addDataRow(11 ,       0.0  );
    addDataRow(12 , 2.008e-06  );
    addDataRow(13 , 2.008e-06  );
    addDataRow(14 , 2.008e-06  );
    addDataRow(15 , 2.008e-06  );
    addDataRow(16 ,       0.0  );
    addDataRow(17 ,       0.0  );
    addDataRow(18 ,       0.0  );
    addDataRow(19 ,       0.0  );
}


void ExpectedResultDefaultIter1::addDataRow(size_t step, double rhs) {
    rhs_[step] = rhs;
}

}