#include "ResidsOutputerCreator.h"

namespace fvmsolver {

ResidsOutputerCreator::ResidsOutputerCreator(
    const Config& config) :
                fullFileName_(
                    config.basicSolverVariables.getResidualsFullFileName()),
                isConsoleOutput_(config.isResidsOutputConsole),
                isFileOutput_(config.isResidsOutputFile) {

}

void ResidsOutputerCreator::configureResidsOutputer() {
    if (isConsoleOutput_) {
        outputList_.push_back(
            std::move(std::unique_ptr<AbstractResidualsOutput> (
                new ResidualsOutputConsole())));
    }
    if (isFileOutput_) {
        outputList_.push_back(
            std::move(std::unique_ptr<AbstractResidualsOutput> (
                new ResidualsOutputFile(fullFileName_))));
    }
}

std::shared_ptr<ResidualsOutputer> ResidsOutputerCreator::createResidsOutputer() {
    spResidsOutputer_ = std::shared_ptr<ResidualsOutputer>(
        new ResidualsOutputer(outputList_)
    );
    
    return spResidsOutputer_;
}

}