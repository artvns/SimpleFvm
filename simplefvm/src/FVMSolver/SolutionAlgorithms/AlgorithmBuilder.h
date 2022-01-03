#ifndef SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMBUILDER_H
#define SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMBUILDER_H

#include <memory>

#include "Algorithms/AbstractAlgorithm.h"


namespace fvmsolver {

class AlgorithmBuilder {
public:
    AlgorithmBuilder() {};
    virtual ~AlgorithmBuilder() {};

    virtual void createAlgorithm() {};
    virtual void addNumberOfIterations() {};
    virtual void addCalculatorUstar() {};
    virtual void addCalculatorVstar() {};
    virtual void addCalculatorPprime() {};
    virtual void addCorrectorU() {};
    virtual void addCorrectorV() {};
    virtual void addCorrectorP() {};
    virtual void addResidualsCalculatorU() {};
    virtual void addResidualsCalculatorV() {};
    virtual void addResidualsCalculatorP() {};
    virtual void addResidualsOutput() {};
    virtual std::shared_ptr<AbstractAlgorithm> getAlgorithm() = 0;

protected:

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_SOLUTIONALGORITHMS_ALGORITHMBUILDER_H