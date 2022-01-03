#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDSINTERPOLATORSCREATOR_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDSINTERPOLATORSCREATOR_H

#include <memory>

#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/FieldsInterpolation/FieldInterpolator.h"
#include "FVMSolver/FieldsInterpolation/FieldInterpolatorSets.h"


namespace fvmsolver {

class FieldsInterpolatorsCreator {
public:
    FieldsInterpolatorsCreator(
                        DataManager& dataManager, 
                        MeshInfoManager& meshInfoManager);

    std::unique_ptr<FieldInterpolator>& createInterpolatorU();
    std::unique_ptr<FieldInterpolator>& createInterpolatorV();

private:
    FieldInterpolatorSets fieldInterpolatorSets_;
    MeshInfoManager& meshInfoManager_;

    std::unique_ptr<FieldInterpolator> spInterpolatorU_ = nullptr;
    std::unique_ptr<FieldInterpolator> spInterpolatorV_ = nullptr;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDSINTERPOLATORSCREATOR_H