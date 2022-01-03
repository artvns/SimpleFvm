#include "AlgorithmChooserModule.h"

#include "SolverAlgorithmChooser.h"

namespace mainsolver {

AlgorithmChooserModule::AlgorithmChooserModule() : spObj_(
                                new SolverAlgorithmChooser()) {

}

AlgorithmChooserModule::~AlgorithmChooserModule() {
    delete spObj_;
    spObj_ = nullptr;
}

void AlgorithmChooserModule::select_SIMPLE() {
    spObj_->select_SIMPLE();
}

void AlgorithmChooserModule::select_SIMPLER() {
    spObj_->select_SIMPLER();
}

void AlgorithmChooserModule::select_PISO() {
    spObj_->select_PISO();
}

bool AlgorithmChooserModule::isSIMPLE() {
    return spObj_->isSIMPLE();
}

bool AlgorithmChooserModule::isSIMPLER() {
    return spObj_->isSIMPLER();
}

bool AlgorithmChooserModule::isPISO() {
    return spObj_->isPISO();
}

SolverAlgorithmChooser& AlgorithmChooserModule::getAlgorithmChooser() const {
    return  *spObj_;
}

}