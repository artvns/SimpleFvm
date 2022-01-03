#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERV_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERV_H

#include <cstddef>
#include <string>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsGlobal/AdjCellGlobalNumsVMask.h"
#include "MeshLoader/DataStoresLoaderMasks/CellNumsInterior/AdjCellInteriorNumsVMask.h"

#include "AbstractNumsPacker.h"


namespace meshloader {

class NumsPackerV : public AbstractNumsPacker {
public:
    NumsPackerV(DataStoreMasks& dataStoreMasks, 
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
                                AdjCellGlobalNumsVMask& dataMask);

    void packAdjCellInteriorNum(std::string partName, 
                                size_t partSize, 
                                AdjCellInteriorNumsVMask& dataMask);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_CELLNUMSPACKER_NUMSPACKERV_H