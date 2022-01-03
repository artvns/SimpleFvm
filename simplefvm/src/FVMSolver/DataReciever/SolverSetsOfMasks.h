#ifndef SIMPLEFVM_FVMSOLVER_DATARECIEVER_SOLVERSETSOFMASKS_H
#define SIMPLEFVM_FVMSOLVER_DATARECIEVER_SOLVERSETSOFMASKS_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <iterator>
#include <algorithm>

#include "DataStores/GlobalDataStores.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsPMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsUMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverAdjCellGlobalNumsVMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsPMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsUMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsVMask.h"


namespace fvmsolver {

class SolverSetsOfMasks {
public:
    SolverSetsOfMasks(datastores::GlobalDataStores& dataStores);

    void createMaskSetsU();
    void createMaskSetsV();
    void createMaskSetsP();

    SolverCellNumsGlobalMask&         getCellNumsGlobalUMask(std::string partName);
    SolverCellNumsGlobalMask&         getCellNumsGlobalVMask(std::string partName);
    SolverCellNumsGlobalMask&         getCellNumsGlobalPMask(std::string partName);

    SolverAdjCellGlobalNumsUMask&     getAdjCellGlobalNumsUMask(std::string partName);
    SolverAdjCellGlobalNumsVMask&     getAdjCellGlobalNumsVMask(std::string partName);
    SolverAdjCellGlobalNumsPMask&     getAdjCellGlobalNumsPMask(std::string partName);

    SolverCellNumsInteriorMask&       getCellInterNumsUMask(std::string partName);
    SolverCellNumsInteriorMask&       getCellInterNumsVMask(std::string partName);
    SolverCellNumsInteriorMask&       getCellInterNumsPMask(std::string partName);

    SolverAdjCellInteriorNumsUMask&   getAdjCellInterNumsUMask(std::string partName);
    SolverAdjCellInteriorNumsVMask&   getAdjCellInterNumsVMask(std::string partName);
    SolverAdjCellInteriorNumsPMask&   getAdjCellInterNumsPMask(std::string partName);

private:
    datastores::GlobalDataStores& dataStores_;

    std::map<std::string, std::unique_ptr<SolverCellNumsGlobalMask>> mapCellNumsGlobalU_;
    std::map<std::string, std::unique_ptr<SolverCellNumsGlobalMask>> mapCellNumsGlobalV_;
    std::map<std::string, std::unique_ptr<SolverCellNumsGlobalMask>> mapCellNumsGlobalP_;

    std::map<std::string, std::unique_ptr<SolverCellNumsInteriorMask>> mapCellNumsInteriorU_;
    std::map<std::string, std::unique_ptr<SolverCellNumsInteriorMask>> mapCellNumsInteriorV_;
    std::map<std::string, std::unique_ptr<SolverCellNumsInteriorMask>> mapCellNumsInteriorP_;

    std::map<std::string, std::unique_ptr<SolverAdjCellGlobalNumsUMask>> mapAdjCellGlobalNumsU_;
    std::map<std::string, std::unique_ptr<SolverAdjCellGlobalNumsVMask>> mapAdjCellGlobalNumsV_;
    std::map<std::string, std::unique_ptr<SolverAdjCellGlobalNumsPMask>> mapAdjCellGlobalNumsP_;

    std::map<std::string, std::unique_ptr<SolverAdjCellInteriorNumsUMask>> mapAdjCellInteriorNumsU_;
    std::map<std::string, std::unique_ptr<SolverAdjCellInteriorNumsVMask>> mapAdjCellInteriorNumsV_;
    std::map<std::string, std::unique_ptr<SolverAdjCellInteriorNumsPMask>> mapAdjCellInteriorNumsP_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_DATARECIEVER_SOLVERSETSOFMASKS_H