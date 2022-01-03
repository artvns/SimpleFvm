#ifndef SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDER_H
#define SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDER_H

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "FVMSolver/MathToolsReciever/SleSolverTool/SleSolver.h"
#include "FVMSolver/CoeffsCalculators/Calculators/AbstractCoeffsCalculator.h"
#include "FVMSolver/CoeffsPartsCommon/CellNumbers/CellNumbers.h"

#include "SleMatrixBuilderPort.h"


namespace fvmsolver {

class SleMatrixBuilder {
private:
    using uPtrDataPort = std::unique_ptr<SleMatrixBuilderPort>;

public:
    SleMatrixBuilder(AbstractCoeffsCalculator& coeffsCalculator, 
                     uPtrDataPort spData);

    void build(std::shared_ptr<SleSolver> sleSolver);

private:
    uPtrDataPort spDataPort_ = nullptr;
    SleMatrixBuilderPort& dataPort_;
    AbstractCoeffsCalculator& coeffsCalculator_;

    std::vector<double>& aP_;
    std::vector<double>& aW_;
    std::vector<double>& aE_;
    std::vector<double>& aN_;
    std::vector<double>& aS_;

    std::shared_ptr<SleSolver> pSleSolver_ = nullptr;

    void createMatrixAndVectors();
    void buildInterior();
    void buildBoundary();

    void placeAllCoeffs();

    void placeCoeffsMainDiag(size_t rowNum, size_t colNum, double value);
    void placeCoeffsOtherDiags(size_t rowNum, size_t colNum, 
                                        double value, bool isInteriorCell);

    void saveCoeff(size_t pos, double value, std::vector<double>& coeff);
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDER_H