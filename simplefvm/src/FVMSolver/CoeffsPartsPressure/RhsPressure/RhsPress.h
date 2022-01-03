#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESS_H

#include <cstddef>
#include <memory>

#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"

#include "RhsPressPort.h"


namespace fvmsolver {

class RhsPress {
private:
    using uPtrDataPort = std::unique_ptr<RhsPressPort>;

public:
    RhsPress(uPtrDataPort spData);

    void calculate(size_t step);
    double getRhsValue();

private:
    uPtrDataPort spData_ = nullptr;
    const RhsPressPort& data_;

    CalculatedScalar& uStar_;
    CalculatedScalar& vStar_;

    double rhsValue_ = 0.0;

    bool isNotZeroNumber(const size_t num);
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESS_H

