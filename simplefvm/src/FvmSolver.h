#ifndef SIMPLEFVM_FVMSOLVER_H
#define SIMPLEFVM_FVMSOLVER_H

#include <memory>
#include <string>

#include "DataStores/GlobalDataStores.h"
#include "FVMSolver/Solver.h"
#include "ResultsSaver/Saver.h"

#include "SolverAlgorithmChooser.h"
#include "SolverSchemeChooser.h"
#include "SolverSleSolverChooser.h"
#include "SolverPartTypeChooser.h"
#include "SolverFluidPropsDefiner.h"
#include "SolverMeshLoader.h"
#include "SolverFVMSolver.h"
#include "SolverResultsSaver.h"
#include "SolverResidualsSettingsDefiner.h"


namespace mainsolver {

class FvmSolver {
public:
    FvmSolver();
    ~FvmSolver();

    void setAlgorithm(SolverAlgorithmChooser& algirithm);
    void setScheme(SolverSchemeChooser& scheme);
    void setSleSolver(SolverSleSolverChooser& sleSolver);
    void setFluidProps(SolverFluidPropsDefiner& fluidPropsDefiner);
    void setBoundaryConditions(SolverPartTypeChooser& bc);
    void setResidualsSettings(SolverResidualsSettingsDefiner& residsSettings);
    
    SolverMeshLoader& getSolverMeshLoader();
    SolverFVMSolver& getSolverFVMSolver();
    SolverResultsSaver& getSolverResultsSaver();

private:
    datastores::GlobalDataStores dataStores_;
    fvmsolver::Solver solver_;

    SolverMeshLoader solverMeshLoader_;
    SolverFVMSolver solverFVMSolver_;
    SolverResultsSaver solverResultsSaver_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_H