#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORU_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORU_H

#include <cstddef>
#include <memory>
#include <vector>

#include "IResidsCalculator.h"
#include "ResidualsCalculatorUPort.h"


namespace fvmsolver {

class ResidualsCalculatorU : public IResidsCalculator {
private:
    using uPtrDataPort = std::unique_ptr<ResidualsCalculatorUPort>;

public:
    ResidualsCalculatorU(uPtrDataPort spData);

    double calculateCellResidual(const size_t step) override;

private:
    uPtrDataPort spData_ = nullptr;
    ResidualsCalculatorUPort& data_;
    CalculatedScalar& uStar_;

    std::vector<double>& coeffAp_;
    std::vector<double>& coeffAw_;
    std::vector<double>& coeffAe_;
    std::vector<double>& coeffAn_;
    std::vector<double>& coeffAs_;

    double residual_ = 0.0;

    bool isCoeffExists(const size_t num);
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORU_H