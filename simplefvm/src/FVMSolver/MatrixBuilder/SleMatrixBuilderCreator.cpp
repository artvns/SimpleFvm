#include "SleMatrixBuilderCreator.h"

namespace fvmsolver {

SleMatrixBuilderCreator::SleMatrixBuilderCreator(
    MeshInfoManager& meshInfoManager,
    SolverDataStoresCreator& solverDataStores, 
    CoeffsPartsCommonCreator& coeffsPartsCommon, 
    CoeffsPartsVelocityCreator& coeffsPartsVelocity,
    CoeffsPartsPressureCreator& coeffsPartsPressure) :
            dataPorts_           (meshInfoManager, solverDataStores),
            uVelocityBuilder_    (coeffsPartsCommon, coeffsPartsVelocity),
            vVelocityBuilder_    (coeffsPartsCommon, coeffsPartsVelocity),
            pressureBuilder_     (coeffsPartsCommon, coeffsPartsPressure) {

}

std::shared_ptr<SleMatrixBuilder> SleMatrixBuilderCreator::createUStarBuilder() {
    return std::shared_ptr<SleMatrixBuilder>(
                new SleMatrixBuilder(
                    *coeffsCalcCreator_.createForU(uVelocityBuilder_),
                    dataPorts_.createPortU()));
}

std::shared_ptr<SleMatrixBuilder> SleMatrixBuilderCreator::createVStarBuilder() {
    return std::shared_ptr<SleMatrixBuilder>(
                new SleMatrixBuilder(
                    *coeffsCalcCreator_.createForV(vVelocityBuilder_),
                    dataPorts_.createPortV()));
}

std::shared_ptr<SleMatrixBuilder> SleMatrixBuilderCreator::createPPrimeBuilder() {
    return std::shared_ptr<SleMatrixBuilder>(
                new SleMatrixBuilder(
                    *coeffsCalcCreator_.createForP(pressureBuilder_),
                    dataPorts_.createPortP()));
}

}