#include "DataMasks.h"

namespace resultssaver {

DataMasks::DataMasks(
    datastores::FieldsStore& fields,
    datastores::MeshParametersStore& meshParams, 
    datastores::MeshBuildingStore& meshBuilding) : 
                    meshInformation_(meshParams, meshBuilding),
                    recievedSaverCellData_(fields) {

}

MeshInformation& DataMasks::getMeshInformation() {
    return meshInformation_;
}

RecievedCellData& DataMasks::getRecievedCellData() {
    return recievedSaverCellData_;
}

}