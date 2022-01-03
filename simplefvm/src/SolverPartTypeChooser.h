#ifndef SIMPLEFVM_SOLVERPARTTYPECHOOSER_H
#define SIMPLEFVM_SOLVERPARTTYPECHOOSER_H

#include <string>
#include <map>

#include "FVMSolver/Solver.h"


namespace mainsolver {

enum EnumBcType {
    BC_TYPE_INTERIOR,
    BC_TYPE_MOVING_WALL,
    BC_TYPE_STATIC_WALL
};

class SolverPartTypeChooser {

public:
    SolverPartTypeChooser();

    void set_INTERIOR(std::string partName);
    void set_MOVING_WALL(std::string partName, const double wallVelocity);
    void set_STATIC_WALL(std::string partName);

    void setUpBcConditions(fvmsolver::Solver& solver);

private:
    struct MovingWallPart {
        double wallVelocity = 0.0;
    };

    std::map<std::string, EnumBcType> mapBcTypes_;
    std::map<std::string, MovingWallPart> mapMovingWallParams_;
};

}
#endif // SIMPLEFVM_SOLVERPARTTYPECHOOSER_H