#include "PDataExchangerPort.h"

namespace fvmsolver {

PDataExchangerPort::PDataExchangerPort(
        const SolverCellNumsInteriorMask& numsInterior,
        const SolverAdjCellInteriorNumsPMask& adjInterNums, 
        const CoeffsCalculatorsStore& coeffsCalculatorsData) :
                        numsInterior_(numsInterior),
                        adjInterNums_(adjInterNums),
                        coeffsCalculatorsData_(coeffsCalculatorsData) {

}

size_t PDataExchangerPort::getNumUStarW(size_t step) const {
    return adjInterNums_.get_numUStarW(step);
}

size_t PDataExchangerPort::getNumUStarE(size_t step) const {
    return adjInterNums_.get_numUStarE(step);
}

size_t PDataExchangerPort::getNumVStarN(size_t step) const {
    return adjInterNums_.get_numVStarN(step);
}

size_t PDataExchangerPort::getNumVStarS(size_t step) const {
    return adjInterNums_.get_numVStarS(step);
}


double PDataExchangerPort::get_deU(size_t num) const {
    return coeffsCalculatorsData_.get_deU(num);
}

double PDataExchangerPort::get_deV(size_t num) const {
    return coeffsCalculatorsData_.get_deV(num);
}

}