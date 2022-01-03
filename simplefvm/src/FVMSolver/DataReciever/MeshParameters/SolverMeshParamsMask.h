#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_MESHPARAMETERS_SOLVERMESHPARAMSMASK_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_MESHPARAMETERS_SOLVERMESHPARAMSMASK_H

#include <cstddef>
#include <string>

#include "DataStores/MeshParametersStores/MeshParametersStore.h"


namespace fvmsolver {

class SolverMeshParamsMask {
private:
    using RecievedDataStore = datastores::MeshParametersStore;

public:
    SolverMeshParamsMask(RecievedDataStore& store);

    double get_dX(size_t index) const;
    double get_dY(size_t index) const;

private:
    RecievedDataStore& store_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_MESHPARAMETERS_SOLVERMESHPARAMSMASK_H