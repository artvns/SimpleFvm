#ifndef SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCPARAMETERSSTORES_MOVINGWALLBCPARAMSSTORE_H
#define SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCPARAMETERSSTORES_MOVINGWALLBCPARAMSSTORE_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

#include "../../Tools/LocalAdt/MapAdt.cpp"


namespace fvmsolver {

class MovingWallBcParamsStore {
public:
    MovingWallBcParamsStore();

    void setWallVelocity(const double wallVelocity);
    double getWallVelocity() const;

private:
    double wallVelocity_ = 0.0;
};

}
#endif // SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCPARAMETERSSTORES_MOVINGWALLBCPARAMSSTORE_H