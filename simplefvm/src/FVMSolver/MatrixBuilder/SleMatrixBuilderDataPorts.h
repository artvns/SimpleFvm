#ifndef SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERDATAPORTS_H
#define SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERDATAPORTS_H

#include "FVMSolver/MeshInformation/MeshInfo.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/SolverDataStoresCreator.h"

#include "SleMatrixBuilderPort.h"


namespace fvmsolver {

class SleMatrixBuilderDataPorts {
public:
    SleMatrixBuilderDataPorts(MeshInfoManager& meshInfoManager, 
                        SolverDataStoresCreator& solverDataStores);

    std::unique_ptr<SleMatrixBuilderPort> createPortU();
    std::unique_ptr<SleMatrixBuilderPort> createPortV();
    std::unique_ptr<SleMatrixBuilderPort> createPortP();

private:
    MeshInfoManager& meshInfoManager_;
    SolverDataStoresCreator& solverDataStores_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERDATAPORTS_H