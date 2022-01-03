#include "CalculatedScalar.h"

namespace fvmsolver {

CalculatedScalar::CalculatedScalar(
            mathtools::ISleSolverVector& resVector) : 
                                    resVector_(resVector) {
    
}

double CalculatedScalar::getValue(const size_t i) {
    return resVector_.getValue(i);
}

void CalculatedScalar::setValue(const size_t i, double value) {
    resVector_.setValue(i, value);
}

size_t CalculatedScalar::getSize() {
    return resVector_.getSize();
}

}