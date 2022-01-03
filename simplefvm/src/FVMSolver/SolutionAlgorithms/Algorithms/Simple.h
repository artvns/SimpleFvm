#ifndef SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMS_SIMPLE_H
#define SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMS_SIMPLE_H

#include <cstddef>

#include "AbstractAlgorithm.h"


namespace fvmsolver {

class Simple : public AbstractAlgorithm {
public:
    Simple();

    void setUVariableCalculator(std::shared_ptr<ScalarCalculator> sle);
    void setVVariableCalculator(std::shared_ptr<ScalarCalculator> sle);
    void setPressVariableCalculator(std::shared_ptr<ScalarCalculator> sle);

    void setFieldsCorrectorP(std::shared_ptr<FieldCorrector> corrector);
    void setFieldsCorrectorU(std::shared_ptr<FieldCorrector> corrector);
    void setFieldsCorrectorV(std::shared_ptr<FieldCorrector> corrector);

    void setResidualsCalculatorP(std::shared_ptr<ResidualsCalculator> residCalculator);
    void setResidualsCalculatorU(std::shared_ptr<ResidualsCalculator> residCalculator);
    void setResidualsCalculatorV(std::shared_ptr<ResidualsCalculator> residCalculator);

    void setResidualsOutputer(std::shared_ptr<ResidualsOutputer> residsOutputer);

protected:
    void executeAlgorithmSteps() override;

    void solveMomentumEquations() override;
    void solvePressureCorrectionEquation() override;
    void calculateResiduals() override;
    void outputResiduals() override;
    void correctFields() override;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMS_SIMPLE_H