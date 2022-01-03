#ifndef SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_GAPCELLSPOSITIONSDATA_H
#define SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_GAPCELLSPOSITIONSDATA_H

#include <cstddef>
#include <fstream>

#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"


namespace resultssaver {

class GapCellsPositionsData {
public:
    GapCellsPositionsData(datastores::MeshParametersStore& meshParams, 
                            datastores::MeshBuildingStore& meshBuilding);

    void outputData(std::ofstream& fout);

private:
    datastores::MeshParametersStore& meshParams_;
    datastores::MeshBuildingStore& meshBuilding_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_GAPCELLSPOSITIONSDATA_H