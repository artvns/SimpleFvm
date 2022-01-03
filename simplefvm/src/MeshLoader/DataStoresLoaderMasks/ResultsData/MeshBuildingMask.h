#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_RESULTSDATA_MESHBUILDINGMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_RESULTSDATA_MESHBUILDINGMASK_H

#include <cstddef>
#include <string>

#include "DataStores/Adt/ArrayAdt.cpp"
#include "DataStores/ResultsDataStores/MeshBuildingStore.h"


namespace meshloader {

class MeshBuildingMask {
private:
    using RecievedDataStore = datastores::MeshBuildingStore;

public:
    MeshBuildingMask(RecievedDataStore& store);

    void createArrays(size_t activeCells, size_t gapCells);

    void setActiveCellsAmount(size_t value);
    void setGapCellsAmount(size_t value);
    void setMeshSizeX(size_t value);
    void setMeshSizeY(size_t value);

    size_t getActiveCellNum(size_t pos);
    size_t getActiveCell_iPos(size_t pos);
    size_t getActiveCell_jPos(size_t pos);

    size_t getGapCellNum(size_t pos);
    size_t getGapCell_iPos(size_t pos);
    size_t getGapCell_jPos(size_t pos);

    void setActiveCellNum(size_t pos, size_t value);
    void setActiveCell_iPos(size_t pos, size_t value);
    void setActiveCell_jPos(size_t pos, size_t value);

    void setGapCellNum(size_t pos, size_t value);
    void setGapCell_iPos(size_t pos, size_t value);
    void setGapCell_jPos(size_t pos, size_t value);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_RESULTSDATA_MESHBUILDINGMASK_H