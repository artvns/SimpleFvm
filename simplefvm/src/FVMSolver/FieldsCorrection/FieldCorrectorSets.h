#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_VELOCITYCORRECTORSETS_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_VELOCITYCORRECTORSETS_H

#include <memory>
#include <string>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "AbstractFieldCorrector.h"
#include "FieldCorrectorU.h"
#include "FieldCorrectorV.h"
#include "FieldCorrectorP.h"
#include "FieldCorrectorPorts.h"


namespace fvmsolver {

class FieldCorrectorSets {
private:
    using shPtrMapAbstFieldCorrector = std::shared_ptr<MapAdt<std::unique_ptr<AbstractFieldCorrector>>>;

public:
    FieldCorrectorSets(
                    DataManager& dataManager,
                    MeshInfoManager& meshInfoManager,
                    MathToolsManager& mathToolsManager,
                    SolverDataStoresCreator& solverDataManager);

    shPtrMapAbstFieldCorrector createSetU();
    shPtrMapAbstFieldCorrector createSetV();
    shPtrMapAbstFieldCorrector createSetP();

private:
    FieldCorrectorPorts dataPorts_;

    SetsCreator<AbstractFieldCorrector, FieldCorrectorPorts, FieldCorrectorU> setsMakerU_;
    SetsCreator<AbstractFieldCorrector, FieldCorrectorPorts, FieldCorrectorV> setsMakerV_;
    SetsCreator<AbstractFieldCorrector, FieldCorrectorPorts, FieldCorrectorP> setsMakerP_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_VELOCITYCORRECTORSETS_H