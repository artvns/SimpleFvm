#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSPORT_H

#include <cstddef>

#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsPMask.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"


namespace fvmsolver {

class CoeffsPressPort {
public:
    CoeffsPressPort(const SolverFluidPropsMask& fluid, 
                    const SolverMeshParamsMask& mesh,
                    const SolverCellNumsGlobalMask& numsGlob, 
                    const SolverAdjCellInteriorNumsPMask& adjNumsInterior,
                    CoeffsCalculatorsStore& coeffsCalculators);

    double getRHO() const;
    double get_dX(size_t num) const;
    double get_dY(size_t num) const;

    size_t getNumPp(size_t step) const;
    size_t getNumUStarW(size_t step) const;
    size_t getNumUStarE(size_t step) const;
    size_t getNumVStarN(size_t step) const;
    size_t getNumVStarS(size_t step) const;

    double get_deU(size_t num) const;
    double get_deV(size_t num) const;

private:
    const SolverFluidPropsMask& fluid_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& numsGlob_;
    const SolverAdjCellInteriorNumsPMask& adjNumsInterior_;
    CoeffsCalculatorsStore& coeffsCalculators_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSPORT_H