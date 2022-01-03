#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVELOCITYDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVELOCITYDATAPORTS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"

#include "RhsUPort.h"
#include "RhsVPort.h"


namespace fvmsolver {

class RhsVelocityDataPorts {
public:
    RhsVelocityDataPorts(DataManager& dataManager);

    std::unique_ptr<RhsUPort> createPortU(std::string name);
    std::unique_ptr<RhsVPort> createPortV(std::string name);

private:
    DataManager& dataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVELOCITYDATAPORTS_H