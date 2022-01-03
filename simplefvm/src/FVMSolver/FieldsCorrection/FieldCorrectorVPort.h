#ifndef SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORVPORT_H
#define SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORVPORT_H

#include <cstddef>
#include <string>

#include "FVMSolver/MeshInformation/MeshInfo.h"
#include "FVMSolver/DataReciever/Fields/SolverFieldsMask.h"
#include "FVMSolver/DataReciever/CellNumsGlobal/SolverCellNumsGlobalMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/DataReciever/CellNumsInterior/SolverAdjCellInteriorNumsVMask.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/SolverDataStores/CoeffsCalculatorsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"


namespace fvmsolver {

class FieldCorrectorVPort {
public:
    FieldCorrectorVPort(
                    MeshInfo& meshInfo,
                    SolverFieldsMask& fields,
                    const SolverCellNumsInteriorMask& numsInterior,
                    const SolverCellNumsGlobalMask& numsGlob, 
                    const SolverAdjCellInteriorNumsVMask& adjCellNumsInter,
                    ScalarsStore& scalar,
                    CoeffsCalculatorsStore& coeffsCalculators);

    size_t getDomainPartsAmount();
    std::string getPartName(const size_t id);
    size_t getPartCellsAmount(const std::string name);

    CalculatedScalar& getVStar();
    CalculatedScalar& getPPrime();

    double get_deV(const size_t pos) const;

    size_t getGlobNumVp(const size_t step) const;
    size_t getInterNumVp(const size_t step) const;

    size_t getInterNumPp(const size_t step) const;
    size_t getInterNumPn(const size_t step) const;

    void set_v(const size_t pos, double value);

private:
    MeshInfo& meshInfo_;
    SolverFieldsMask& fields_;
    const SolverCellNumsInteriorMask& numsInterior_;
    const SolverCellNumsGlobalMask& numsGlob_; 
    const SolverAdjCellInteriorNumsVMask& adjCellNumsInter_;
    ScalarsStore& scalar_;
    CoeffsCalculatorsStore& coeffsCalculators_;
};  

}
#endif // SIMPLEFVM_FVMSOLVER_FIELDSCORRECTION_FIELDCORRECTORVPORT_H