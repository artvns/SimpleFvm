#ifndef SIMPLEFVM_RESULTSSAVER_SAVER_H
#define SIMPLEFVM_RESULTSSAVER_SAVER_H

#include <fstream>

#include "DataStores/FieldsStores/FieldsStore.h"
#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"

#include "SimpleSaver/SimpleDataSaver.h"
#include "VtkSaver/VtkDataSaver.h"


namespace resultssaver {

class Saver {
public:
    Saver(datastores::FieldsStore& fields, 
            datastores::MeshParametersStore& meshParams, 
            datastores::MeshBuildingStore& meshBuilding);

    void saveDataVtk(const std::string fileName);
    void saveDataTxt(const std::string fileName);

private:
    datastores::FieldsStore& fields_;
    datastores::MeshParametersStore& meshParams_;
    datastores::MeshBuildingStore& meshBuilding_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_SAVER_H