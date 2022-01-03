#ifndef SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_SIMPLEDATASAVER_H
#define SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_SIMPLEDATASAVER_H

#include <fstream>

#include "DataStores/FieldsStores/FieldsStore.h"
#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"

#include "../IResultsSaver.h"
#include "FileHeaderData.h"
#include "ActiveCellsParamsData.h"
#include "GapCellsPositionsData.h"
#include "MeshGlobalParamsData.h"


namespace resultssaver {

class SimpleDataSaver : public IResultsSaver {
public:
    SimpleDataSaver(datastores::FieldsStore& fields, 
                    datastores::MeshParametersStore& meshParams, 
                    datastores::MeshBuildingStore& meshBuilding);

    void saveData(const std::string fileName) override;

private:
    FileHeaderData fileHeader_;
    MeshGlobalParamsData meshGlobalParams_;
    ActiveCellsParamsData activeCellsParams_;
    GapCellsPositionsData gapCellsPositions_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_SIMPLESAVER_SIMPLEDATASAVER_H