#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_DATASTOREMASKS_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_DATASTOREMASKS_H

#include <string>

#include "DataStores/GlobalDataStores.h"
#include "MeshLoader/LoaderDataStores/MeshInformation.h"
#include "MeshLoader/DataStoresLoaderMasks/Fields/FieldsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshParameters/MeshParamsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshInformation/MeshInformationMask.h"
#include "MeshLoader/DataStoresLoaderMasks/AdjacentCellsType/AdjCellsTypeMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/CellNumsGlobalMask.h"
#include "MeshLoader/DataStoresLoaderMasks/ResultsData/MeshBuildingMask.h"

#include "SingleMasks.h"
#include "SetsOfMasks.h"


namespace meshloader {

class DataStoreMasks {
public:
    DataStoreMasks(datastores::GlobalDataStores& dataStores, 
                    const MeshInformation& meshInfoU, 
                    const MeshInformation& meshInfoV, 
                    const MeshInformation& meshInfoP);

    void createDataMasks();

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

    CellNumsGlobalMask&         getCellNumsGlobalUMask(std::string partName);
    CellNumsGlobalMask&         getCellNumsGlobalVMask(std::string partName);
    CellNumsGlobalMask&         getCellNumsGlobalPMask(std::string partName);
    AdjCellGlobalNumsUMask&     getAdjCellGlobalNumsUMask(std::string partName);
    AdjCellGlobalNumsVMask&     getAdjCellGlobalNumsVMask(std::string partName);
    AdjCellGlobalNumsPMask&     getAdjCellGlobalNumsPMask(std::string partName);
    CellNumsInteriorMask&       getCellInterNumsUMask(std::string partName);
    CellNumsInteriorMask&       getCellInterNumsVMask(std::string partName);
    CellNumsInteriorMask&       getCellInterNumsPMask(std::string partName);
    AdjCellInteriorNumsUMask&   getAdjCellInterNumsUMask(std::string partName);
    AdjCellInteriorNumsVMask&   getAdjCellInterNumsVMask(std::string partName);
    AdjCellInteriorNumsPMask&   getAdjCellInterNumsPMask(std::string partName);

private:
    datastores::GlobalDataStores& dataStores_;
    const MeshInformation& meshInfoU_; 
    const MeshInformation& meshInfoV_; 
    const MeshInformation& meshInfoP_;

    SingleMasks singleMasks_;
    SetsOfMasks setsOfMasks_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_DATASTOREMASKS_H