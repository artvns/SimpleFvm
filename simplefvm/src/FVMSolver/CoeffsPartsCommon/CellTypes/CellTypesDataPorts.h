#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESDATAPORTS_H

#include "FVMSolver/DataReciever/DataManager.h"

#include "CellTypesPort.h"


namespace fvmsolver {

class CellTypesDataPorts {
public:
    CellTypesDataPorts(DataManager& dataManager);

    std::unique_ptr<CellTypesPort> createPortU(std::string name);
    std::unique_ptr<CellTypesPort> createPortV(std::string name);
    std::unique_ptr<CellTypesPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLTYPES_CELLTYPESDATAPORTS_H