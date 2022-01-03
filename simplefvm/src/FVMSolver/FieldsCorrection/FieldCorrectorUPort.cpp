#include "FieldCorrectorUPort.h"

namespace fvmsolver {

FieldCorrectorUPort::FieldCorrectorUPort(
                const MeshInfo& meshInfo,
                SolverFieldsMask& fields,
                const SolverCellNumsInteriorMask& numsInterior,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellInteriorNumsUMask& adjCellNumsInter,
                ScalarsStore& scalar,
                CoeffsCalculatorsStore& coeffsCalculators) : 
                                meshInfo_(meshInfo), 
                                fields_(fields),
                                numsInterior_(numsInterior),
                                numsGlob_(numsGlob),
                                adjCellNumsInter_(adjCellNumsInter),
                                scalar_(scalar),
                                coeffsCalculators_(coeffsCalculators) {

}


size_t FieldCorrectorUPort::getDomainPartsAmount() {
    return meshInfo_.getDomainPartsAmount();
}

std::string FieldCorrectorUPort::getPartName(const size_t id) {
    return meshInfo_.getPartName(id);
}

size_t FieldCorrectorUPort::getPartCellsAmount(const std::string name) {
    return meshInfo_.getPartCellsAmount(name);
}

CalculatedScalar& FieldCorrectorUPort::getUStar() {
    return scalar_.get_uStar();  
}

CalculatedScalar& FieldCorrectorUPort::getPPrime() {
    return scalar_.get_pPrime();
}

double FieldCorrectorUPort::get_deU(const size_t pos) const {
    return coeffsCalculators_.get_deU(pos);
}

size_t FieldCorrectorUPort::getInterNumUp(const size_t step) const {
    return numsInterior_.getCellNumP(step);
}

size_t FieldCorrectorUPort::getGlobNumUp(const size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t FieldCorrectorUPort::getInterNumPp(const size_t step) const {
    return adjCellNumsInter_.get_numPw(step);
}

size_t FieldCorrectorUPort::getInterNumPe(const size_t step) const {
    return adjCellNumsInter_.get_numPp(step);
}

void FieldCorrectorUPort::set_u(const size_t pos, double value) {
    fields_.setU(pos, value);
}

}