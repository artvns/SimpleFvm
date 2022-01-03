#include "FieldCorrector.h"

namespace fvmsolver {

FieldCorrector::FieldCorrector(
            MeshInfo& meshInfo, 
            shPtrMapAbstractFieldCorrector spFieldCorrectorSet) :
                                meshInfo_(meshInfo),
                                spFieldCorrectorSet_(spFieldCorrectorSet) {

}

void FieldCorrector::correctField() {
    size_t domainParts = meshInfo_.getDomainPartsAmount();

    for (size_t partId = 0; partId < domainParts; partId++) {
        std::string name = meshInfo_.getPartName(partId);

        AbstractFieldCorrector& fieldCorrector_ = 
                                    *spFieldCorrectorSet_->getObject(name);

        size_t partCells = meshInfo_.getPartCellsAmount(name);
        for (size_t i = 0; i < partCells; i++) {

            fieldCorrector_.correct(i);
        }
    }
}

}