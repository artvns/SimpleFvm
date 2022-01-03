#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_IRESIDSCALCULATOR_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_IRESIDSCALCULATOR_H

#include <cstddef>
#include <cmath>


namespace fvmsolver {

class IResidsCalculator {
public:
    virtual double calculateCellResidual(size_t step) = 0;

    virtual ~IResidsCalculator() {};
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_IRESIDSCALCULATOR_H