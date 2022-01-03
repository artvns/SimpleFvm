#ifndef SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMBUILDERSIMPLE_H
#define SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMBUILDERSIMPLE_H

#include <memory>

#include "FVMSolver/SolverSettings/Config.h"
#include "FVMSolver/Sle/ScalarCalculatorCreator.h"
#include "FVMSolver/CoeffsCalculators/Calculators/AbstractCoeffsCalculator.h"
#include "FVMSolver/SolutionAlgorithms/AlgorithmBuilder.h"
#include "FVMSolver/SolutionAlgorithms/Algorithms/Simple.h"
#include "FVMSolver/FieldsCorrection/FieldsCorrectorsCreator.h"
#include "FVMSolver/ResidualsCalculation/ResidsCalculatorsCreator.h"
#include "FVMSolver/ResidualsOutput/ResidsOutputerCreator.h"


namespace fvmsolver {

class AlgorithmBuilderSimple : public AlgorithmBuilder {
public:
    AlgorithmBuilderSimple(
                Config& config,
                ScalarCalculatorCreator& sleCalculatorCreator,
                FieldsCorrectorsCreator& fieldsCorrectorsCreator,
                ResidsCalculatorsCreator& residsCalculatorsCreator,
                ResidsOutputerCreator& residsOutputerCreator);

    void createAlgorithm() override;
    void addNumberOfIterations() override;
    void addCalculatorUstar() override;
    void addCalculatorVstar() override;
    void addCalculatorPprime() override;
    void addCorrectorU() override;
    void addCorrectorV() override;
    void addCorrectorP() override;
    void addResidualsCalculatorU() override;
    void addResidualsCalculatorV() override;
    void addResidualsCalculatorP() override;
    void addResidualsOutput() override;

    std::shared_ptr<AbstractAlgorithm> getAlgorithm() override { return pAlgorithm_; }

private:
    Config& config_;
    ScalarCalculatorCreator& sleCalculatorCreator_;
    FieldsCorrectorsCreator& fieldsCorrectorsCreator_;
    ResidsCalculatorsCreator& residsCalculatorsCreator_;
    ResidsOutputerCreator& residsOutputerCreator_;
    
    std::shared_ptr<Simple> pAlgorithm_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMBUILDERSIMPLE_H