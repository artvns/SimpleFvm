#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_ABSTRACTRESIDUALSOUTPUT_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_ABSTRACTRESIDUALSOUTPUT_H

#include <cstddef>


namespace fvmsolver {

class AbstractResidualsOutput {
public:
    AbstractResidualsOutput();
    virtual ~AbstractResidualsOutput() = 0;

    virtual void saveStepResiduals(size_t stepNumber) = 0;

    void addStepResidualU(double residual);
    void addStepResidualV(double residual);
    void addStepResidualP(double residual);

protected:
    double residualU_ = 0.0;
    double residualV_ = 0.0;
    double residualP_ = 0.0;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_ABSTRACTRESIDUALSOUTPUT_H

