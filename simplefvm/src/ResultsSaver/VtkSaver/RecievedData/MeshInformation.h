#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_MESHINFORMATION_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_MESHINFORMATION_H

#include <cstddef>
#include <vector>

#include "DataStores/MeshParametersStores/MeshParametersStore.h"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"


namespace resultssaver {

class MeshInformation {
public:
    MeshInformation(datastores::MeshParametersStore& meshParams, 
                    datastores::MeshBuildingStore& meshBuilding);

    size_t getCellsAmount() const;
    size_t getDimentionX() const;
    size_t getDimentionY() const;
    size_t getCellNum(size_t index) const;
    size_t getCell_iPos(size_t index) const;
    size_t getCell_jPos(size_t index) const;
    double get_dX() const;
    double get_dY() const;

private:
    datastores::MeshParametersStore& meshParams_;
    datastores::MeshBuildingStore& meshBuilding_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_MESHINFORMATION_H