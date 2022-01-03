#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMSDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMSDATAPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"

#include "CellNumbersPort.h"


namespace fvmsolver {

class CellNumsDataPorts {
public:
    CellNumsDataPorts(DataManager& dataManager);

    std::unique_ptr<CellNumbersPort> createPortU(std::string name);
    std::unique_ptr<CellNumbersPort> createPortV(std::string name);
    std::unique_ptr<CellNumbersPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMSDATAPORTS_H