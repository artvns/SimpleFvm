#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "UDataExchangerPort.h"
#include "VDataExchangerPort.h"
#include "PDataExchangerPort.h"


namespace fvmsolver {

class DataExchangerPorts {
public:
    DataExchangerPorts(DataManager& dataManager, 
                        SolverDataStoresCreator& solverDataStores);

    std::unique_ptr<UDataExchangerPort> createPortU(std::string name);
    std::unique_ptr<VDataExchangerPort> createPortV(std::string name);
    std::unique_ptr<PDataExchangerPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
    SolverDataStoresCreator& solverDataStores_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_DATAEXCHANGER_DATAEXCHANGERPORTS_H