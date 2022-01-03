#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMSSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMSSETS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "CellNumbers.h"
#include "CellNumsDataPorts.h"


namespace fvmsolver {

class CellNumsSets {
private:
    using shPtrMapCellNumbers = std::shared_ptr<MapAdt<std::unique_ptr<CellNumbers>>>;

public:
    CellNumsSets(DataManager& dataManager, 
                            MeshInfoManager& meshInfoManager);

    shPtrMapCellNumbers createSetForU();
    shPtrMapCellNumbers createSetForV();
    shPtrMapCellNumbers createSetForP();

private:
    CellNumsDataPorts dataPorts_;
    SetsCreator<CellNumbers, CellNumsDataPorts, CellNumbers> setsMaker_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMSSETS_H