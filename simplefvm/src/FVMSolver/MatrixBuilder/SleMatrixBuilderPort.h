#ifndef SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERPORT_H
#define SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERPORT_H

#include <cstddef>
#include <string>
#include <vector>

#include "FVMSolver/MeshInformation/MeshInfo.h"
#include "FVMSolver/SolverDataStores/SavedCoeffsStore.h"
#include "FVMSolver/SolverDataStores/SavedRhsStore.h"


namespace fvmsolver {

class SleMatrixBuilderPort {
public:
    SleMatrixBuilderPort(MeshInfo& meshInfo, 
                        SavedCoeffsStore& savedCoeffs,
                        SavedRhsStore& savedRhs);

    size_t getDomainPartsAmount();
    size_t getInteriorPartsAmount();
    size_t getBcPartsAmount();
    size_t getAllCellsAmount();

    std::string getPartName    (const size_t id);
    std::string getInteriorName(const size_t id);
    std::string getBoundaryName(const size_t id);

    size_t getPartCellsAmount(const std::string name);

    std::vector<double>& getAp();
    std::vector<double>& getAw();
    std::vector<double>& getAe();
    std::vector<double>& getAn();
    std::vector<double>& getAs();

    void setRhs(const size_t pos, double value);
    void set_b(const size_t pos, double value);

private:
    MeshInfo& meshInfo_;
    SavedCoeffsStore& savedCoeffs_;
    SavedRhsStore& savedRhs_;
};

}
#endif // SIMPLEFVM_FVMSOLVER_MATRIXBUILDER_SLEMATRIXBUILDERPORT_H