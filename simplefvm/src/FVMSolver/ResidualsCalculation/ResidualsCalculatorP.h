#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORP_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORP_H

#include <memory>

#include "IResidsCalculator.h"
#include "ResidualsCalculatorPPort.h"


namespace fvmsolver {

class ResidualsCalculatorP : public IResidsCalculator {
private:
    using uPtrDataPort = std::unique_ptr<ResidualsCalculatorPPort>;

public:
    ResidualsCalculatorP(uPtrDataPort spData);

    double calculateCellResidual(size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    ResidualsCalculatorPPort& data_;

    double residual_ = 0.0;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORP_H