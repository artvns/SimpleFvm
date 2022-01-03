#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONSETS_H

#include <string>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "DiffusionDataPorts.h"
#include "AbstractDiffusion.h"
#include "UDiffusion.h"
#include "VDiffusion.h"


namespace fvmsolver {

class DiffusionSets {
private:
    using shPtrMapAbstDiffusion = std::shared_ptr<MapAdt<std::unique_ptr<AbstractDiffusion>>>;

public:
    DiffusionSets(DataManager& dataManager, 
                            MeshInfoManager& meshInfoManager);

    shPtrMapAbstDiffusion createSetForU();
    shPtrMapAbstDiffusion createSetForV();

private:
    DiffusionDataPorts dataPorts_;
    SetsCreator<AbstractDiffusion, DiffusionDataPorts, UDiffusion> setsMakerU_;
    SetsCreator<AbstractDiffusion, DiffusionDataPorts, VDiffusion> setsMakerV_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONSETS_H