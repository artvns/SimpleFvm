#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_SETSOFMASKS_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_SETSOFMASKS_H

#include <cstddef>
#include <string>
#include <map>
#include <memory>
#include <iterator>
#include <algorithm>

#include "DataStores/GlobalDataStores.h"
#include "MeshLoader/LoaderDataStores/MeshInformation.h"
#include "MeshLoader/DataStoresLoaderMasks/Fields/FieldsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshParameters/MeshParamsMask.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshInformation/MeshInformationMask.h"
#include "MeshLoader/DataStoresLoaderMasks/AdjacentCellsType/AdjCellsTypeMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/CellNumsGlobalMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/AdjCellGlobalNumsUMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/AdjCellGlobalNumsVMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/AdjCellGlobalNumsPMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/CellNumsInteriorMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/AdjCellInteriorNumsUMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/AdjCellInteriorNumsVMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/AdjCellInteriorNumsPMask.h"

#include "SingleMasks.h"


namespace meshloader {

class SetsOfMasks {
private:
    using mapCellNumsGlobalMask = std::map<std::string, std::unique_ptr<CellNumsGlobalMask>>;
    using mapCellNumsInteriorMask = std::map<std::string, std::unique_ptr<CellNumsInteriorMask>>;
    using mapAdjCellGlobalNumsUMask = std::map<std::string, std::unique_ptr<AdjCellGlobalNumsUMask>>;
    using mapAdjCellGlobalNumsVMask = std::map<std::string, std::unique_ptr<AdjCellGlobalNumsVMask>>;
    using mapAdjCellGlobalNumsPMask = std::map<std::string, std::unique_ptr<AdjCellGlobalNumsPMask>>;
    using mapAdjCellInteriorNumsUMask = std::map<std::string, std::unique_ptr<AdjCellInteriorNumsUMask>>;
    using mapAdjCellInteriorNumsVMask = std::map<std::string, std::unique_ptr<AdjCellInteriorNumsVMask>>;
    using mapAdjCellInteriorNumsPMask = std::map<std::string, std::unique_ptr<AdjCellInteriorNumsPMask>>;

public:
    SetsOfMasks();

    void clearSets(datastores::GlobalDataStores& dataStores);

    void createMaskSetsU(datastores::GlobalDataStores& dataStores, 
                                        const MeshInformation& meshInfoU);

    void createMaskSetsV(datastores::GlobalDataStores& dataStores, 
                                        const MeshInformation& meshInfoV);

    void createMaskSetsP(datastores::GlobalDataStores& dataStores, 
                                        const MeshInformation& meshInfoP);

    CellNumsGlobalMask& getCellNumsGlobalUMask(std::string partName);
    CellNumsGlobalMask& getCellNumsGlobalVMask(std::string partName);
    CellNumsGlobalMask& getCellNumsGlobalPMask(std::string partName);

    AdjCellGlobalNumsUMask& getAdjCellGlobalNumsUMask(std::string partName);
    AdjCellGlobalNumsVMask& getAdjCellGlobalNumsVMask(std::string partName);
    AdjCellGlobalNumsPMask& getAdjCellGlobalNumsPMask(std::string partName);

    CellNumsInteriorMask& getCellInterNumsUMask(std::string partName);
    CellNumsInteriorMask& getCellInterNumsVMask(std::string partName);
    CellNumsInteriorMask& getCellInterNumsPMask(std::string partName);

    AdjCellInteriorNumsUMask& getAdjCellInterNumsUMask(std::string partName);
    AdjCellInteriorNumsVMask& getAdjCellInterNumsVMask(std::string partName);
    AdjCellInteriorNumsPMask& getAdjCellInterNumsPMask(std::string partName);

private:
    mapCellNumsGlobalMask mapCellNumsGlobalU_;
    mapCellNumsGlobalMask mapCellNumsGlobalV_;
    mapCellNumsGlobalMask mapCellNumsGlobalP_;

    mapCellNumsInteriorMask mapCellNumsInteriorU_;
    mapCellNumsInteriorMask mapCellNumsInteriorV_;
    mapCellNumsInteriorMask mapCellNumsInteriorP_;

    mapAdjCellGlobalNumsUMask mapAdjCellGlobalNumsU_;
    mapAdjCellGlobalNumsVMask mapAdjCellGlobalNumsV_;
    mapAdjCellGlobalNumsPMask mapAdjCellGlobalNumsP_;

    mapAdjCellInteriorNumsUMask mapAdjCellInteriorNumsU_;
    mapAdjCellInteriorNumsVMask mapAdjCellInteriorNumsV_;
    mapAdjCellInteriorNumsPMask mapAdjCellInteriorNumsP_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_SETSOFMASKS_H