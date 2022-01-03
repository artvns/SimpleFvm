#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORPPORT_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORPPORT_H

#include <cstddef>
#include <string>

#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/SolverDataStores/SavedRhsStore.h"


namespace fvmsolver {

class ResidualsCalculatorPPort {
public:
    ResidualsCalculatorPPort(
            const SolverCellNumsInteriorMask& numsInterior,
            SavedRhsStore& savedRhs);

    size_t getInterNumPp(const size_t step) const;
    double getRhs(const size_t pos) const;

private:
    const SolverCellNumsInteriorMask& numsInterior_;
    SavedRhsStore& savedRhs_;
};  

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORPPORT_H