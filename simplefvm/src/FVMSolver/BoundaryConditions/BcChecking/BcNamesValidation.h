#ifndef SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCCHECKING_BCNAMESVALIDATION_H
#define SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCCHECKING_BCNAMESVALIDATION_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

#include "CustomExceptions/BoundaryConditionsException.h"
#include "FVMSolver/DataReciever/MeshInformation/SolverMeshInfoMask.h"

#include "../PartsTypeInfo.h"


namespace fvmsolver {

class BcNamesValidation {
public:
    BcNamesValidation(SolverMeshInfoMask& solverMeshInfoMask, 
                        PartsTypeInfo& partsTypeInfo);

    void validateNames();

private:
    SolverMeshInfoMask& solverMeshInfoMask_;
    PartsTypeInfo& partsTypeInfo_;

    std::vector<std::string> incorrectBcNames_;

    bool isCorrectName(const std::string name);
};

}
#endif // SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCCHECKING_BCNAMESVALIDATION_H