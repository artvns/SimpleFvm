#ifndef SIMPLEFVM_DATASTORES_GLOBALDATASTORES_H
#define SIMPLEFVM_DATASTORES_GLOBALDATASTORES_H

#include <memory>
#include <string>

#include "Adt/MapAdt.cpp"
#include "StateFlags/SolverStateFlagsStore.cpp"
#include "AdjCellNumsGlobalStores/AdjCellGlobalNumsUStore.h"
#include "AdjCellNumsGlobalStores/AdjCellGlobalNumsVStore.h"
#include "AdjCellNumsGlobalStores/AdjCellGlobalNumsPStore.h"
#include "AdjCellsTypeStores/AdjCellsTypeStore.h"
#include "CellNumsInteriorStores/CellNumsInteriorStore.h"
#include "CellNumsInteriorStores/AdjCellInteriorNumsUStore.h"
#include "CellNumsInteriorStores/AdjCellInteriorNumsVStore.h"
#include "CellNumsInteriorStores/AdjCellInteriorNumsPStore.h"
#include "CellNumsGlobalStores/CellNumsGlobalStore.h"
#include "FieldsStores/FieldsStore.h"
#include "FluidPropertiesStores/FluidPropertiesStore.h"
#include "MeshParametersStores/MeshParametersStore.h"
#include "MeshInformationStore/MeshInfoStore.h"
#include "ResultsDataStores/MeshBuildingStore.h"


namespace datastores {

class GlobalDataStores {
private:
    using uPtrCellNumsGlobalStore = std::unique_ptr<CellNumsGlobalStore>;
    using uPtrAdjCellGlobalNumsUStore = std::unique_ptr<AdjCellGlobalNumsUStore>;
    using uPtrAdjCellGlobalNumsVStore = std::unique_ptr<AdjCellGlobalNumsVStore>;
    using uPtrAdjCellGlobalNumsPStore = std::unique_ptr<AdjCellGlobalNumsPStore>;
    using uPtrCellNumsInteriorStore = std::unique_ptr<CellNumsInteriorStore>;
    using uPtrAdjCellInteriorNumsUStore = std::unique_ptr<AdjCellInteriorNumsUStore>;
    using uPtrAdjCellInteriorNumsVStore = std::unique_ptr<AdjCellInteriorNumsVStore>;
    using uPtrAdjCellInteriorNumsPStore = std::unique_ptr<AdjCellInteriorNumsPStore>;

public:
    GlobalDataStores();

    void clearSets();

    SolverStateFlagsStore& getSolverStateFlags();
    FieldsStore& getFieldsStore();
    FluidPropertiesStore& getFluidPropertiesStore();
    MeshParametersStore& getMeshParametersStoreP();
    MeshParametersStore& getMeshParametersStoreU();
    MeshParametersStore& getMeshParametersStoreV();
    MeshInfoStore& getMeshInfoStoreP();
    MeshInfoStore& getMeshInfoStoreU();
    MeshInfoStore& getMeshInfoStoreV();
    AdjCellsTypeStore& getAdjCellsTypeStoreP();
    AdjCellsTypeStore& getAdjCellsTypeStoreU();
    AdjCellsTypeStore& getAdjCellsTypeStoreV();

    CellNumsGlobalStore& getCellNumsGlobalSetsU(std::string partName);
    CellNumsGlobalStore& getCellNumsGlobalSetsV(std::string partName);
    CellNumsGlobalStore& getCellNumsGlobalSetsP(std::string partName);

    CellNumsInteriorStore& getCellNumsInteriorSetsU(std::string partName);
    CellNumsInteriorStore& getCellNumsInteriorSetsV(std::string partName);
    CellNumsInteriorStore& getCellNumsInteriorSetsP(std::string partName);

    AdjCellGlobalNumsUStore& getAdjCellGlobalNumsSetsU(std::string partName);
    AdjCellGlobalNumsVStore& getAdjCellGlobalNumsSetsV(std::string partName);
    AdjCellGlobalNumsPStore& getAdjCellGlobalNumsSetsP(std::string partName);

    AdjCellInteriorNumsUStore& getAdjCellInterNumsSetsU(std::string partName);
    AdjCellInteriorNumsVStore& getAdjCellInterNumsSetsV(std::string partName);
    AdjCellInteriorNumsPStore& getAdjCellInterNumsSetsP(std::string partName);

    MeshBuildingStore& getMeshBuildingStore();

    void createCellNumsGlobalU(std::string partName);
    void createCellNumsGlobalV(std::string partName);
    void createCellNumsGlobalP(std::string partName);

    void createCellNumsInteriorU(std::string partName);
    void createCellNumsInteriorV(std::string partName);
    void createCellNumsInteriorP(std::string partName);

    void createAdjCellGlobalNumsU(std::string partName);
    void createAdjCellGlobalNumsV(std::string partName);
    void createAdjCellGlobalNumsP(std::string partName);

    void createAdjCellInterNumsU(std::string partName);
    void createAdjCellInterNumsV(std::string partName);
    void createAdjCellInterNumsP(std::string partName);

private:
    SolverStateFlagsStore solverStateFlagsStore_;
    FieldsStore fieldsStore_;
    FluidPropertiesStore fluidPropertiesStore_;
    MeshParametersStore meshParametersStoreP_;
    MeshParametersStore meshParametersStoreU_;
    MeshParametersStore meshParametersStoreV_;
    MeshInfoStore meshInfoStoreP_;
    MeshInfoStore meshInfoStoreU_;
    MeshInfoStore meshInfoStoreV_;
    AdjCellsTypeStore adjCellsTypeStoreP_;
    AdjCellsTypeStore adjCellsTypeStoreU_;
    AdjCellsTypeStore adjCellsTypeStoreV_;
 
    MapAdt<uPtrCellNumsGlobalStore> cellNumsGlobalSetsU_;
    MapAdt<uPtrCellNumsGlobalStore> cellNumsGlobalSetsV_;
    MapAdt<uPtrCellNumsGlobalStore> cellNumsGlobalSetsP_;

    MapAdt<uPtrCellNumsInteriorStore> cellNumsInteriorSetsU_;
    MapAdt<uPtrCellNumsInteriorStore> cellNumsInteriorSetsV_;
    MapAdt<uPtrCellNumsInteriorStore> cellNumsInteriorSetsP_;

    MapAdt<uPtrAdjCellGlobalNumsUStore> adjCellGlobalNumsSetsU_;
    MapAdt<uPtrAdjCellGlobalNumsVStore> adjCellGlobalNumsSetsV_;
    MapAdt<uPtrAdjCellGlobalNumsPStore> adjCellGlobalNumsSetsP_;

    MapAdt<uPtrAdjCellInteriorNumsUStore> adjCellInterNumsSetsU_;
    MapAdt<uPtrAdjCellInteriorNumsVStore> adjCellInterNumsSetsV_;
    MapAdt<uPtrAdjCellInteriorNumsPStore> adjCellInterNumsSetsP_;

    MeshBuildingStore meshBuildingStore_;
};

}
#endif // SIMPLEFVM_DATASTORES_GLOBALDATASTORES_H