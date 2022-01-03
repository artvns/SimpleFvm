#include "CoeffsPartsVelocityCreator.h"

namespace fvmsolver {

CoeffsPartsVelocityCreator::CoeffsPartsVelocityCreator(
        DataManager& dataManager,
        MeshInfoManager& meshInfoManager,
        BcManager& bcManager,
        Config& config) :
            diffusionSets_(dataManager, meshInfoManager),
            fluxSets_(dataManager, meshInfoManager),
            sourceSets_(dataManager, meshInfoManager, bcManager),
            schemeCreator_(config),
            rhsVelocitySets_(dataManager, meshInfoManager) {

}

CoeffsPartsVelocityCreator::shPtrMapAbstDiffusion CoeffsPartsVelocityCreator::getDiffusionSetU() {
    return diffusionSets_.createSetForU();
}

CoeffsPartsVelocityCreator::shPtrMapAbstDiffusion CoeffsPartsVelocityCreator::getDiffusionSetV() {
    return diffusionSets_.createSetForV();
}

CoeffsPartsVelocityCreator::shPtrMapAbstFlux CoeffsPartsVelocityCreator::getFluxSetU() {
    return fluxSets_.createSetForU();
}

CoeffsPartsVelocityCreator::shPtrMapAbstFlux CoeffsPartsVelocityCreator::getFluxSetV() {
    return fluxSets_.createSetForV();
}

CoeffsPartsVelocityCreator::shPtrMapAbstSource CoeffsPartsVelocityCreator::getSourceSetU() {
    return sourceSets_.createSetForU();
}

CoeffsPartsVelocityCreator::shPtrMapAbstSource CoeffsPartsVelocityCreator::getSourceSetV() {
    return sourceSets_.createSetForV();
}

std::shared_ptr<IDifferencingScheme> CoeffsPartsVelocityCreator::getDifferencingScheme() {
    return schemeCreator_.create();
}

CoeffsPartsVelocityCreator::shPtrMapAbstRhsVelocity CoeffsPartsVelocityCreator::getRhsSetU() {
    return rhsVelocitySets_.createSetForU();
}

CoeffsPartsVelocityCreator::shPtrMapAbstRhsVelocity CoeffsPartsVelocityCreator::getRhsSetV() {
    return rhsVelocitySets_.createSetForV();
}

}