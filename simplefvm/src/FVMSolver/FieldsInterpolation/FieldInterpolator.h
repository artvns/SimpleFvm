#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATOR_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATOR_H

#include <cstddef>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/MeshInformation/MeshInfo.h"

#include "IFieldInterpolator.h"


namespace fvmsolver {

class FieldInterpolator {
private:
    using uPtrDataPortsMap = std::shared_ptr<MapAdt<std::unique_ptr<IFieldInterpolator>>>;

public:
    FieldInterpolator(MeshInfo& meshInfo, 
            uPtrDataPortsMap spFieldInterpolatorSet);

    void interpolateField();

private:
    MeshInfo& meshInfo_; 
    uPtrDataPortsMap spFieldInterpolatorSet_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATOR_H