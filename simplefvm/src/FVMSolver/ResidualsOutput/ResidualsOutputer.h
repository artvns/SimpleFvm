#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTER_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTER_H

#include <cstddef>
#include <memory>
#include <vector>
#include <string>

#include "FVMSolver/SolverSettings/Config.h"

#include "IResidualsOutputer.h"
#include "AbstractResidualsOutput.h"
#include "ResidualsOutputConsole.h"
#include "ResidualsOutputFile.h"


namespace fvmsolver {

class ResidualsOutputer : public IResidualsOutputer  {
private:
    using uPtrAbstResidsOutput = std::unique_ptr<AbstractResidualsOutput>;

public:
    ResidualsOutputer(std::vector<uPtrAbstResidsOutput>& outputList);

    void saveStepResiduals(size_t stepNumber) override;
    void addStepResidualU(double residual) override;
    void addStepResidualV(double residual) override;
    void addStepResidualP(double residual) override;

private:
    std::vector<uPtrAbstResidsOutput> outputList_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSOUTPUT_RESIDUALSOUTPUTER_H

