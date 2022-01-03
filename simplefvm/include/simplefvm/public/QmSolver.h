#ifndef SIMPLEFVM_QMSOLVER_H
#define SIMPLEFVM_QMSOLVER_H

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "MSolverMacros.h"
#include "AlgorithmChooserModule.h"
#include "FluidPropsModule.h"
#include "SchemeChooserModule.h"
#include "SleSolverChooserModule.h"
#include "PartTypeChooserModule.h"
#include "ResidualsSettingsModule.h"


namespace mainsolver {

class FvmSolver;

class SFVM_API_ QmSolver {
public:
    QmSolver();
    ~QmSolver();

    void defineAlgorithm(const AlgorithmChooserModule& algirithm);
    void defineFluidProperties(const FluidPropsModule& fluidProperties);
    void defineScheme(const SchemeChooserModule& scheme);
    void defineSleSolver(const SleSolverChooserModule& sleSolver);
    void defineBoundaryConditions(const PartTypeChooserModule& partTypes);
    void defineResidualsSettings(const ResidualsSettingsModule& residualsSettings);

    std::vector<std::string>& getBoundaryConditionsNames();

    void loadMesh(const std::string meshFileName, 
                    const double dx, 
                    const double dy);
                    
    void startCalculation(const size_t numberOfIterations);
    void saveFileTxt(const std::string resultFileName);
    void saveFileVtk(const std::string resultFileName);

private:
    FvmSolver* spFvmSolver_ = nullptr;
};

}
#endif // SIMPLEFVM_QMSOLVER_H