#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_SOURCESETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_SOURCESETS_H

#include <cstddef>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/BoundaryConditions/BcManager.h"

#include "SourceDataPorts.h"
#include "AbstractSource.h"
#include "InteriorSource.h"
#include "MovingWallSource.h"
#include "StaticWallSource.h"


namespace fvmsolver {

class SourceSets {
private:
    using shPtrMapAbstSource = std::shared_ptr<MapAdt<std::unique_ptr<AbstractSource>>>;

public:
    SourceSets(DataManager& dataManager, 
                MeshInfoManager& meshInfoManager, 
                BcManager& bcManager);

    shPtrMapAbstSource createSetForU();
    shPtrMapAbstSource createSetForV();

private:
    SourceDataPorts dataPorts_;
    MeshInfoManager& meshInfoManager_;

    shPtrMapAbstSource pSourceSetU_ = nullptr;
    shPtrMapAbstSource pSourceSetV_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_SOURCESETS_H