#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLTYPESPACKER_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLTYPESPACKER_H

#include <cstddef>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"
#include "MeshLoader/DataStoresLoaderMasks/AdjacentCellsType/AdjCellsTypeMask.h"


namespace meshloader {

class CellTypesPacker {
public:
    CellTypesPacker(DataStoreMasks& dataContainer, Mesh& mesh);

    void packCellTypes();

private:
    DataStoreMasks& dataContainer_;
    Mesh& mesh_;

    void createStores(size_t storeSize);

    void setGhostTypes(size_t cellNum);

    void packCellTypesP(size_t cellNum);
    void packCellTypesU(size_t cellNum);
    void packCellTypesV(size_t cellNum);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLTYPESPACKER_H