#include "VDataExchangerPort.h"

namespace fvmsolver {

VDataExchangerPort::VDataExchangerPort(
    const SolverMeshParamsMask& mesh, 
    const SolverCellNumsGlobalMask& nums,
    const SolverCellNumsInteriorMask& numsInterior, 
    CoeffsCalculatorsStore& coeffsCalculatorsData) :
                        mesh_(mesh),
                        nums_(nums),
                        numsInterior_(numsInterior),
                        coeffsCalculatorsData_(coeffsCalculatorsData) {

}

size_t VDataExchangerPort::getGlobNumVp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t VDataExchangerPort::get_pNum(size_t step) const {
    return numsInterior_.getCellNumP(step);
}

double VDataExchangerPort::get_dX(size_t num) const {
    return mesh_.get_dX(num);
}

void VDataExchangerPort::set_de(size_t pos, double value) {
    return coeffsCalculatorsData_.set_deV(pos, value);
}

}