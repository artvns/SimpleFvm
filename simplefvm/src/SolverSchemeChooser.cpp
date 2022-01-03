#include "SolverSchemeChooser.h"

namespace mainsolver {

SolverSchemeChooser::SolverSchemeChooser() {

}

void SolverSchemeChooser::select_CENTRAL() {
    currentScheme_ = SCHEME_CENTRAL;
}

void SolverSchemeChooser::select_UPWIND() {
    currentScheme_ = SCHEME_UPWIND;
}

void SolverSchemeChooser::select_HYBRID() {
    currentScheme_ = SCHEME_HYBRID;
}

bool SolverSchemeChooser::isCENTRAL() {
    if (SCHEME_CENTRAL == currentScheme_) {
        return true;
    }
    else {
        return false;
    }
}

bool SolverSchemeChooser::isUPWIND() {
    if (SCHEME_UPWIND == currentScheme_) {
        return true;
    }
    else {
        return false;
    }
}

bool SolverSchemeChooser::isHYBRID() {
    if (SCHEME_HYBRID == currentScheme_) {
        return true;
    }
    else {
        return false;
    }
}

void SolverSchemeChooser::setUpSolverParameter(fvmsolver::Solver& solver) {
    switch (currentScheme_) {
        case SCHEME_CENTRAL:
            solver.getSettingsManager().chooseSchemeCentral();
            break;
        case SCHEME_UPWIND:
            solver.getSettingsManager().chooseSchemeUpwind();
            break;
        case SCHEME_HYBRID:
            solver.getSettingsManager().chooseSchemeHybrid();
            break;
        default:
            solver.getSettingsManager().chooseSchemeCentral();
            break;
    }
}

}