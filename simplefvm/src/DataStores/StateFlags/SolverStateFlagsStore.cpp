#ifndef SIMPLEFVM_DATASTORES_STATEFLAGS_SOLVERSTATEFLAGSSTORE_H
#define SIMPLEFVM_DATASTORES_STATEFLAGS_SOLVERSTATEFLAGSSTORE_H


namespace datastores {

struct SolverStateFlagsStore {
    bool isMeshLoaded = false;
    bool isCalculationCompleted = false;
};

}
#endif // SIMPLEFVM_DATASTORES_STATEFLAGS_SOLVERSTATEFLAGSSTORE_H