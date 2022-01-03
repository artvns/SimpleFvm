#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTOR_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTOR_H

#include <cstddef>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/MeshInformation/MeshInfo.h"

#include "AbstractFieldCorrector.h"


namespace fvmsolver {

class FieldCorrector {
private:
    using shPtrAbstFieldCorrector = std::unique_ptr<AbstractFieldCorrector>;
    using shPtrMapAbstractFieldCorrector = std::shared_ptr<MapAdt<shPtrAbstFieldCorrector>>;

public:
    FieldCorrector(
            MeshInfo& meshInfo, 
            shPtrMapAbstractFieldCorrector spFieldCorrectorSet);

    void correctField();

private:
    MeshInfo& meshInfo_;
    shPtrMapAbstractFieldCorrector spFieldCorrectorSet_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTOR_H