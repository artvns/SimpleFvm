#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_IRESIDUALSOUTPUTER_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_IRESIDUALSOUTPUTER_H

#include <cstddef>


namespace fvmsolver {

class IResidualsOutputer {
public:
    virtual void saveStepResiduals(size_t stepNumber) = 0;
    virtual void addStepResidualU(double residual) = 0;
    virtual void addStepResidualV(double residual) = 0;
    virtual void addStepResidualP(double residual) = 0;

    virtual ~IResidualsOutputer() {};
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_IRESIDUALSOUTPUTER_H