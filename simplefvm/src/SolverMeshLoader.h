#ifndef SIMPLEFVM_SOLVERMESHLOADER_H
#define SIMPLEFVM_SOLVERMESHLOADER_H

#include <string>
#include <stdexcept>

#include "DataStores/GlobalDataStores.h"
#include "MeshLoader/Loader.h"

#include "CustomExceptions/MeshLoadStateException.h"
#include "CustomExceptions/DomainPartsException.h"


namespace mainsolver {

class GlobalDataStores;

class SolverMeshLoader {
public:
    SolverMeshLoader(datastores::GlobalDataStores& dataStores);

    void loadMesh(const std::string fileName, const double dx, const double dy);
    std::vector<std::string>& getBcNamesVector();

private:
    datastores::GlobalDataStores& dataStores_;
};

}
#endif // SIMPLEFVM_SOLVERMESHLOADER_H