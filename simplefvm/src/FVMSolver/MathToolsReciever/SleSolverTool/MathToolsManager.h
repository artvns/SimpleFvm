#ifndef SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_MATHTOOLSMANAGER_H
#define SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_MATHTOOLSMANAGER_H

#include <memory>

#include "MathTools/SleSolvers/ISleSolver.h"
#include "MathTools/SleSolvers/ISleSolverVector.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/SleSolver.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"

#include "ScalarsStore.h"


namespace fvmsolver {

class MathToolsManager {
public:
    MathToolsManager();

    void createScalarsStore();

    std::shared_ptr<SleSolver> getSleSoverP();
    std::shared_ptr<SleSolver> getSleSoverU();
    std::shared_ptr<SleSolver> getSleSoverV();

    std::shared_ptr<ScalarsStore> getScalarsStore();

    void setSleSoverP(mathtools::ISleSolver& solver);
    void setSleSoverU(mathtools::ISleSolver& solver);
    void setSleSoverV(mathtools::ISleSolver& solver);

private:
    std::shared_ptr<SleSolver> pSleSolverP_ = nullptr;
    std::shared_ptr<SleSolver> pSleSolverU_ = nullptr;
    std::shared_ptr<SleSolver> pSleSolverV_ = nullptr;

    std::shared_ptr<CalculatedScalar> pResVectorP_ = nullptr;
    std::shared_ptr<CalculatedScalar> pResVectorU_ = nullptr;
    std::shared_ptr<CalculatedScalar> pResVectorV_ = nullptr;

    std::shared_ptr<ScalarsStore> pScalarsStore_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATHTOOLSRECIEVER_MATHTOOLSMANAGER_H