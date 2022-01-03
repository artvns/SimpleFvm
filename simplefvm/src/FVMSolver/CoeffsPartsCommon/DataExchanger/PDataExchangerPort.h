#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_PDATAEXCHANGERPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_PDATAEXCHANGERPORT_H

#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsPMask.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"


namespace fvmsolver {

class PDataExchangerPort {
public:
    PDataExchangerPort(const SolverCellNumsInteriorMask& numsInterior,
                       const SolverAdjCellInteriorNumsPMask& adjInterNums, 
                       const CoeffsCalculatorsStore& coeffsCalculatorsData);

    size_t getNumUStarW(size_t step) const;
    size_t getNumUStarE(size_t step) const;
    size_t getNumVStarN(size_t step) const;
    size_t getNumVStarS(size_t step) const;

    double get_deU(size_t num) const;
    double get_deV(size_t num) const;

private:
    const SolverCellNumsInteriorMask& numsInterior_;
    const SolverAdjCellInteriorNumsPMask& adjInterNums_;
    const CoeffsCalculatorsStore& coeffsCalculatorsData_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_PDATAEXCHANGERPORT_H