#include "SleMatrixBuilderPort.h"

namespace fvmsolver {

SleMatrixBuilderPort::SleMatrixBuilderPort(
                        MeshInfo& meshInfo, 
                        SavedCoeffsStore& savedCoeffs,
                        SavedRhsStore& savedRhs) : 
                                meshInfo_(meshInfo),
                                savedCoeffs_(savedCoeffs),
                                savedRhs_(savedRhs) {

}

size_t SleMatrixBuilderPort::getDomainPartsAmount() {
    return meshInfo_.getDomainPartsAmount();
}

size_t SleMatrixBuilderPort::getInteriorPartsAmount() {
    return meshInfo_.getInteriorPartsAmount();
}

size_t SleMatrixBuilderPort::getBcPartsAmount() {
    return meshInfo_.getBcPartsAmount();
}

size_t SleMatrixBuilderPort::getAllCellsAmount() {
    return meshInfo_.getAllCellsAmount();
}

std::string SleMatrixBuilderPort::getPartName(const size_t id) {
    return meshInfo_.getPartName(id);
}

std::string SleMatrixBuilderPort::getInteriorName(const size_t id) {
    return meshInfo_.getInteriorName(id);
}

std::string SleMatrixBuilderPort::getBoundaryName(const size_t id) {
    return meshInfo_.getBoundaryName(id);
}

size_t SleMatrixBuilderPort::getPartCellsAmount(const std::string name) {
    return meshInfo_.getPartCellsAmount(name);
}

std::vector<double>& SleMatrixBuilderPort::getAp() {
    return savedCoeffs_.getAp();
}

std::vector<double>& SleMatrixBuilderPort::getAw() {
    return savedCoeffs_.getAw();
}

std::vector<double>& SleMatrixBuilderPort::getAe() {
    return savedCoeffs_.getAe();
}

std::vector<double>& SleMatrixBuilderPort::getAn() {
    return savedCoeffs_.getAn();
}

std::vector<double>& SleMatrixBuilderPort::getAs() {
    return savedCoeffs_.getAs();
}

void SleMatrixBuilderPort::setRhs(const size_t pos, double value) {
    return savedRhs_.setRhs(pos, value);
}

void SleMatrixBuilderPort::set_b(const size_t pos, double value) {
    return savedRhs_.set_b(pos, value);
}

}