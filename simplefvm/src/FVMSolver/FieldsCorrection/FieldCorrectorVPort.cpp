#include "FieldCorrectorVPort.h"

namespace fvmsolver {

FieldCorrectorVPort::FieldCorrectorVPort(
                MeshInfo& meshInfo,
                SolverFieldsMask& fields,
                const SolverCellNumsInteriorMask& numsInterior,
                const SolverCellNumsGlobalMask& numsGlob, 
                const SolverAdjCellInteriorNumsVMask& adjCellNumsInter,
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

size_t FieldCorrectorVPort::getDomainPartsAmount() {
    return meshInfo_.getDomainPartsAmount();
}

std::string FieldCorrectorVPort::getPartName(const size_t id) {
    return meshInfo_.getPartName(id);
}

size_t FieldCorrectorVPort::getPartCellsAmount(const std::string name) {
    return meshInfo_.getPartCellsAmount(name);
}

CalculatedScalar& FieldCorrectorVPort::getVStar() {
    return scalar_.get_vStar();  
}

CalculatedScalar& FieldCorrectorVPort::getPPrime() {
    return scalar_.get_pPrime();
}

double FieldCorrectorVPort::get_deV(const size_t pos) const {
    return coeffsCalculators_.get_deV(pos);
}

size_t FieldCorrectorVPort::getInterNumVp(const size_t step) const {
    return numsInterior_.getCellNumP(step);
}

size_t FieldCorrectorVPort::getGlobNumVp(const size_t step) const {
    return numsGlob_.get_pCellNum(step);
}

size_t FieldCorrectorVPort::getInterNumPp(const size_t step) const {
    return adjCellNumsInter_.get_numPp(step);
}

size_t FieldCorrectorVPort::getInterNumPn(const size_t step) const {
    return adjCellNumsInter_.get_numPs(step);
}

void FieldCorrectorVPort::set_v(const size_t pos, double value) {
    fields_.setV(pos, value);
}

}