#ifndef SIMPLEFVM_MESHLOADER_FILEREADER_FILECHECKER_CELLSAMOUNTCHECK_H
#define SIMPLEFVM_MESHLOADER_FILEREADER_FILECHECKER_CELLSAMOUNTCHECK_H

#include <limits>
#include <string>
#include <cstddef>
#include <stdexcept>


namespace meshloader {

class CellsAmountCheck {
public:
    CellsAmountCheck();

    void checkCellsMaxAmount(const size_t currentCellsAmount);

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_FILEREADER_FILECHECKER_CELLSAMOUNTCHECK_H