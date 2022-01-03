#include "ResidualsOutputer.h"

namespace fvmsolver {

ResidualsOutputer::ResidualsOutputer(
    std::vector<uPtrAbstResidsOutput>& outputList) : 
                        outputList_(std::move(outputList)) {

}

void ResidualsOutputer::saveStepResiduals(size_t stepNumber) {
    for (size_t i = 0; i < outputList_.size(); ++i) {
        outputList_.at(i)->saveStepResiduals(stepNumber);
    }
}

void ResidualsOutputer::addStepResidualU(double residual) {
    for (size_t i = 0; i < outputList_.size(); ++i) {
        outputList_.at(i)->addStepResidualU(residual);
    }
}

void ResidualsOutputer::addStepResidualV(double residual) {
    for (size_t i = 0; i < outputList_.size(); ++i) {
        outputList_.at(i)->addStepResidualV(residual);
    }
}

void ResidualsOutputer::addStepResidualP(double residual) {
    for (size_t i = 0; i < outputList_.size(); ++i) {
        outputList_.at(i)->addStepResidualP(residual);
    }
}

}