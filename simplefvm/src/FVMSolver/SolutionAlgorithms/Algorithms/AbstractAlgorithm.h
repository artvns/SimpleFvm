#ifndef SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMS_ABSTRACTALGORITHM_H
#define SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMS_ABSTRACTALGORITHM_H

#include <memory>

#include "FVMSolver/Sle/ScalarCalculatorCreator.h"
#include "FVMSolver/Sle/ScalarCalculator.h"
#include "FVMSolver/FieldsCorrection/FieldCorrector.h"
#include "FVMSolver/ResidualsCalculation/ResidualsCalculator.h"
#include "FVMSolver/ResidualsOutput/ResidualsOutputer.h"


namespace fvmsolver {

class AbstractAlgorithm {
public:
    AbstractAlgorithm();
    virtual ~AbstractAlgorithm() = 0;

    void calculate();
    void setNumberOfIterations(const size_t iterations);

protected:
    size_t numberOfIterations_ = 0;
    size_t calculationStep_ = 0;

    virtual void executeAlgorithmSteps() = 0;

    virtual void solveMomentumEquations() = 0;
    virtual void solvePressureCorrectionEquation() = 0;
    virtual void calculateResiduals() = 0;
    virtual void outputResiduals() = 0;
    virtual void correctFields() = 0;

    void calculateOtherValues() {};

    std::shared_ptr<ScalarCalculator> pUStarCalculator_ = nullptr;
    std::shared_ptr<ScalarCalculator> pVStarCalculator_ = nullptr;
    std::shared_ptr<ScalarCalculator> pPressCalculator_ = nullptr;

    std::shared_ptr<FieldCorrector> pFieldCorrectorP_ = nullptr;
    std::shared_ptr<FieldCorrector> pFieldCorrectorU_ = nullptr;
    std::shared_ptr<FieldCorrector> pFieldCorrectorV_ = nullptr;

    std::shared_ptr<ResidualsCalculator> pResidCalculatorP_ = nullptr;
    std::shared_ptr<ResidualsCalculator> pResidCalculatorU_ = nullptr;
    std::shared_ptr<ResidualsCalculator> pResidCalculatorV_ = nullptr;

    std::shared_ptr<ResidualsOutputer> pResidOutputer_ = nullptr;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMS_ABSTRACTALGORITHM_H