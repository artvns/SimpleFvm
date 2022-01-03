#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPARTSPRESSURECREATOR_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPARTSPRESSURECREATOR_H

#include <iostream>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPressure/CoeffsPress.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPressure/CoeffsPressSets.h"
#include "FVMSolver/CoeffsPartsPressure/RhsPressure/RhsPress.h"
#include "FVMSolver/CoeffsPartsPressure/RhsPressure/RhsPressSets.h"


namespace fvmsolver {

class CoeffsPartsPressureCreator {
private:
    using shPtrMapCoeffsPress = std::shared_ptr<MapAdt<std::unique_ptr<CoeffsPress>>>;
    using shPtrMapRhsPress = std::shared_ptr<MapAdt<std::unique_ptr<RhsPress>>>;

public:
    CoeffsPartsPressureCreator(
                        DataManager& dataManager, 
                        MeshInfoManager& meshInfoManager,
                        MathToolsManager& mathToolsManager,
                        SolverDataStoresCreator& solverDataManager);

    shPtrMapCoeffsPress getCoeffsPressSet();
    shPtrMapRhsPress getRhsPressSet();

private:
    CoeffsPressSets coeffsPressSets_;
    RhsPressSets rhsPressSets_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSPRESSURE_COEFFSPARTSPRESSURECREATOR_H