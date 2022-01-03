#include "ReaderTxt.h"

namespace integr_tests {

ReaderTxt::ReaderTxt() {

}

void ReaderTxt::readFile(std::string fileName) {
    fileData_.clear();
    linesAmount_ = 0;

    std::string strLine_;
    std::ifstream file;

    // file.exceptions(std::ifstream::badbit |std::ifstream::failbit);
    file.open(fileName, std::ifstream::in);

    // Count lines.
    while (!file.eof()) {
        std::getline(file, strLine_);
        linesAmount_++;
    }

    fileData_.reserve(linesAmount_);


    // Read file content.
    strLine_.clear();
    file.clear();
    file.seekg(0);

    while (!file.eof()) {
        std::getline(file, strLine_);
        fileData_.push_back(strLine_);      
    }

    file.close();
}

size_t ReaderTxt::getLinesAmount() {
    return linesAmount_;
}

std::string ReaderTxt::getLine(size_t linePos) {
    return fileData_[linePos];
}

void ReaderTxt::clearData() {
    fileData_.clear();
    linesAmount_ = 0;
}

}