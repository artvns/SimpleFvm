#ifndef SIMPLEFVM_FVMSOLVER_SOLVERCONFIGURATION_H
#define SIMPLEFVM_FVMSOLVER_SOLVERCONFIGURATION_H

#include <memory>

#include "FVMSolver/SolverSettings/Config.h"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/BoundaryConditions/BcManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/MathToolsManager.h"
#include "FVMSolver/SolutionAlgorithms/AlgorithmCreator.h"
#include "FVMSolver/SolutionAlgorithms/AlgorithmBuilderSimple.h"
#include "FVMSolver/SolutionAlgorithms/Algorithms/AbstractAlgorithm.h"
#include "FVMSolver/MatrixBuilder/SleMatrixBuilderCreator.h"
#include "FVMSolver/Sle/ScalarCalculatorCreator.h"
#include "FVMSolver/CoeffsPartsCommon/CoeffsPartsCommonCreator.h"
#include "FVMSolver/CoeffsPartsVelocity/CoeffsPartsVelocityCreator.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPartsPressureCreator.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"
#include "FVMSolver/FieldsCorrection/FieldsCorrectorsCreator.h"
#include "FVMSolver/ResidualsCalculation/ResidsCalculatorsCreator.h"
#include "FVMSolver/FieldsInterpolation/FieldsInterpolatorsCreator.h"
#include "FVMSolver/ResidualsOutput/ResidsOutputerCreator.h"


namespace fvmsolver {

class SolverConfiguration {
public:
    SolverConfiguration(Config& config,
                        MathToolsManager& mathToolsManager,
                        DataManager& dataManager,
                        BcManager& bcManager,
                        SolverDataStoresCreator& solverDataStores,
                        MeshInfoManager& meshInfoManager);

    void configureAlgorithmComponents();
    void configureAlgorithm();
    void calculate();

private:
    CoeffsPartsCommonCreator        coeffsPartsCommon_;
    CoeffsPartsVelocityCreator      coeffsPartsVelocity_;
    CoeffsPartsPressureCreator      coeffsPartsPressure_;
    SleMatrixBuilderCreator         sleMatrixBuilderCreator_;
    ResidsCalculatorsCreator        residsCalculatorsCreator_;
    ScalarCalculatorCreator         scalarCalculatorCreator_;
    FieldsCorrectorsCreator         fieldsCorrectorsCreator_;
    AlgorithmBuilderSimple          simpleBuilder_;
    FieldsInterpolatorsCreator      fieldsInterpolatorsCreator_;
    AlgorithmCreator                algorithmCreator_;
    ResidsOutputerCreator           residsOutputerCreator_;

    std::shared_ptr<AbstractAlgorithm> pAlgorithm_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERCONFIGURATION_H