#include "SolverDataStoresCreator.h"

namespace fvmsolver {

SolverDataStoresCreator::SolverDataStoresCreator(
                    MeshInfoManager& meshInfoManager) : 
                            meshInfoManager_(meshInfoManager) {

}

void SolverDataStoresCreator::createStores() {
    createCoeffsCalculatorStore();
    createSavedCoeffsStore();
    createSavedRhsStore();
}

CoeffsCalculatorsStore& SolverDataStoresCreator::getCoeffsCalculatorsStore() {
    return coeffsCalculatorsStore_;
}

SavedCoeffsStore& SolverDataStoresCreator::getSavedCoeffsStoreU() {
    return savedCoeffsStoreU_;
}

SavedCoeffsStore& SolverDataStoresCreator::getSavedCoeffsStoreV() {
    return savedCoeffsStoreV_;
}

SavedCoeffsStore& SolverDataStoresCreator::getSavedCoeffsStoreP() {
    return savedCoeffsStoreP_;
}

SavedRhsStore& SolverDataStoresCreator::getSavedRhsStoreU() {
    return savedRhsStoreU_;
}

SavedRhsStore& SolverDataStoresCreator::getSavedRhsStoreV() {
    return savedRhsStoreV_;
}

SavedRhsStore& SolverDataStoresCreator::getSavedRhsStoreP() {
    return savedRhsStoreP_;
}

void SolverDataStoresCreator::createCoeffsCalculatorStore() {

    size_t sizeU = meshInfoManager_.getMeshInfoU()->getAllCellsAmount();
    size_t sizeV = meshInfoManager_.getMeshInfoV()->getAllCellsAmount();

    coeffsCalculatorsStore_.createArrays(sizeU, sizeV);
}

void SolverDataStoresCreator::createSavedCoeffsStore() {
    size_t sizeU = meshInfoManager_.getMeshInfoU()->getAllCellsAmount();
    size_t sizeV = meshInfoManager_.getMeshInfoV()->getAllCellsAmount();
    size_t sizeP = meshInfoManager_.getMeshInfoP()->getAllCellsAmount();

    savedCoeffsStoreU_.createArrays(sizeU);
    savedCoeffsStoreV_.createArrays(sizeV);
    savedCoeffsStoreP_.createArrays(sizeP);
}

void SolverDataStoresCreator::createSavedRhsStore() {
    size_t sizeU = meshInfoManager_.getMeshInfoU()->getAllCellsAmount();
    size_t sizeV = meshInfoManager_.getMeshInfoV()->getAllCellsAmount();
    size_t sizeP = meshInfoManager_.getMeshInfoP()->getAllCellsAmount();
     
    savedRhsStoreU_.createArrays(sizeU);
    savedRhsStoreV_.createArrays(sizeV);
    savedRhsStoreP_.createArrays(sizeP);
}

}