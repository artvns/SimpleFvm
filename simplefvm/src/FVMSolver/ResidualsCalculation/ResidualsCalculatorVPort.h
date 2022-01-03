#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORVPORT_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORVPORT_H

#include <cstddef>
#include <string>
#include <vector>

#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/SolverDataStores/SavedCoeffsStore.h"
#include "FVMSolver/SolverDataStores/SavedRhsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"


namespace fvmsolver {

class ResidualsCalculatorVPort {
public:
    ResidualsCalculatorVPort(
                const SolverCellNumsInteriorMask& numsInterior,
                ScalarsStore& scalar,
                SavedCoeffsStore& savedCoeffs,
                SavedRhsStore& savedRhs);

    CalculatedScalar& getVStar();
    size_t getInterNumVp(const size_t step) const;
    size_t getInterNumVw(const size_t step) const;
    size_t getInterNumVe(const size_t step) const;
    size_t getInterNumVn(const size_t step) const;
    size_t getInterNumVs(const size_t step) const;
    std::vector<double>& getAp();
    std::vector<double>& getAw();
    std::vector<double>& getAe();
    std::vector<double>& getAn();
    std::vector<double>& getAs();
    double get_b(const size_t pos) const;

private:
    const SolverCellNumsInteriorMask& numsInterior_;
    ScalarsStore& scalar_;
    SavedCoeffsStore& savedCoeffs_;
    SavedRhsStore& savedRhs_;
};  

}
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORVPORT_H