#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORPORTS_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORPORTS_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"

#include "FieldInterpolatorUPort.h"
#include "FieldInterpolatorVPort.h"


namespace fvmsolver {

class FieldInterpolatorPorts {
public:
    FieldInterpolatorPorts(DataManager& dataManager);

    std::unique_ptr<FieldInterpolatorUPort> createPortU(std::string name);
    std::unique_ptr<FieldInterpolatorVPort> createPortV(std::string name);

private:
    DataManager& dataManager_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORPORTS_H