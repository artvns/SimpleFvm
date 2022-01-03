#ifndef SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORSETS_H
#define SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORSETS_H

#include <string>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/DataSets/SetsCreatorInterpolator.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"

#include "IFieldInterpolator.h"
#include "FieldInterpolatorU.h"
#include "FieldInterpolatorV.h"
#include "FieldInterpolatorPorts.h"


namespace fvmsolver {

class FieldInterpolatorSets {
private:
    using shPtrMapIFieldInterpolator = std::shared_ptr<MapAdt<std::unique_ptr<IFieldInterpolator>>>;

public:
    FieldInterpolatorSets(DataManager& dataManager,
                            MeshInfoManager& meshInfoManager);

    shPtrMapIFieldInterpolator createSetForU();
    shPtrMapIFieldInterpolator createSetForV();

private:
    FieldInterpolatorPorts dataPorts_;
    SetsCreatorInterpolator<IFieldInterpolator, FieldInterpolatorPorts, FieldInterpolatorU> setsMakerU_;
    SetsCreatorInterpolator<IFieldInterpolator, FieldInterpolatorPorts, FieldInterpolatorV> setsMakerV_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSINTERPOLATION_FIELDINTERPOLATORSETS_H