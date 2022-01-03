#ifndef SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_MESHGLOBALPARAMSDATA_H
#define SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_MESHGLOBALPARAMSDATA_H

#include <fstream>

#include "DataStores/ResultsDataStores/MeshBuildingStore.h"


namespace resultssaver {

class MeshGlobalParamsData {
public:
    MeshGlobalParamsData(datastores::MeshBuildingStore& meshBuilding);

    void outputData(std::ofstream& fout);

private:
    datastores::MeshBuildingStore& meshBuilding_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_MESHGLOBALPARAMSDATA_H