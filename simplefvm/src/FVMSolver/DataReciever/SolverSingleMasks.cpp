#include "SolverSingleMasks.h"

namespace fvmsolver {

SolverSingleMasks::SolverSingleMasks(
    datastores::GlobalDataStores& dataStores) :
            fieldsMask_(dataStores.getFieldsStore()),
            fluidPropertiesMask_(dataStores.getFluidPropertiesStore()),
            meshParamsMaskP_(dataStores.getMeshParametersStoreP()),
            meshParamsMaskU_(dataStores.getMeshParametersStoreU()),
            meshParamsMaskV_(dataStores.getMeshParametersStoreV()),
            meshInformationMaskP_(dataStores.getMeshInfoStoreP()),
            meshInformationMaskU_(dataStores.getMeshInfoStoreU()),
            meshInformationMaskV_(dataStores.getMeshInfoStoreV()),
            adjCellsTypeMaskP_(dataStores.getAdjCellsTypeStoreU()),
            adjCellsTypeMaskU_(dataStores.getAdjCellsTypeStoreV()),
            adjCellsTypeMaskV_(dataStores.getAdjCellsTypeStoreP()) {

}


SolverFieldsMask& SolverSingleMasks::getFieldsMask() {
    return fieldsMask_;
}

SolverFluidPropsMask& SolverSingleMasks::getFluidPropertiesMask() {
    return fluidPropertiesMask_;
}

SolverMeshParamsMask& SolverSingleMasks::getMeshParametersMaskP() {
    return meshParamsMaskP_;
}
SolverMeshParamsMask& SolverSingleMasks::getMeshParametersMaskU() {
    return meshParamsMaskU_;
}
SolverMeshParamsMask& SolverSingleMasks::getMeshParametersMaskV() {
    return meshParamsMaskV_;
}

SolverMeshInfoMask& SolverSingleMasks::getMeshInfoMaskP() {
    return meshInformationMaskP_;
}
SolverMeshInfoMask& SolverSingleMasks::getMeshInfoMaskU() {
    return meshInformationMaskU_;
}
SolverMeshInfoMask& SolverSingleMasks::getMeshInfoMaskV() {
    return meshInformationMaskV_;
}

SolverAdjCellsTypeMask& SolverSingleMasks::getAdjCellTypesMaskU() {
    return adjCellsTypeMaskP_;
}
SolverAdjCellsTypeMask& SolverSingleMasks::getAdjCellTypesMaskV() {
    return adjCellsTypeMaskU_;
}
SolverAdjCellsTypeMask& SolverSingleMasks::getAdjCellTypesMaskP() {
    return adjCellsTypeMaskV_;
}

}