#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORPPORT_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORPPORT_H

#include <cstddef>
#include <string>

#include "FVMSolver/MeshInformation/MeshInfo.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"


namespace fvmsolver {

class FieldCorrectorPPort {
public:
    FieldCorrectorPPort(
                const MeshInfo& meshInfo,
                SolverFieldsMask& fields,
                const SolverCellNumsInteriorMask& numsInterior,
                const SolverCellNumsGlobalMask& numsGlob, 
                ScalarsStore& scalar);

    size_t getDomainPartsAmount();
    std::string getPartName(const size_t id);
    size_t getPartCellsAmount(const std::string name);

    CalculatedScalar& getPPrime_();

    size_t getGlobNumPp(const size_t step) const;
    size_t getInterNumPp(const size_t step) const;

    double get_p(const size_t pos) const;
    void set_p(const size_t pos, double value);

private:
    const MeshInfo& meshInfo_;
    SolverFieldsMask& fields_;
    const SolverCellNumsInteriorMask& numsInterior_;
    const SolverCellNumsGlobalMask& numsGlob_; 
    ScalarsStore& scalar_;
};  

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORPPORT_H