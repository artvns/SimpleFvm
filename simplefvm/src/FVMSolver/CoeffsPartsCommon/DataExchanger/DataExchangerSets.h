#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERSETS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "DataExchangerPorts.h"
#include "AbstractDataExchanger.h"
#include "DataExchangerU.h"
#include "DataExchangerV.h"
#include "DataExchangerP.h"


namespace fvmsolver {

class DataExchangerSets {
private:
    using shPtrMapAbstDataExchanger = std::shared_ptr<MapAdt<std::unique_ptr<AbstractDataExchanger>>>;

public:
    DataExchangerSets(DataManager& dataManager, 
                        MeshInfoManager& meshInfoManager,
                        SolverDataStoresCreator& solverDataStores);

    shPtrMapAbstDataExchanger createSetForU();
    shPtrMapAbstDataExchanger createSetForV();
    shPtrMapAbstDataExchanger createSetForP();

private:
    DataExchangerPorts dataPorts_;
    SetsCreator<AbstractDataExchanger, DataExchangerPorts, DataExchangerU> setsMakerU_;
    SetsCreator<AbstractDataExchanger, DataExchangerPorts, DataExchangerV> setsMakerV_;
    SetsCreator<AbstractDataExchanger, DataExchangerPorts, DataExchangerP> setsMakerP_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERSETS_H