#include "AbstractResidualsOutput.h"

namespace fvmsolver {

AbstractResidualsOutput::AbstractResidualsOutput() {

}

AbstractResidualsOutput::~AbstractResidualsOutput() {

}

void AbstractResidualsOutput::addStepResidualU(double residual) {
    residualU_ = residual;
}

void AbstractResidualsOutput::addStepResidualV(double residual) {
    residualV_ = residual;
}

void AbstractResidualsOutput::addStepResidualP(double residual) {
    residualP_ = residual;
}

}