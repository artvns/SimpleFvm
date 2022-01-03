#include "MeshInfo.h"

namespace fvmsolver {

MeshInfo::MeshInfo( PartsTypeInfo& partsTypeInfo, 
                    SolverMeshInfoMask& meshInfoMask) :
                                    partsTypeInfo_(partsTypeInfo),
                                    meshInfoMask_(meshInfoMask) {
    groupeAndCountNames();
}

size_t MeshInfo::getDomainPartsAmount() const {
    return meshInfoMask_.getDomainPartsAmount();
}

size_t MeshInfo::getInteriorPartsAmount() const {
    return interiorParts_;
}

size_t MeshInfo::getBcPartsAmount() const {
    return boundaryParts_;
}

size_t MeshInfo::getAllCellsAmount() const {
    return meshInfoMask_.getAllCellsAmount();
}



std::string MeshInfo::getPartName(const size_t id) const {
    return meshInfoMask_.getPartName(id);
}

std::string MeshInfo::getInteriorName(const size_t id) const {
    return interiorPartNames_.at(id);
}

std::string MeshInfo::getBoundaryName(const size_t id) const {
    return boundaryPartNames_.at(id);
}



size_t MeshInfo::getPartCellsAmount(const std::string name) const {
    return meshInfoMask_.getPartCellsAmount(name);
}



bool MeshInfo::isInterior (const std::string name) const {
    return partsTypeInfo_.isInterior(name);
}

bool MeshInfo::isVelocityInlet (const std::string name) const {
    return partsTypeInfo_.isVelocityInlet(name);
}

bool MeshInfo::isPressureInlet (const std::string name) const {
    return partsTypeInfo_.isPressureInlet(name);
}

bool MeshInfo::isPressureOutlet (const std::string name) const {
    return partsTypeInfo_.isPressureOutlet(name);
}

bool MeshInfo::isMovingWall (const std::string name) const {
    return partsTypeInfo_.isMovingWall(name);
}

bool MeshInfo::isStaticWall (const std::string name) const {
    return partsTypeInfo_.isStaticWall(name);
}



void MeshInfo::groupeAndCountNames() {
    size_t parts = meshInfoMask_.getDomainPartsAmount();

    for (size_t i = 0; i < parts; i++) {
        std::string name = meshInfoMask_.getPartName(i);

        if (partsTypeInfo_.isInterior(name)) {
            interiorPartNames_.push_back(name);
            interiorParts_++;
        }
        else {
            boundaryPartNames_.push_back(name);
            boundaryParts_++;
        }
    }
}

}