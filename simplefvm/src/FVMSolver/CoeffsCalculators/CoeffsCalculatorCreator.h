#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORCREATOR_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORCREATOR_H

#include <memory>

#include "FVMSolver/CoeffsCalculators/Calculators/AbstractCoeffsCalculator.h"
#include "FVMSolver/CoeffsCalculators/CoeffsCalculatorBuilder.h"


namespace fvmsolver {

class CoeffsCalculatorCreator {
public:
    CoeffsCalculatorCreator();

    std::shared_ptr<AbstractCoeffsCalculator> createForU(
        CoeffsCalculatorBuilder& builder);

    std::shared_ptr<AbstractCoeffsCalculator> createForV(
        CoeffsCalculatorBuilder& builder);
        
    std::shared_ptr<AbstractCoeffsCalculator> createForP(
        CoeffsCalculatorBuilder& builder);
private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_COEFFSCALCULATORCREATOR_H