#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSDATAPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"

#include "RhsPressPort.h"


namespace fvmsolver {

class RhsPressDataPorts {
public:
    RhsPressDataPorts(DataManager& dataManager, 
                            MathToolsManager& mathToolsManager);

    std::unique_ptr<RhsPressPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
    MathToolsManager& mathToolsManager_;

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSDATAPORTS_H