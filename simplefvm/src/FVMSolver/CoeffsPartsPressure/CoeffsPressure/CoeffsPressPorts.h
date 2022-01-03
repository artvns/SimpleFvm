#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSPORTS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSPORTS_H

#include <iostream>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "CoeffsPressPort.h"


namespace fvmsolver {

class CoeffsPressPorts {
public:
    CoeffsPressPorts(DataManager& dataManager, 
                        SolverDataStoresCreator& solverDataManager);

    std::unique_ptr<CoeffsPressPort> createPortP(std::string name);

private:
    DataManager& dataManager_;
    SolverDataStoresCreator& solverDataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSPORTS_H