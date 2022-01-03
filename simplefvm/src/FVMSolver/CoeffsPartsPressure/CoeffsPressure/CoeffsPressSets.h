#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSSETS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSSETS_H

#include <string>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "CoeffsPress.h"
#include "CoeffsPressPorts.h"


namespace fvmsolver {

class CoeffsPressSets {
private:
    using shPtrMapCoeffsPress = std::shared_ptr<MapAdt<std::unique_ptr<CoeffsPress>>>;

public:
    CoeffsPressSets(DataManager& dataManager,
                    SolverDataStoresCreator& solverDataManager,
                    MeshInfoManager& meshInfoManager);

    shPtrMapCoeffsPress createSet();

private:
    CoeffsPressPorts dataPorts_;
    SetsCreator<CoeffsPress, CoeffsPressPorts, CoeffsPress> setsMaker_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPRESSURE_COEFFSPRESSSETS_H