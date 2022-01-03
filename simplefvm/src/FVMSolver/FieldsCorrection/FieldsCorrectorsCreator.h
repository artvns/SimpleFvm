#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDSCORRECTORSCREATOR_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDSCORRECTORSCREATOR_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/FieldsCorrection/FieldCorrector.h"
#include "FVMSolver/FieldsCorrection/FieldCorrectorSets.h"


namespace fvmsolver {

class FieldsCorrectorsCreator {
public:
    FieldsCorrectorsCreator(
                        DataManager& dataManager, 
                        MeshInfoManager& meshInfoManager,
                        MathToolsManager& mathToolsManager,
                        SolverDataStoresCreator& solverDataManager);

    std::shared_ptr<FieldCorrector> createFiledCorrectorU();
    std::shared_ptr<FieldCorrector> createFiledCorrectorV();
    std::shared_ptr<FieldCorrector> createFiledCorrectorP();

private:
    FieldCorrectorSets fieldCorrectorSets_;
    MeshInfoManager& meshInfoManager_;

    std::shared_ptr<FieldCorrector> spFieldCorrectorU_ = nullptr;
    std::shared_ptr<FieldCorrector> spFieldCorrectorV_ = nullptr;
    std::shared_ptr<FieldCorrector> spFieldCorrectorP_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDSCORRECTORSCREATOR_H