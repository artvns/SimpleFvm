#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_COEFFSPARTSCOMMONCREATOR_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_COEFFSPARTSCOMMONCREATOR_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"
#include "FVMSolver/CoeffsPartsCommon/CellNumbers/CellNumbers.h"
#include "FVMSolver/CoeffsPartsCommon/CellTypes/CellTypes.h"
#include "FVMSolver/CoeffsPartsCommon/DataExchanger/AbstractDataExchanger.h"
#include "FVMSolver/CoeffsPartsCommon/CellNumbers/CellNumsSets.h"
#include "FVMSolver/CoeffsPartsCommon/CellTypes/CellTypesSets.h"
#include "FVMSolver/CoeffsPartsCommon/DataExchanger/DataExchangerSets.h"


namespace fvmsolver {

class CoeffsPartsCommonCreator {
private:
    using shPtrMapCellNumbers = std::shared_ptr<MapAdt<std::unique_ptr<CellNumbers>>>;
    using shPtrMapCellTypes = std::shared_ptr<MapAdt<std::unique_ptr<CellTypes>>>;
    using shPtrMapAbstDataExchanger = std::shared_ptr<MapAdt<std::unique_ptr<AbstractDataExchanger>>>;

public:
    CoeffsPartsCommonCreator(DataManager& dataManager, 
                            MeshInfoManager& meshInfoManager,
                            SolverDataStoresCreator& solverDataStores);

    shPtrMapCellNumbers getCellNumbersSetU();
    shPtrMapCellNumbers getCellNumbersSetV();
    shPtrMapCellNumbers getCellNumbersSetP();
    shPtrMapCellTypes getCellTypesSetU();
    shPtrMapCellTypes getCellTypesSetV();
    shPtrMapCellTypes getCellTypesSetP();
    shPtrMapAbstDataExchanger getDataExchangerSetU();
    shPtrMapAbstDataExchanger getDataExchangerSetV();
    shPtrMapAbstDataExchanger getDataExchangerSetP();

private:
    CellNumsSets cellNumsSets_;
    CellTypesSets cellTypesSets_;
    DataExchangerSets dataExchangerSets_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_COEFFSPARTSCOMMONCREATOR_H