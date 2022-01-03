#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_FLUXDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_FLUXDATAPORTS_H

#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"

#include "UFluxPort.h"
#include "VFluxPort.h"


namespace fvmsolver {

class FluxDataPorts {
public:
    FluxDataPorts(DataManager& dataManager);

    std::unique_ptr<UFluxPort> createPortU(std::string name);
    std::unique_ptr<VFluxPort> createPortV(std::string name);
 
private:
    DataManager& dataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_FLUX_FLUXDATAPORTS_H