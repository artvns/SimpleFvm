#include "SleSolverEigen.h"

namespace mathtools {

SleSolverEigen::SleSolverEigen() {

}

void SleSolverEigen::createContainers(const size_t cellsAmount) {
    createCoeffsMatrix(cellsAmount, cellsAmount);
    resultsVector_.createVector(cellsAmount);
    rhsVector_.createVector(cellsAmount);
}

void SleSolverEigen::placeMatrixCoeff(size_t rowPos, size_t colPos, 
                                                            double value) {
    triplets.push_back(Eigen::Triplet<double>(rowPos, colPos, value));
}

void SleSolverEigen::placeRhsValue(size_t i, double value) {
    rhsVector_.setValue(i, value);
}

void SleSolverEigen::solve() {
    coeffsMatrix_.setFromTriplets(triplets.begin(), triplets.end());

    Eigen::BiCGSTAB<Eigen::SparseMatrix<double>> solver;
    solver.setMaxIterations(maxSolverIterations_);
    solver.setTolerance(tolerance_);
    solver.compute(coeffsMatrix_);

    if (Eigen::Success != solver.info()) {
        std::cout << "<--- Decomposition failed --->" << '\n';
        throw customexceptions::SleSolverException(
                    "Decomposition failed...");
    }

    resultsVector_.getVector() = solver.solve(rhsVector_.getVector());
    coeffsMatrix_.prune(0, 0);
    triplets.clear();
}

void SleSolverEigen::createCoeffsMatrix(size_t rowsN, size_t colsN) {
    coeffsMatrix_ = Eigen::SparseMatrix<double>(rowsN, colsN);
}

ISleSolverVector& SleSolverEigen::getResultsVector() {
    return resultsVector_;
}

}