#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MESHPARAMSPACKER_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MESHPARAMSPACKER_H

#include <cstddef>
#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshParameters/MeshParamsMask.h"


namespace meshloader {

class MeshParamsPacker {
public:
    MeshParamsPacker(DataStoreMasks& dataContainer, Mesh& mesh);

    void packMeshParameters();

private:
    DataStoreMasks& dataContainer_;
    Mesh& mesh_;

    void createStores(size_t storeSize);

    void packMeshValuesP(size_t idx, size_t cellNum);
    void packMeshValuesU(size_t idx, size_t cellNum);
    void packMeshValuesV(size_t idx, size_t cellNum);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MESHPARAMSPACKER_H