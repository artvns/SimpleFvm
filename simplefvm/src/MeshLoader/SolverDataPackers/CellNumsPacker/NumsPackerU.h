#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERU_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERU_H

#include <cstddef>
#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/AdjCellGlobalNumsUMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/AdjCellInteriorNumsUMask.h"

#include "AbstractNumsPacker.h"


namespace meshloader {

class NumsPackerU : public AbstractNumsPacker {
public:
    NumsPackerU(DataStoreMasks& dataStoreMasks, 
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
                                AdjCellGlobalNumsUMask& dataMask);

    void packAdjCellInteriorNum(std::string partName, 
                                size_t partSize, 
                                AdjCellInteriorNumsUMask& dataMask);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERU_H