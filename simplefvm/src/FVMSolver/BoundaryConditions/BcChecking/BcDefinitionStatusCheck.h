#ifndef SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCCHECKING_BCDEFINITIONSTATUSCHECK_H
#define SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCCHECKING_BCDEFINITIONSTATUSCHECK_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

#include "CustomExceptions/BoundaryConditionsException.h"
#include "FVMSolver/DataReciever/MeshInformation/SolverMeshInfoMask.h"

#include "../PartsTypeInfo.h"


namespace fvmsolver {

class BcDefinitionStatusCheck {
public:
    BcDefinitionStatusCheck(SolverMeshInfoMask& solverMeshInfoMask, 
                            PartsTypeInfo& partsTypeInfo);

    void checkStatus();

private:
    SolverMeshInfoMask& solverMeshInfoMask_;
    PartsTypeInfo& partsTypeInfo_;

    std::vector<std::string> undefinedBcNames_;

    bool isInVector(const std::string name,
                    const std::vector<std::string> vect);
};

}
#endif // SIMPLEFVM_FVMSOLVER_BOUNDARYCONDITIONS_BCCHECKING_BCDEFINITIONSTATUSCHECK_H