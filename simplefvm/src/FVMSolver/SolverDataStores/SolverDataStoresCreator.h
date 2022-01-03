#ifndef SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SOLVERDATASTORESCREATOR_H
#define SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SOLVERDATASTORESCREATOR_H

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"
#include "FVMSolver/SolverDataStores/SavedCoeffsStore.h"
#include "FVMSolver/SolverDataStores/SavedRhsStore.h"


namespace fvmsolver {

class SolverDataStoresCreator {
public:
    SolverDataStoresCreator(MeshInfoManager& meshInfoManager);

    void createStores();

    CoeffsCalculatorsStore& getCoeffsCalculatorsStore();
    SavedCoeffsStore& getSavedCoeffsStoreU();
    SavedCoeffsStore& getSavedCoeffsStoreV();
    SavedCoeffsStore& getSavedCoeffsStoreP();
    SavedRhsStore& getSavedRhsStoreU();
    SavedRhsStore& getSavedRhsStoreV();
    SavedRhsStore& getSavedRhsStoreP();

private:
    MeshInfoManager& meshInfoManager_;

    CoeffsCalculatorsStore coeffsCalculatorsStore_;
    SavedCoeffsStore savedCoeffsStoreU_;
    SavedCoeffsStore savedCoeffsStoreV_;
    SavedCoeffsStore savedCoeffsStoreP_;
    SavedRhsStore savedRhsStoreU_;
    SavedRhsStore savedRhsStoreV_;
    SavedRhsStore savedRhsStoreP_;

    void createCoeffsCalculatorStore();
    void createSavedCoeffsStore();
    void createSavedRhsStore();
};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLVERDATASTORES_SOLVERDATASTORESCREATOR_H