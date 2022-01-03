#include "BcDefinitionStatusCheck.h"

namespace fvmsolver {

BcDefinitionStatusCheck::BcDefinitionStatusCheck(
        SolverMeshInfoMask& solverMeshInfoMask,
        PartsTypeInfo& partsTypeInfo) : 
                        solverMeshInfoMask_(solverMeshInfoMask),
                        partsTypeInfo_(partsTypeInfo) {

}


void BcDefinitionStatusCheck::checkStatus() {
    for (size_t i = 0; i < solverMeshInfoMask_.getDomainPartsAmount(); i++) {

        std::string name_ = solverMeshInfoMask_.getPartName(i);

        if (!isInVector(name_, partsTypeInfo_.getAllBcDefinedPartNames())) {
            undefinedBcNames_.push_back(name_);
        }
    }

    if (undefinedBcNames_.size() > 0) {
        throw customexceptions::BoundaryConditionsException(
            "Boundary conditions are not specified for the following parts:",
                    undefinedBcNames_);
    }
}


bool BcDefinitionStatusCheck::isInVector(const std::string name, 
                                        const std::vector<std::string> vect) {

    if(std::find(vect.begin(), vect.end(), name) != vect.end()) {
        return true;
    } else {
        return false;
    }
}

}