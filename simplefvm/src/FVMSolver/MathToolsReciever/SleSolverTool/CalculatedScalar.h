#ifndef SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_CALCULATEDSCALAR_H
#define SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_CALCULATEDSCALAR_H

#include <cstddef>

#include "MathTools/SleSolvers/ISleSolverVector.h"


namespace fvmsolver {

class CalculatedScalar {
public:
    CalculatedScalar(mathtools::ISleSolverVector& resVector);

    double getValue(const size_t i);
    void setValue(const size_t i, double value);
    size_t getSize();

private:
    mathtools::ISleSolverVector& resVector_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_CALCULATEDSCALAR_H