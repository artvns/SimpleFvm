#ifndef SIMPLEFVM_MATHTOOLS_SLESOLVERS_EIGENLIB_VECTOREIGEN_H
#define SIMPLEFVM_MATHTOOLS_SLESOLVERS_EIGENLIB_VECTOREIGEN_H

#include <cstddef>
#include <vector>

#include <Eigen/IterativeLinearSolvers>
#include <Eigen/Sparse>

#include "MathTools/SleSolvers/ISleSolverVector.h"


namespace mathtools {

class VectorEigen : public ISleSolverVector {
public:
    VectorEigen();

    void createVector(size_t size)          override;
    double getValue(size_t i)               override;
    void setValue(size_t i, double value)   override;
    size_t getSize()                        override;

    Eigen::VectorXd& getVector();

private:
    size_t size_ = 0;
    Eigen::VectorXd pVector_;
};

}
#endif // SIMPLEFVM_MATHTOOLS_SLESOLVERS_EIGENLIB_VECTOREIGEN_H