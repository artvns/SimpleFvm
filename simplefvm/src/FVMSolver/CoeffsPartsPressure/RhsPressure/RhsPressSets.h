#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSSETS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"

#include "RhsPressDataPorts.h"
#include "RhsPress.h"


namespace fvmsolver {

class RhsPressSets {
private:
    using shPtrMapRhsPress = std::shared_ptr<MapAdt<std::unique_ptr<RhsPress>>>;

public:
    RhsPressSets(DataManager& dataManager, 
                    MathToolsManager& mathToolsManager,
                    MeshInfoManager& meshInfoManager);

    shPtrMapRhsPress createSet();

private:
    RhsPressDataPorts dataPorts_;
    SetsCreator<RhsPress, RhsPressDataPorts, RhsPress> setsMaker_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_RHSPRESSURE_RHSPRESSSETS_H