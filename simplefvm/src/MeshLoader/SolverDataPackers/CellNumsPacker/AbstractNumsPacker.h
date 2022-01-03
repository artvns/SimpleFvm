#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_ABSTRACTNUMSPACKER_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_ABSTRACTNUMSPACKER_H

#include <cstddef>
#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/CellNumsInteriorMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/CellNumsGlobalMask.h"


namespace meshloader {

class AbstractNumsPacker {
public:
    AbstractNumsPacker(DataStoreMasks& dataStoreMasks, 
                                Mesh& mesh, NumsSets& numsSets);
                          
    virtual~AbstractNumsPacker() = 0;

    void packAll();

protected:
    DataStoreMasks& dataStoreMasks_;
    Mesh& mesh_;
    NumsSets& numsSets_;

    virtual void packPart(std::string partName, size_t partSize) = 0;
    virtual void createStores(std::string partName, size_t partSize) = 0;

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_ABSTRACTNUMSPACKER_H