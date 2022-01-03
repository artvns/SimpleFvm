#ifndef SIMPLEFVM_INTEGRATIONTESTS_FILEREADER_READERTXT_H
#define SIMPLEFVM_INTEGRATIONTESTS_FILEREADER_READERTXT_H

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include <cstring>
#include <vector>
#include <algorithm>

#include "IFileReader.h"


namespace integr_tests {

class ReaderTxt : public IFileReader {
public:
    ReaderTxt();

    void readFile(std::string fileName) override;
    size_t getLinesAmount() override;
    std::string getLine(size_t linePos) override;
    void clearData() override;

private:
    size_t linesAmount_ = 0;
    std::vector<std::string> fileData_;
};

}
#endif // SIMPLEFVM_INTEGRATIONTESTS_FILEREADER_READERTXT_H