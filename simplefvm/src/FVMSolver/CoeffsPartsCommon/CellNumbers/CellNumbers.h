#ifndef SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMBERS_H
#define SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMBERS_H

#include <cstddef>
#include <memory>

#include "CellNumbersPort.h"


namespace fvmsolver {

class CellNumbers {
private:
    using uPtrDataPort = std::unique_ptr<CellNumbersPort>;

public:
    CellNumbers(uPtrDataPort spData);

    void assignCurrentCellValues(size_t step);
    size_t get_wNum();
    size_t get_eNum();
    size_t get_nNum();
    size_t get_sNum();
    size_t get_pNum();
    
private:
    uPtrDataPort spData_ = nullptr;
    const CellNumbersPort& data_;

    size_t wNum_ = 0;
    size_t eNum_ = 0;
    size_t nNum_ = 0;
    size_t sNum_ = 0;
    size_t pNum_ = 0;
};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSPARTSCOMMON_CELLNUMBERS_CELLNUMBERS_H