#include "MeshInfoExtractor.h"

namespace meshloader {

MeshInfoExtractor::MeshInfoExtractor() {

}

void MeshInfoExtractor::extractInfo(MeshInformation& meshInfo, NumsSets& numsSets) {
    for (size_t i = 0; i < numsSets.getSetsAmount(); i++) {
        char tempName_[1];
        std::string partName_;

        partName_    = numsSets.getPartNamesSet().at(i);
        tempName_[0] = numsSets.getPartNamesSet().at(i);

        meshInfo.addFaceParameters(
            partName_,
            numsSets.getSetNumsAmount(tempName_[0])
        );
    }
}

}