#include "ResidualsCalculator.h"

namespace fvmsolver {

ResidualsCalculator::ResidualsCalculator(
    MeshInfo& meshInfo, 
    std::shared_ptr<MapAdt<std::unique_ptr<IResidsCalculator>>> residCalculatorSet) :
                                meshInfo_(meshInfo),
                                residCalculatorSet_(residCalculatorSet) {

}

void ResidualsCalculator::calculateResidual() {
    maxResidual_ = 0.0;

    size_t domainParts = meshInfo_.getDomainPartsAmount();

    for (size_t partId = 0; partId < domainParts; partId++) {
        std::string name = meshInfo_.getPartName(partId);

        IResidsCalculator& residualsCalculator_ = 
                                    *residCalculatorSet_->getObject(name);

        size_t partCells = meshInfo_.getPartCellsAmount(name);

        for (size_t i = 0; i < partCells; i++) {
            
            double tempResidual_ = residualsCalculator_.calculateCellResidual(i);
            if (maxResidual_ < tempResidual_) {
                maxResidual_ = tempResidual_;
            }
        }
    }
}

double ResidualsCalculator::getResidual() {
    return maxResidual_;
}

}