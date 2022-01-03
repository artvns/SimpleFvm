#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_MESHINFORMATION_SOLVERMESHINFOMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_MESHINFORMATION_SOLVERMESHINFOMASK_H

#include <cstddef>
#include <string>

#include "DataStores/MeshInformationStore/MeshInfoStore.h"


namespace fvmsolver {

class SolverMeshInfoMask {
private:
    using RecievedDataStore = datastores::MeshInfoStore;

public:
    SolverMeshInfoMask(RecievedDataStore& store);

    std::string getPartName (size_t index) const;
    size_t getPartCellsAmount(std::string name) const;
    size_t getDomainPartsAmount() const;
    size_t getAllCellsAmount() const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_MESHINFORMATION_SOLVERMESHINFOMASK_H