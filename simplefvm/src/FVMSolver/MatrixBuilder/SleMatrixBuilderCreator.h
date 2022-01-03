#ifndef SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERCREATOR_H
#define SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERCREATOR_H

#include <iostream>

#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/CoeffsPartsCommon/CoeffsPartsCommonCreator.h"
#include "FVMSolver/CoeffsPartsVelocity/CoeffsPartsVelocityCreator.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPartsPressureCreator.h"
#include "FVMSolver/CoeffsCalculators/CoeffsCalculatorCreator.h"
#include "FVMSolver/CoeffsCalculators/CoeffsCalculatorVelocityBuilder.h"
#include "FVMSolver/CoeffsCalculators/CoeffsCalculatorPressureBuilder.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "SleMatrixBuilderDataPorts.h"
#include "SleMatrixBuilder.h"


namespace fvmsolver {

class SleMatrixBuilderCreator {
public:
    SleMatrixBuilderCreator(MeshInfoManager& meshInfoManager,
                            SolverDataStoresCreator& solverDataStores,
                            CoeffsPartsCommonCreator& coeffsPartsCommon, 
                            CoeffsPartsVelocityCreator& coeffsPartsVelocity,
                            CoeffsPartsPressureCreator& coeffsPartsPressure);

    std::shared_ptr<SleMatrixBuilder> createUStarBuilder();
    std::shared_ptr<SleMatrixBuilder> createVStarBuilder();
    std::shared_ptr<SleMatrixBuilder> createPPrimeBuilder();

private:
    SleMatrixBuilderDataPorts dataPorts_;
    CoeffsCalculatorVelocityBuilder uVelocityBuilder_;
    CoeffsCalculatorVelocityBuilder vVelocityBuilder_;
    CoeffsCalculatorPressureBuilder pressureBuilder_;
    
    CoeffsCalculatorCreator coeffsCalcCreator_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERCREATOR_H