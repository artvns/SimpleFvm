#ifndef SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMCREATOR_H
#define SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMCREATOR_H

#include <memory>

#include "AlgorithmBuilder.h"


namespace fvmsolver {

class AlgorithmCreator {
public:
    AlgorithmCreator();

    std::shared_ptr<AbstractAlgorithm> createSimple2D(AlgorithmBuilder& builder);
    std::shared_ptr<AbstractAlgorithm> createSimple1D(AlgorithmBuilder& builder);

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMCREATOR_H