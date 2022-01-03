#ifndef SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MESHINFOPACKER_H
#define SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MESHINFOPACKER_H

#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>

#include "MeshLoader/MeshContainer/Mesh.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"
#include "MeshLoader/DataStoresLoaderMasks/DataStoreMasks.h"
#include "MeshLoader/DataStoresLoaderMasks/MeshInformation/MeshInformationMask.h"


namespace meshloader {

class MeshInfoPacker {
public:
    MeshInfoPacker(DataStoreMasks& dataContainer, 
                    NumsSets& numsSetsP, 
                    NumsSets& numsSetsU, 
                    NumsSets& numsSetsV);

    void packMeshInfo();

private:
    DataStoreMasks& dataContainer_;
    NumsSets& numsSetsP_;
    NumsSets& numsSetsU_;
    NumsSets& numsSetsV_;


    void createStores(size_t storeSizeP, size_t storeSizeU, size_t storeSizeV);

    void packPartNamesAndCellsAmount(NumsSets& numsSets, 
                                        MeshInformationMask& meshInfoMask);

    void packAllCellsAmount(NumsSets& numsSets, 
                                MeshInformationMask& meshInfoMask);

    void sortVector(std::vector<size_t>&);
    void deleteDuplicatedNumsFromVector(std::vector<size_t>&);
};

}
#endif // SIMPLEFVM_MESHLOADER_SOLVERDATAPACKERS_MESHINFOPACKER_H