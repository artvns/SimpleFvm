#include "FieldCorrectorPPort.h"

namespace fvmsolver {

FieldCorrectorPPort::FieldCorrectorPPort(
                const MeshInfo& meshInfo,
                SolverFieldsMask& fields,
                const SolverCellNumsInteriorMask& numsInterior,
                const SolverCellNumsGlobalMask& numsGlob, 
                ScalarsStore& scalar) : 
                                meshInfo_(meshInfo), 
                                fields_(fields),
                                numsInterior_(numsInterior),
                                numsGlob_(numsGlob),
                                scalar_(scalar) {

}

size_t FieldCorrectorPPort::getDomainPartsAmount() {
    return meshInfo_.getDomainPartsAmount();
}

std::string FieldCorrectorPPort::getPartName(const size_t id) {
    return meshInfo_.getPartName(id);
}

size_t FieldCorrectorPPort::getPartCellsAmount(const std::string name) {
    return meshInfo_.getPartCellsAmount(name);
}

CalculatedScalar& FieldCorrectorPPort::getPPrime_() {
    return scalar_.get_pPrime();
}

size_t FieldCorrectorPPort::getGlobNumPp(const size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t FieldCorrectorPPort::getInterNumPp(const size_t step) const {
    return numsInterior_.getCellNumP(step);
}

double FieldCorrectorPPort::get_p(const size_t pos) const {
    return fields_.getP(pos);
}

void FieldCorrectorPPort::set_p(const size_t pos, double value) {
    fields_.setP(pos, value);
}

}