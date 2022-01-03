#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_COEFFSPARTSVELOCITYCREATOR_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_COEFFSPARTSVELOCITYCREATOR_H

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/BoundaryConditions/BcManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"
#include "FVMSolver/BoundaryConditions/PartsTypeInfo.h"
#include "FVMSolver/SolverSettings/Config.h"
#include "FVMSolver/CoeffsPartsVelocity/Diffusion/DiffusionSets.h"
#include "FVMSolver/CoeffsPartsVelocity/Diffusion/AbstractDiffusion.h"
#include "FVMSolver/CoeffsPartsVelocity/Flux/FluxSets.h"
#include "FVMSolver/CoeffsPartsVelocity/Flux/AbstractFlux.h"
#include "FVMSolver/CoeffsPartsVelocity/SourceTerm/SourceSets.h"
#include "FVMSolver/CoeffsPartsVelocity/SourceTerm/AbstractSource.h"
#include "FVMSolver/CoeffsPartsVelocity/DifferencingScheme/DifferencingSchemeCreator.h"
#include "FVMSolver/CoeffsPartsVelocity/DifferencingScheme/IDifferencingScheme.h"
#include "FVMSolver/CoeffsPartsVelocity/RhsVelocity/RhsVelocitySets.h"
#include "FVMSolver/CoeffsPartsVelocity/RhsVelocity/AbstractRhsVelocity.h"


namespace fvmsolver {

class CoeffsPartsVelocityCreator {
private:
    using shPtrMapAbstDiffusion = std::shared_ptr<MapAdt<std::unique_ptr<AbstractDiffusion>>>;
    using shPtrMapAbstFlux = std::shared_ptr<MapAdt<std::unique_ptr<AbstractFlux>>>;
    using shPtrMapAbstSource = std::shared_ptr<MapAdt<std::unique_ptr<AbstractSource>>>;
    using shPtrMapAbstRhsVelocity = std::shared_ptr<MapAdt<std::unique_ptr<AbstractRhsVelocity>>>;

public:
    CoeffsPartsVelocityCreator(DataManager& dataManager, 
                                MeshInfoManager& meshInfoManager,
                                BcManager& bcManager,
                                Config& config);

    shPtrMapAbstDiffusion getDiffusionSetU();
    shPtrMapAbstDiffusion getDiffusionSetV();
    shPtrMapAbstFlux getFluxSetU();
    shPtrMapAbstFlux getFluxSetV();
    shPtrMapAbstSource getSourceSetU();
    shPtrMapAbstSource getSourceSetV();
    std::shared_ptr<IDifferencingScheme> getDifferencingScheme();
    shPtrMapAbstRhsVelocity getRhsSetU();
    shPtrMapAbstRhsVelocity getRhsSetV();

private:
    DiffusionSets diffusionSets_;
    FluxSets fluxSets_;
    SourceSets sourceSets_;
    DifferencingSchemeCreator schemeCreator_;
    RhsVelocitySets rhsVelocitySets_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSVELOCITY_COEFFSPARTSVELOCITYCREATOR_H