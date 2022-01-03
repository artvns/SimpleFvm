#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_ABSTRACTSOURCEPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_ABSTRACTSOURCEPORT_H

#include <cstddef>

#include "FVMSolver/Tools/Enums/EnumAdjacentCellTypes.cpp"
#include "FVMSolver/DataReciever/FluidProperties/SolverFluidPropsMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/AdjacentCellsType/SolverAdjCellsTypeMask.h"


namespace fvmsolver {

class AbstractSourcePort {
public:
    AbstractSourcePort( const SolverFluidPropsMask& fluid, 
                        const SolverMeshParamsMask& mesh,
                        const SolverAdjCellsTypeMask& adjCellsType, 
                        const SolverCellNumsGlobalMask& nums);

    virtual ~AbstractSourcePort() = 0;

    double getMU() const;
    double get_dX(size_t num) const;
    double get_dY(size_t num) const;
    size_t getNumCellp(size_t step) const;
    size_t getNumCellw(size_t step) const;
    size_t getNumCelle(size_t step) const;
    size_t getNumCelln(size_t step) const;
    size_t getNumCells(size_t step) const;
    EnumAdjacentCellTypes getCellType(size_t num) const;

    virtual double getWallVelocity() const { return 0.0; }

protected:
    const SolverFluidPropsMask& fluid_;
    const SolverMeshParamsMask& mesh_;
    const SolverAdjCellsTypeMask& adjCellsType_;
    const SolverCellNumsGlobalMask& nums_;

    double wallVelocity_ = 0.0;
private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_ABSTRACTSOURCEPORT_H