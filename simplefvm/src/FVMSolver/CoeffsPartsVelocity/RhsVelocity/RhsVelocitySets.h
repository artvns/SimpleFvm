#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVELOCITYSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVELOCITYSETS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "RhsVelocityDataPorts.h"
#include "AbstractRhsVelocity.h"
#include "RhsU.h"
#include "RhsV.h"


namespace fvmsolver {

class RhsVelocitySets {
private:
    using shPtrMapAbstRhsVelocity = std::shared_ptr<MapAdt<std::unique_ptr<AbstractRhsVelocity>>>;

public:
    RhsVelocitySets(DataManager& dataManager, 
                            MeshInfoManager& meshInfoManager);

    shPtrMapAbstRhsVelocity createSetForU();
    shPtrMapAbstRhsVelocity createSetForV();

private:
    RhsVelocityDataPorts dataPorts_;
    SetsCreator<AbstractRhsVelocity, RhsVelocityDataPorts, RhsU> setsMakerU_;
    SetsCreator<AbstractRhsVelocity, RhsVelocityDataPorts, RhsV> setsMakerV_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_RHSVELOCITY_RHSVELOCITYSETS_H