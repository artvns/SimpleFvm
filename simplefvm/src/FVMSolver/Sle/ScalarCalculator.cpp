#include "ScalarCalculator.h"

namespace fvmsolver {

ScalarCalculator::ScalarCalculator(
                std::shared_ptr<SleSolver> spSleSolver,
                std::shared_ptr<SleMatrixBuilder> sleMatrixes) :
                                spSleSolver_(spSleSolver),
                                sleMatrixes_(sleMatrixes) {

}


void ScalarCalculator::calculate() {
    sleMatrixes_->build(spSleSolver_);
    spSleSolver_->solve();
}

}