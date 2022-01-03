#include "SolverPartTypeChooser.h"

namespace mainsolver {

SolverPartTypeChooser::SolverPartTypeChooser() {

}

void SolverPartTypeChooser::set_INTERIOR(std::string partName) {
    mapBcTypes_[partName] = BC_TYPE_INTERIOR;
}

void SolverPartTypeChooser::set_MOVING_WALL(std::string partName, 
                                            const double wallVelocity) {

    mapBcTypes_[partName] = BC_TYPE_MOVING_WALL;
    mapMovingWallParams_[partName].wallVelocity = wallVelocity;
}

void SolverPartTypeChooser::set_STATIC_WALL(std::string partName) {
    mapBcTypes_[partName] = BC_TYPE_STATIC_WALL;
}

void SolverPartTypeChooser::setUpBcConditions(fvmsolver::Solver& solver) {

    std::map<std::string, EnumBcType>::iterator it;

    for (it = mapBcTypes_.begin(); it != mapBcTypes_.end(); ++it) {

        std::string partName_ = it->first;
        EnumBcType type_ = it->second;

        switch (type_) {
        case BC_TYPE_INTERIOR:
            solver.getBcManager().defineInteriorPart(partName_);
            break;
        case BC_TYPE_STATIC_WALL:
            solver.getBcManager().defineStaticWallPart(partName_);
            break;
        case BC_TYPE_MOVING_WALL:
            solver.getBcManager().defineMovingWallPart(
                partName_, mapMovingWallParams_[partName_].wallVelocity);
            break;
        default:
            solver.getBcManager().defineStaticWallPart(partName_);
            break;
        }
    }
}

}