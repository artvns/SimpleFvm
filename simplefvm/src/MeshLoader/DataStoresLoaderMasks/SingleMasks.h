#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_SINGLEMASKS_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_SINGLEMASKS_H

#include <string>

#include "DataStores/GlobalDataStores.h"
#include "MeshLoader/DataStoresLoaderMasks/StateFlags/StateFlagsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/Fields/FieldsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshParameters/MeshParamsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshInformation/MeshInformationMask.h"
#include "MeshLoader/DataStoresLoaderMasks/AdjacentCellsType/AdjCellsTypeMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/CellNumsGlobalMask.h"
#include "MeshLoader/DataStoresLoaderMasks/ResultsData/MeshBuildingMask.h"


namespace meshloader {

class SingleMasks {
public:
    SingleMasks(datastores::GlobalDataStores& dataStores);

    StateFlagsMask&         getStateFlagsMask();
    FieldsMask&             getFieldsMask();
    MeshParamsMask&         getMeshParametersMaskP();
    MeshParamsMask&         getMeshParametersMaskU();
    MeshParamsMask&         getMeshParametersMaskV();
    MeshInformationMask&    getMeshInfoMaskP();
    MeshInformationMask&    getMeshInfoMaskU();
    MeshInformationMask&    getMeshInfoMaskV();
    AdjCellsTypeMask&       getAdjCellTypesMaskU();
    AdjCellsTypeMask&       getAdjCellTypesMaskV();
    AdjCellsTypeMask&       getAdjCellTypesMaskP();
    MeshBuildingMask&       getMeshBuildingMask();

private:
    StateFlagsMask          stateFlagsMask_;
    FieldsMask              fieldsMask_;
    MeshParamsMask          meshParamsMaskP_;
    MeshParamsMask          meshParamsMaskU_;
    MeshParamsMask          meshParamsMaskV_;
    MeshInformationMask     meshInformationMaskP_;
    MeshInformationMask     meshInformationMaskU_;
    MeshInformationMask     meshInformationMaskV_;
    AdjCellsTypeMask        adjCellsTypeMaskP_;
    AdjCellsTypeMask        adjCellsTypeMaskU_;
    AdjCellsTypeMask        adjCellsTypeMaskV_;
    MeshBuildingMask        meshBuildingMask_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_SINGLEMASKS_H