#ifndef SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORUPORT_H
#define SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORUPORT_H

#include <cstddef>
#include <string>
#include <vector>

#include "FVMSolver/DataReciever/CellNumsInterior/SolverCellNumsInteriorMask.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/ScalarsStore.h"
#include "FVMSolver/SolverDataStores/SavedCoeffsStore.h"
#include "FVMSolver/SolverDataStores/SavedRhsStore.h"
#include "FVMSolver/MathToolsReciever/SleSolverTool/CalculatedScalar.h"


namespace fvmsolver {

class ResidualsCalculatorUPort {
public:
    ResidualsCalculatorUPort(
                const SolverCellNumsInteriorMask& numsInterior,
                ScalarsStore& scalar,
                SavedCoeffsStore& savedCoeffs,
                SavedRhsStore& savedRhs);

    CalculatedScalar& getUStar();
    size_t getInterNumUp(const size_t step) const;
    size_t getInterNumUw(const size_t step) const;
    size_t getInterNumUe(const size_t step) const;
    size_t getInterNumUn(const size_t step) const;
    size_t getInterNumUs(const size_t step) const;
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
#endif // SIMPLEFVM_FVMSOLVER_RESIDUALSCALCULATION_RESIDUALSCALCULATORUPORT_H