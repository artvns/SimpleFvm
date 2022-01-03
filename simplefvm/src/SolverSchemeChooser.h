#ifndef SIMPLEFVM_SOLVERSCHEMECHOOSER_H
#define SIMPLEFVM_SOLVERSCHEMECHOOSER_H

#include "FVMSolver/Solver.h"


namespace mainsolver {

enum EnumScheme {
    SCHEME_CENTRAL,
    SCHEME_UPWIND,
    SCHEME_HYBRID
};

class SolverSchemeChooser {
public:
    SolverSchemeChooser();

    void select_CENTRAL();
    void select_UPWIND();
    void select_HYBRID();

    bool isCENTRAL();
    bool isUPWIND();
    bool isHYBRID();

    void setUpSolverParameter(fvmsolver::Solver& solver);

private:
    EnumScheme currentScheme_ = SCHEME_CENTRAL;
};

}
#endif // SIMPLEFVM_SOLVERSCHEMECHOOSER_H