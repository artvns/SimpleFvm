#ifndef SIMPLEFVM_MATHTOOLS_SLESOLVERS_ISLESOLVER_H
#define SIMPLEFVM_MATHTOOLS_SLESOLVERS_ISLESOLVER_H

#include <cstddef>

#include "ISleSolverVector.h"


namespace mathtools {

class ISleSolver {
public:
    virtual void createContainers(const size_t cellsAmount) = 0;
    virtual void placeMatrixCoeff(size_t row, size_t col, double value) = 0;
    virtual void placeRhsValue(size_t i, double value) = 0;
    virtual void solve() = 0;
    virtual ISleSolverVector& getResultsVector() = 0;

    virtual ~ISleSolver() {};
};

}
#endif // SIMPLEFVM_MATHTOOLS_SLESOLVERS_ISLESOLVER_H