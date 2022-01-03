#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSPORT_H

#include <cstddef>

#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsPMask.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"


namespace fvmsolver {

class RhsPressPort {
public:
    RhsPressPort(const SolverFluidPropsMask& fluid, 
                    const SolverMeshParamsMask& mesh,
                    const SolverCellNumsGlobalMask& numsGlob, 
                    const SolverAdjCellInteriorNumsPMask& adjNumsInterior,
                    ScalarsStore& scalarsStore);

    double getRHO() const;
    double get_dX(size_t num) const;
    double get_dY(size_t num) const;

    size_t getNumPp(size_t step) const;
    size_t getNumUStarW(size_t step) const;
    size_t getNumUStarE(size_t step) const;
    size_t getNumVStarN(size_t step) const;
    size_t getNumVStarS(size_t step) const;

    CalculatedScalar& getUStar() const;
    CalculatedScalar& getVStar() const;

private:
    const SolverFluidPropsMask& fluid_;
    const SolverMeshParamsMask& mesh_;
    const SolverCellNumsGlobalMask& numsGlob_;
    const SolverAdjCellInteriorNumsPMask& adjNumsInterior_;
    ScalarsStore& scalarsStore_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSPORT_H