#include "UDataExchangerPort.h"

namespace fvmsolver {

UDataExchangerPort::UDataExchangerPort(
    const SolverMeshParamsMask& mesh, 
    const SolverCellNumsGlobalMask& nums,
    const SolverCellNumsInteriorMask& numsInterior,
    CoeffsCalculatorsStore& coeffsCalculatorsData) :
                        mesh_(mesh),
                        nums_(nums),
                        numsInterior_(numsInterior),
                        coeffsCalculatorsData_(coeffsCalculatorsData) {

}

size_t UDataExchangerPort::getGlobNumUp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t UDataExchangerPort::get_pNum(size_t step) const {
    return numsInterior_.getCellNumP(step);
}

double UDataExchangerPort::get_dY(size_t num) const {
    return mesh_.get_dY(num);
}

void UDataExchangerPort::set_de(size_t pos, double value) {
    return coeffsCalculatorsData_.set_deU(pos, value);
}

}