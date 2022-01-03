#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORPORTS_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORPORTS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "FieldCorrectorUPort.h"
#include "FieldCorrectorVPort.h"
#include "FieldCorrectorPPort.h"


namespace fvmsolver {

class FieldCorrectorPorts {
public:
    FieldCorrectorPorts(
                    DataManager& dataManager, 
                    MathToolsManager& mathToolsManager,
                    MeshInfoManager& meshInfoManager,
                    SolverDataStoresCreator& solverDataManager);

    std::unique_ptr<FieldCorrectorUPort> createPortU(std::string name);
    std::unique_ptr<FieldCorrectorVPort> createPortV(std::string name);
    std::unique_ptr<FieldCorrectorPPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
    MathToolsManager& mathToolsManager_;
    MeshInfoManager& meshInfoManager_;
    SolverDataStoresCreator& solverDataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORPORTS_H