#include "MeshInfoPacker.h"

namespace meshloader {

MeshInfoPacker::MeshInfoPacker(
                    DataStoreMasks& dataContainer, 
                    NumsSets& numsSetsP, 
                    NumsSets& numsSetsU, 
                    NumsSets& numsSetsV) :
                            dataContainer_(dataContainer),
                            numsSetsP_(numsSetsP),
                            numsSetsU_(numsSetsU),
                            numsSetsV_(numsSetsV) {

}

void MeshInfoPacker::packMeshInfo() {
    size_t partsAmountP_ = numsSetsP_.getSetsAmount();
    size_t partsAmountU_ = numsSetsU_.getSetsAmount();
    size_t partsAmountV_ = numsSetsV_.getSetsAmount();

    createStores(partsAmountP_, partsAmountU_, partsAmountV_);

    packPartNamesAndCellsAmount(numsSetsP_, dataContainer_.getMeshInfoMaskP());
    packPartNamesAndCellsAmount(numsSetsU_, dataContainer_.getMeshInfoMaskU());
    packPartNamesAndCellsAmount(numsSetsV_, dataContainer_.getMeshInfoMaskV());

    packAllCellsAmount(numsSetsP_, dataContainer_.getMeshInfoMaskP());
    packAllCellsAmount(numsSetsU_, dataContainer_.getMeshInfoMaskU());
    packAllCellsAmount(numsSetsV_, dataContainer_.getMeshInfoMaskV());

    dataContainer_.getMeshInfoMaskP().setDomainPartsAmount(partsAmountP_);
    dataContainer_.getMeshInfoMaskU().setDomainPartsAmount(partsAmountU_);
    dataContainer_.getMeshInfoMaskV().setDomainPartsAmount(partsAmountV_);
}

void MeshInfoPacker::packPartNamesAndCellsAmount(NumsSets& numsSets, 
                                    MeshInformationMask& meshInfoMask) {

    size_t partsAmount = numsSets.getPartNamesSet().size();

    for (size_t i = 0; i < partsAmount; i++) {

        char partName = numsSets.getPartNamesSet().at(i);
        size_t  partSize = numsSets.getNumsSet(partName).size();

        std::string name(1, partName);

        meshInfoMask.setPartName(i, name);
        meshInfoMask.setPartCellsAmount(name, partSize);
    }
}

void MeshInfoPacker::packAllCellsAmount(NumsSets& numsSets, 
                                MeshInformationMask& meshInfoMask) {

    std::vector<size_t> cellNums_;

    size_t partsAmount = numsSets.getPartNamesSet().size();

    for (size_t i = 0; i < partsAmount; i++) {
        char partName = numsSets.getPartNamesSet().at(i);
        size_t  partSize = numsSets.getNumsSet(partName).size();

        for (size_t j = 0; j < partSize; j++) {
            cellNums_.push_back(numsSets.getNumsSet(partName).at(j));
        }

    }
    sortVector(cellNums_);
    deleteDuplicatedNumsFromVector(cellNums_);
    
    meshInfoMask.setAllCellsAmount(cellNums_.size());
}

void MeshInfoPacker::createStores(size_t storeSizeP, size_t storeSizeU, 
                                                    size_t storeSizeV) {

    dataContainer_.getMeshInfoMaskP().createStore(storeSizeP);
    dataContainer_.getMeshInfoMaskU().createStore(storeSizeU);
    dataContainer_.getMeshInfoMaskV().createStore(storeSizeV);
}

void MeshInfoPacker::sortVector(std::vector<size_t>& v) {
    std::sort(v.begin(), v.end());
}

void MeshInfoPacker::deleteDuplicatedNumsFromVector(std::vector<size_t>& v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

}