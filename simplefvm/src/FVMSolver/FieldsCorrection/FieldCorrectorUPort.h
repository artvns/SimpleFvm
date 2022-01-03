#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORUPORT_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORUPORT_H

#include <cstddef>
#include <string>

#include "FVMSolver/MeshInformation/MeshInfo.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsUMask.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"


namespace fvmsolver {

class FieldCorrectorUPort {
public:
    FieldCorrectorUPort(
                const MeshInfo& meshInfo,
                SolverFieldsMask& fields,
                const SolverCellNumsInteriorMask& numsInterior,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellInteriorNumsUMask& adjCellNumsInter,
                ScalarsStore& scalar,
                CoeffsCalculatorsStore& coeffsCalculators);

    size_t getDomainPartsAmount();
    std::string getPartName(const size_t id);
    size_t getPartCellsAmount(const std::string name);

    CalculatedScalar& getUStar();
    CalculatedScalar& getPPrime();

    double get_deU(const size_t pos) const;

    size_t getGlobNumUp(const size_t step) const;
    size_t getInterNumUp(const size_t step) const;

    size_t getInterNumPp(const size_t step) const;
    size_t getInterNumPe(const size_t step) const;

    void set_u(const size_t pos, double value);

private:
    const MeshInfo& meshInfo_;
    SolverFieldsMask& fields_;
    const SolverCellNumsInteriorMask& numsInterior_;
    const SolverCellNumsGlobalMask& numsGlob_; 
    const SolverAdjCellInteriorNumsUMask& adjCellNumsInter_;
    ScalarsStore& scalar_;
    CoeffsCalculatorsStore& coeffsCalculators_;
};  

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORUPORT_H