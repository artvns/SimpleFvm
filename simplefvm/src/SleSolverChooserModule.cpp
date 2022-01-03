#include "SleSolverChooserModule.h"

#include "SolverSleSolverChooser.h"

namespace mainsolver {

SleSolverChooserModule::SleSolverChooserModule() : 
                    spObj_(new SolverSleSolverChooser()) {

}

SleSolverChooserModule::~SleSolverChooserModule() {
    delete spObj_;
    spObj_ = nullptr;
}

void SleSolverChooserModule::select_EIGEN_SOLVER() {
    spObj_->select_EIGEN_SOLVER();
}

SolverSleSolverChooser& SleSolverChooserModule::getSleSolverChooser() const {
    return  *spObj_;
}

}