#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_DATAMASKS_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_DATAMASKS_H

#include <cstddef>
#include <vector>

#include "DataStores/FieldsStores/FieldsStore.h"
#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"

#include "MeshInformation.h"
#include "RecievedCellData.h"


namespace resultssaver {

class DataMasks {
public:
    DataMasks(datastores::FieldsStore& fields,
                datastores::MeshParametersStore& meshParams, 
                datastores::MeshBuildingStore& meshBuilding);

    MeshInformation& getMeshInformation();
    RecievedCellData& getRecievedCellData();

private:
    MeshInformation meshInformation_;
    RecievedCellData recievedSaverCellData_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_DATAMASKS_H