#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESSETS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "CellTypes.h"
#include "CellTypesDataPorts.h"


namespace fvmsolver {

class CellTypesSets {
private:
    using shPtrMapCellTypes = std::shared_ptr<MapAdt<std::unique_ptr<CellTypes>>>;

public:
    CellTypesSets(DataManager& dataManager, 
                            MeshInfoManager& meshInfoManager);

    shPtrMapCellTypes createSetForU();
    shPtrMapCellTypes createSetForV();
    shPtrMapCellTypes createSetForP();

private:
    CellTypesDataPorts dataPorts_;
    SetsCreator<CellTypes, CellTypesDataPorts, CellTypes> setsMaker_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESSETS_H