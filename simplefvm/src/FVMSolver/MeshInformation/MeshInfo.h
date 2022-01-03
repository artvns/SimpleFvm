#ifndef SIMPLEFVM_FVMSOLVER_MESHINFORMATION_MESHINFO_H
#define SIMPLEFVM_FVMSOLVER_MESHINFORMATION_MESHINFO_H

#include <cstddef>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

#include "FVMSolver/BoundaryConditions/PartsTypeInfo.h"
#include "FVMSolver/DataReciever/MeshInformation/SolverMeshInfoMask.h"


namespace fvmsolver {

class MeshInfo {
public:
    MeshInfo(PartsTypeInfo& partsTypeInfo, SolverMeshInfoMask& meshInfoStore);

    size_t getDomainPartsAmount() const;
    size_t getInteriorPartsAmount() const;
    size_t getBcPartsAmount() const;
    size_t getAllCellsAmount() const;

    std::string getPartName (const size_t id) const;
    std::string getInteriorName(const size_t id) const;
    std::string getBoundaryName(const size_t id) const;

    size_t getPartCellsAmount(const std::string name) const;

    bool isInterior      (const std::string name) const;
    bool isVelocityInlet (const std::string name) const;
    bool isPressureInlet (const std::string name) const;
    bool isPressureOutlet(const std::string name) const;
    bool isMovingWall    (const std::string name) const;
    bool isStaticWall    (const std::string name) const;

private:
    PartsTypeInfo& partsTypeInfo_;
    SolverMeshInfoMask& meshInfoMask_;

    size_t interiorParts_ = 0;
    size_t boundaryParts_ = 0;

    size_t interiorCellsAmount_ = 0;

    std::vector<std::string> interiorPartNames_;
    std::vector<std::string> boundaryPartNames_;

    void groupeAndCountNames();
};

}
#endif // SIMPLEFVM_FVMSOLVER_MESHINFORMATION_MESHINFO_H