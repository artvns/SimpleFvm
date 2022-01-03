#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMBERSPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMBERSPORT_H

#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"


namespace fvmsolver {

class CellNumbersPort {
public:
    CellNumbersPort(const SolverCellNumsInteriorMask& nums);

    size_t get_pNum(size_t step) const;
    size_t get_wNum(size_t step) const;
    size_t get_eNum(size_t step) const;
    size_t get_nNum(size_t step) const;
    size_t get_sNum(size_t step) const;

private:
    const SolverCellNumsInteriorMask& nums_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMBERSPORT_H