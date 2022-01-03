#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORV_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORV_H

#include <cstddef>
#include <memory>
#include <vector>

#include "IResidsCalculator.h"
#include "ResidualsCalculatorVPort.h"


namespace fvmsolver {

class ResidualsCalculatorV : public IResidsCalculator {
private:
    using uPtrDataPort = std::unique_ptr<ResidualsCalculatorVPort>;

public:
    ResidualsCalculatorV(uPtrDataPort spData);

    double calculateCellResidual(const size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    ResidualsCalculatorVPort& data_;
    CalculatedScalar& vStar_;

    std::vector<double>& coeffAp_;
    std::vector<double>& coeffAw_;
    std::vector<double>& coeffAe_;
    std::vector<double>& coeffAn_;
    std::vector<double>& coeffAs_;

    double residual_ = 0.0;

    bool isCoeffExists(const size_t num);
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORV_H