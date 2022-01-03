#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONDATAPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"

#include "DiffusionPort.h"


namespace fvmsolver {

class DiffusionDataPorts {
public:
    DiffusionDataPorts(DataManager& dataManager);

    std::unique_ptr<DiffusionPort> createPortU(std::string name);
    std::unique_ptr<DiffusionPort> createPortV(std::string name);

private:
    DataManager& dataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_DIFFUSION_DIFFUSIONDATAPORTS_H