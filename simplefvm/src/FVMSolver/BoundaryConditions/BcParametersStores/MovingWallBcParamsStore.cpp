#include "MovingWallBcParamsStore.h"

namespace fvmsolver {

MovingWallBcParamsStore::MovingWallBcParamsStore() {

}


void MovingWallBcParamsStore::setWallVelocity(const double wallVelocity) {
    wallVelocity_ = wallVelocity;
}


double MovingWallBcParamsStore::getWallVelocity() const {
    return wallVelocity_;
}

}