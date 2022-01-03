#include "FieldsInterpolatorsCreator.h"

namespace fvmsolver {

FieldsInterpolatorsCreator::FieldsInterpolatorsCreator(
    DataManager& dataManager, 
    MeshInfoManager& meshInfoManager) :
                fieldInterpolatorSets_(dataManager, 
                                       meshInfoManager),
                meshInfoManager_(meshInfoManager) {

}

std::unique_ptr<FieldInterpolator>& FieldsInterpolatorsCreator::createInterpolatorU() {
    spInterpolatorU_ = std::unique_ptr<FieldInterpolator>(
        new FieldInterpolator(
            *meshInfoManager_.getMeshInfoP(), 
            fieldInterpolatorSets_.createSetForU())
    );

    return spInterpolatorU_;
}

std::unique_ptr<FieldInterpolator>& FieldsInterpolatorsCreator::createInterpolatorV() {
    spInterpolatorV_ = std::unique_ptr<FieldInterpolator>(
        new FieldInterpolator(
            *meshInfoManager_.getMeshInfoP(),
            fieldInterpolatorSets_.createSetForV())
    );

    return spInterpolatorV_;
}

}