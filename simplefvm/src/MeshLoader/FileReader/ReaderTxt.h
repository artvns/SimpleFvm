#ifndef SIMPLEFVM_MESHLOADER_FILEREADER_READERTXT_H
#define SIMPLEFVM_MESHLOADER_FILEREADER_READERTXT_H

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include <cstring>
#include <vector>
#include <algorithm>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"

#include "FileChecker/LineCheck.h"
#include "FileChecker/CellsAmountCheck.h"
#include "IFileReader.h"


namespace meshloader {

class ReaderTxt : public IFileReader {
public:
    ReaderTxt();

    void load(std::string fileName, BaseMatrix& baseMatrix) override;
    size_t getMaxNumberOfCells();

private:
    LineCheck lineCheck_;
    CellsAmountCheck cellsAmountCheck_;
};

}
#endif // SIMPLEFVM_MESHLOADER_FILEREADER_READERTXT_H