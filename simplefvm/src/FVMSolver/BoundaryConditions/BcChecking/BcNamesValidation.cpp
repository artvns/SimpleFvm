#include "BcNamesValidation.h"

namespace fvmsolver {

BcNamesValidation::BcNamesValidation(
        SolverMeshInfoMask& solverMeshInfoMask,
        PartsTypeInfo& partsTypeInfo) : 
                        solverMeshInfoMask_(solverMeshInfoMask),
                        partsTypeInfo_(partsTypeInfo) {

}


void BcNamesValidation::validateNames() {
    for (size_t i = 0; i < partsTypeInfo_.getDefinedPartNamesAmount(); i++) {
        std::string name_ = partsTypeInfo_.getDefinedPartName(i);

        if (!isCorrectName(name_)) {
            incorrectBcNames_.push_back(name_);
        }
    }

    if (incorrectBcNames_.size() > 0) {
        throw customexceptions::BoundaryConditionsException(
            "The following incorrect bc names have been entered:",
            incorrectBcNames_);
    }
}


bool BcNamesValidation::isCorrectName(const std::string name) {
    bool isNameCorrect_ = false;

    for (size_t i = 0; i < solverMeshInfoMask_.getDomainPartsAmount(); i++) {
        if(solverMeshInfoMask_.getPartName(i) == name) {
            isNameCorrect_ = true;
            break;
        }
    }

    return isNameCorrect_;
}

}