#include "ResidualsSettingsModule.h"

#include "SolverResidualsSettingsDefiner.h"

namespace mainsolver {

ResidualsSettingsModule::ResidualsSettingsModule() : spObj_(
                                new SolverResidualsSettingsDefiner()) {

}

ResidualsSettingsModule::~ResidualsSettingsModule() {
    delete spObj_;
    spObj_ = nullptr;
}

void ResidualsSettingsModule::selectConsoleOutput() {
    spObj_->selectConsoleOutput();
}

void ResidualsSettingsModule::selectFileOutput(
                            const std::string fullFileName) {
                                
    spObj_->selectFileOutput(fullFileName);
}

bool ResidualsSettingsModule::isConsoleOutput() {
    return spObj_->isConsoleOutput();
}

bool ResidualsSettingsModule::isFileOutput() {
    return spObj_->isFileOutput();
}

SolverResidualsSettingsDefiner& ResidualsSettingsModule::getResidsSettingsDefiner() const {
    return  *spObj_;
}

}