#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_ABSTRACTFIELDCORRECTOR_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_ABSTRACTFIELDCORRECTOR_H

#include <cstddef>
#include <memory>

#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"

#include "FieldCorrectorUPort.h"


namespace fvmsolver {

class AbstractFieldCorrector {
public:
    AbstractFieldCorrector();
    virtual ~AbstractFieldCorrector() = 0;

    virtual void correct(size_t step) = 0;

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_ABSTRACTFIELDCORRECTOR_H

    