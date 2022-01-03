#include "FieldInterpolator.h"

namespace fvmsolver {

FieldInterpolator::FieldInterpolator(
            MeshInfo& meshInfo, 
            uPtrDataPortsMap spFieldInterpolatorSet) :
                    meshInfo_(meshInfo),
                    spFieldInterpolatorSet_(spFieldInterpolatorSet) {

}


void FieldInterpolator::interpolateField() {
    size_t domainParts = meshInfo_.getDomainPartsAmount();

    for (size_t partId = 0; partId < domainParts; partId++) {
        std::string name = meshInfo_.getPartName(partId);

        IFieldInterpolator& fieldInterpolator_ = 
                                    *spFieldInterpolatorSet_->getObject(name);

        size_t partCells = meshInfo_.getPartCellsAmount(name);
        for (size_t i = 0; i < partCells; i++) {

            fieldInterpolator_.interpolate(i);
        }
    }
}

}