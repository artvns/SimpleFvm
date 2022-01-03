#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_FIELDSPACKER_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_FIELDSPACKER_H

#include <cstddef>
#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"
#include "MeshLoader/DataStoresLoaderMasks/Fields/FieldsMask.h"



namespace meshloader {

class FieldsPacker {
public:
    FieldsPacker(DataStoreMasks& dataContainer, Mesh& mesh);

    void packFields();

private:
    DataStoreMasks& dataContainer_;
    Mesh& mesh_;

    void createStore(size_t storeSize);

    void packValueP(size_t idx, size_t cellNum);
    void packValueU(size_t idx, size_t cellNum);
    void packValueV(size_t idx, size_t cellNum);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_FIELDSPACKER_H