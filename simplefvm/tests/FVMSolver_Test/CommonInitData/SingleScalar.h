#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_SINGLESCALAR_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_SINGLESCALAR_H

#include <cstddef>
#include <vector>

#include "MathTools/SleSolvers/ISleSolverVector.h"


namespace commoninitdata {

class SingleScalar : public mathtools::ISleSolverVector {
public:
    SingleScalar();

    void    createVector(size_t size)           override;
    double  getValue(size_t i)                  override;
    void    setValue(size_t i, double value)    override;
    size_t  getSize()                           override;

    std::vector<double> getVector();

private:
    size_t size_ = 0;
    std::vector<double> dataVector_;
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_SINGLESCALAR_H