#ifndef SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_ACTIVECELLSPARAMSDATA_H
#define SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_ACTIVECELLSPARAMSDATA_H

#include <cstddef>
#include <fstream>

#include "DataStores/FieldsStores/FieldsStore.h"
#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"


namespace resultssaver {

class ActiveCellsParamsData {
public:
    ActiveCellsParamsData(datastores::FieldsStore& fields, 
                            datastores::MeshParametersStore& meshParams,
                            datastores::MeshBuildingStore& meshBuilding);

    void outputData(std::ofstream& fout);

private:
    datastores::FieldsStore& fields_;
    datastores::MeshParametersStore& meshParams_;
    datastores::MeshBuildingStore& meshBuilding_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_ACTIVECELLSPARAMSDATA_H