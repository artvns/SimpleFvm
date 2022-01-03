#include "ReaderTxt.h"

namespace meshloader {

ReaderTxt::ReaderTxt() {

}

void ReaderTxt::load(std::string fileName, BaseMatrix& baseMatrix) {
    size_t maxLines_  = 0;
    size_t maxColumns_ = 0;

    std::string strLine_;
    std::ifstream file;

    file.exceptions(std::ifstream::badbit |std::ifstream::failbit);
    file.open(fileName, std::ifstream::in);

    // Counting number of lines and columns.
    while (!file.eof()) {
        std::getline(file, strLine_);
        size_t lineLength_ = std::strcspn(strLine_.c_str(), "\r\n");

        if (lineLength_ > maxColumns_) {
            maxColumns_ = lineLength_;
        }
        maxLines_++;
    }


    baseMatrix.createMatrix(maxLines_, maxColumns_);
    cellsAmountCheck_.checkCellsMaxAmount(maxLines_ * maxColumns_);


    // Reading mesh file content in matrix.
    size_t rowNum_ = 0;
    strLine_.clear();
    file.clear();
    file.seekg(0);

    while (!file.eof()) {
        std::getline(file, strLine_);

        lineCheck_.checkLine(strLine_, rowNum_);

        strLine_.erase(std::remove(strLine_.begin(), strLine_.end(), '\n'), strLine_.end());
        strLine_.erase(std::remove(strLine_.begin(), strLine_.end(), '\r'), strLine_.end());

        for (size_t j = 0; j < maxColumns_; j++) {
            baseMatrix.setValue(rowNum_, j, strLine_.at(j));
        }

        rowNum_++;
    }
    file.close();
}

}