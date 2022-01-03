#ifndef SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_SLESOLVER_H
#define SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_SLESOLVER_H

#include <cstddef>
#include <iostream>

#include "MathTools/SleSolvers/ISleSolver.h"


namespace fvmsolver {

class SleSolver {
public:
    SleSolver(mathtools::ISleSolver& solver);

    void createContainers(const size_t cellsAmount);
    void placeCoeff(size_t rowPos, size_t colPos, double value);
    void placeRhsValue(size_t rowPos, double value);
    void solve();

private:
    mathtools::ISleSolver& solver_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_SLESOLVER_H