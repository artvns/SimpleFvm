#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_VDATAEXCHANGERPORT_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_VDATAEXCHANGERPORT_H

#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/MeshParameters/SolverMeshParamsMask.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"


namespace fvmsolver {

class VDataExchangerPort {
public:
    VDataExchangerPort( const SolverMeshParamsMask& mesh, 
                        const SolverCellNumsGlobalMask& nums,
                        const SolverCellNumsInteriorMask& numsInterior, 
                        CoeffsCalculatorsStore& coeffsCalculatorsData);

    size_t getGlobNumVp(size_t step) const;
    size_t get_pNum(size_t step) const;
    double get_dX(size_t num) const;

    void set_de(size_t pos, double value);

private:
    const SolverMeshParamsMask& mesh_; 
    const SolverCellNumsGlobalMask& nums_;
    const SolverCellNumsInteriorMask&  numsInterior_;
    CoeffsCalculatorsStore& coeffsCalculatorsData_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_VDATAEXCHANGERPORT_H