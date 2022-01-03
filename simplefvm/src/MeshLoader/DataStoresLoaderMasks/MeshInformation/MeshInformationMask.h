#ifndef SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_MESHINFORMATION_MESHINFORMATIONMASK_H
#define SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_MESHINFORMATION_MESHINFORMATIONMASK_H

#include <cstddef>
#include <string>

#include "DataStores/MeshInformationStore/MeshInfoStore.h"


namespace meshloader {

class MeshInformationMask {
private:
    using RecievedDataStore = datastores::MeshInfoStore;

public:
    MeshInformationMask(RecievedDataStore& store);

    void createStore(size_t parts);

    std::vector<std::string>& getBcNamesVector();
    
    void setPartName(size_t index, std::string value);
    void setPartCellsAmount(std::string name, size_t value);

    void setDomainPartsAmount(size_t partsAmount);
    void setAllCellsAmount(size_t allCellsAmount);

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_MESHLOADER_DATASTORESLOADERMASKS_MESHINFORMATION_MESHINFORMATIONMASK_H