#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_CALCEDSCALARSDEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_CALCEDSCALARSDEFAULTITER1_H

#include <cstddef>

#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"
#include "MathTools/SleSolvers/ISleSolverVector.h"

#include "../SingleScalar.h"


namespace commoninitdata {

using namespace fvmsolver;


class CalcedScalars_DefaultIter1 {
public:
    CalcedScalars_DefaultIter1();

    ScalarsStore& getScalarsStore();

    void createScalars();

private:
    SingleScalar uStarData_;
    SingleScalar vStarData_;
    SingleScalar pPrimeData_;
    CalculatedScalar uStarScalar_;
    CalculatedScalar vStarScalar_;  
    CalculatedScalar pPrimeScalar_;
    ScalarsStore scalars_;

    size_t cells_u_ = 20;
    size_t cells_v_ = 20;
    size_t cells_p_ = 20;

    void createUStar();
    void createVStar();
    void createPPrime();
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_DATADEFAULTITERATION1_CALCEDSCALARSDEFAULTITER1_H