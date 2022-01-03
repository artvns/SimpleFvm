#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_FLUXSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_FLUXSETS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "FluxDataPorts.h"
#include "AbstractFlux.h"
#include "UFlux.h"
#include "VFlux.h"


namespace fvmsolver {

class FluxSets {
private:
    using shPtrMapAbstFlux = std::shared_ptr<MapAdt<std::unique_ptr<AbstractFlux>>>;

public:
    FluxSets(DataManager& dataManager, 
                            MeshInfoManager& meshInfoManager);

    shPtrMapAbstFlux createSetForU();
    shPtrMapAbstFlux createSetForV();

private:
    FluxDataPorts dataPorts_;
    SetsCreator<AbstractFlux, FluxDataPorts, UFlux> setsMakerU_;
    SetsCreator<AbstractFlux, FluxDataPorts, VFlux> setsMakerV_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_FLUXSETS_H