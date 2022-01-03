#include "SingleMasks.h"

namespace meshloader {


SingleMasks::SingleMasks(
    datastores::GlobalDataStores& dataStores) :
            stateFlagsMask_(dataStores.getSolverStateFlags()),
            fieldsMask_(dataStores.getFieldsStore()),
            meshParamsMaskP_(dataStores.getMeshParametersStoreP()),
            meshParamsMaskU_(dataStores.getMeshParametersStoreU()),
            meshParamsMaskV_(dataStores.getMeshParametersStoreV()),
            meshInformationMaskP_(dataStores.getMeshInfoStoreP()),
            meshInformationMaskU_(dataStores.getMeshInfoStoreU()),
            meshInformationMaskV_(dataStores.getMeshInfoStoreV()),
            adjCellsTypeMaskP_(dataStores.getAdjCellsTypeStoreU()),
            adjCellsTypeMaskU_(dataStores.getAdjCellsTypeStoreV()),
            adjCellsTypeMaskV_(dataStores.getAdjCellsTypeStoreP()),
            meshBuildingMask_(dataStores.getMeshBuildingStore()) {

}


StateFlagsMask& SingleMasks::getStateFlagsMask() {
    return stateFlagsMask_;
}

FieldsMask& SingleMasks::getFieldsMask() {
    return fieldsMask_;
}

MeshParamsMask& SingleMasks::getMeshParametersMaskP() {
    return meshParamsMaskP_;
}
MeshParamsMask& SingleMasks::getMeshParametersMaskU() {
    return meshParamsMaskU_;
}
MeshParamsMask& SingleMasks::getMeshParametersMaskV() {
    return meshParamsMaskV_;
}

MeshInformationMask& SingleMasks::getMeshInfoMaskP() {
    return meshInformationMaskP_;
}
MeshInformationMask& SingleMasks::getMeshInfoMaskU() {
    return meshInformationMaskU_;
}
MeshInformationMask& SingleMasks::getMeshInfoMaskV() {
    return meshInformationMaskV_;
}

AdjCellsTypeMask& SingleMasks::getAdjCellTypesMaskU() {
    return adjCellsTypeMaskP_;
}
AdjCellsTypeMask& SingleMasks::getAdjCellTypesMaskV() {
    return adjCellsTypeMaskU_;
}
AdjCellsTypeMask& SingleMasks::getAdjCellTypesMaskP() {
    return adjCellsTypeMaskV_;
}

MeshBuildingMask& SingleMasks::getMeshBuildingMask() {
    return meshBuildingMask_;
}

}