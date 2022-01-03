#ifndef SIMPLEFVM_FASTTEST_FILEREADER_IFILEREADER_H
#define SIMPLEFVM_FASTTEST_FILEREADER_IFILEREADER_H

#include <string>

namespace fasttest {

class IFileReader {
public:
    virtual void readFile(std::string fileName) = 0;
    virtual size_t getLinesAmount() = 0;
    virtual std::string getLine(size_t linePos) = 0;
    virtual void clearData() = 0;

    virtual ~IFileReader() {};
};

}
#endif // SIMPLEFVM_FASTTEST_FILEREADER_IFILEREADER_H