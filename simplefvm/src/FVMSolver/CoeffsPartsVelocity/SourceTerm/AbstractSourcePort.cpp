#include "AbstractSourcePort.h"

namespace fvmsolver {

AbstractSourcePort::AbstractSourcePort(
                const SolverFluidPropsMask& fluid, 
                const SolverMeshParamsMask& mesh,
                const SolverAdjCellsTypeMask& adjCellsType, 
                const SolverCellNumsGlobalMask& nums) : 
                                    fluid_(fluid), 
                                    mesh_(mesh),
                                    adjCellsType_(adjCellsType),
                                    nums_(nums) {

}

AbstractSourcePort::~AbstractSourcePort() {
    
}

double AbstractSourcePort::getMU() const {
    return fluid_.getMU();
}

double AbstractSourcePort::get_dX(size_t num) const {
    return mesh_.get_dX(num);
}

double AbstractSourcePort::get_dY(size_t num) const {
    return mesh_.get_dY(num);
}

size_t AbstractSourcePort::getNumCellp(size_t step) const {
    return nums_.get_pCellNum(step);
}

size_t AbstractSourcePort::getNumCellw(size_t step) const {
    return nums_.get_wCellNum(step);
}

size_t AbstractSourcePort::getNumCelle(size_t step) const {
    return nums_.get_eCellNum(step);
}

size_t AbstractSourcePort::getNumCelln(size_t step) const {
    return nums_.get_nCellNum(step);
}

size_t AbstractSourcePort::getNumCells(size_t step) const {
      return nums_.get_sCellNum(step);  
}

EnumAdjacentCellTypes AbstractSourcePort::getCellType(size_t num) const {
    return adjCellsType_.getCellType(num);
}

}