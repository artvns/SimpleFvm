#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_SOURCEDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_SOURCEDATAPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/BoundaryConditions/BcManager.h"

#include "AbstractSourcePort.h"
#include "StaticWallSourcePort.h"
#include "MovingWallSourcePort.h"


namespace fvmsolver {

class SourceDataPorts {
public:
    SourceDataPorts(DataManager& dataManager,BcManager& bcManager);

    std::unique_ptr<AbstractSourcePort> createPortU(std::string name);
    std::unique_ptr<AbstractSourcePort> createPortV(std::string name);

private:
    DataManager& dataManager_;
    BcManager& bcManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_SOURCETERM_SOURCEDATAPORTS_H