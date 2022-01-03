#ifndef SIMPLEFVM_MATHTOOLS_SLESOLVERS_EIGENLIB_SLESOLVEREIGEN_H
#define SIMPLEFVM_MATHTOOLS_SLESOLVERS_EIGENLIB_SLESOLVEREIGEN_H

#include <cstddef>
#include <iostream>
#include <vector>

#include <Eigen/IterativeLinearSolvers>
#include <Eigen/Sparse>

#include "CustomExceptions/SleSolverException.h"
#include "MathTools/SleSolvers/ISleSolver.h"
#include "MathTools/SleSolvers/ISleSolverVector.h"

#include "VectorEigen.h"


namespace mathtools {

class SleSolverEigen : public ISleSolver {
public:
    SleSolverEigen();

    void createContainers(const size_t cellsAmount) override;
    void placeMatrixCoeff(size_t row, size_t col, double value) override;
    void placeRhsValue(size_t i, double value) override;
    void solve() override;
    ISleSolverVector& getResultsVector() override;

private:
    const int maxSolverIterations_ = 100;
    const double tolerance_ = 0.00000001;

    VectorEigen resultsVector_;
    VectorEigen rhsVector_;

    Eigen::SparseMatrix<double> coeffsMatrix_;
    std::vector<Eigen::Triplet<double>> triplets;

    void createCoeffsMatrix(size_t rows, size_t cols);
};

}
#endif // SIMPLEFVM_MATHTOOLS_SLESOLVERS_EIGENLIB_SLESOLVEREIGEN_H