#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERP_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERP_H

#include <cstddef>
#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/AdjCellGlobalNumsPMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/AdjCellInteriorNumsPMask.h"

#include "AbstractNumsPacker.h"


namespace meshloader {

class NumsPackerP : public AbstractNumsPacker {
public:
    NumsPackerP(DataStoreMasks& dataStoreMasks, 
                        Mesh& mesh, NumsSets& numsSets);

protected:
    void packPart(std::string partName, size_t partSize) override;
    void createStores(std::string partName, size_t partSize) override;

private:

    void packCellInteriorNum(std::string partName, 
                                size_t storeSize,
                                CellNumsInteriorMask& dataMask);

    void packCellGlobalNum(std::string partName, 
                                size_t partSize, 
                                CellNumsGlobalMask& dataMask);
                                
    void packAdjCellGlobalNum(std::string partName, 
                                size_t partSize, 
                                AdjCellGlobalNumsPMask& dataMask);

    void packAdjCellInteriorNum(std::string partName, 
                                size_t partSize, 
                                AdjCellInteriorNumsPMask& dataMask);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERP_H