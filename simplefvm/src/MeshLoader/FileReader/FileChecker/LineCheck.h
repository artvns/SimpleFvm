#ifndef SIMPLEFVM_MESHLOADER_FILEREADER_FILECHECKER_LINECHECK_H
#define SIMPLEFVM_MESHLOADER_FILEREADER_FILECHECKER_LINECHECK_H

#include <string>
#include <cstddef>

#include "CustomExceptions/MeshLoadStateException.h"


namespace meshloader {

class LineCheck {
public:
    LineCheck();

    void checkLine(const std::string& line, const size_t lineNumber);

private:
    size_t lineNumber_ = 0;
    size_t columnNumber_ = 0;

    bool isContinuousLine(const std::string& line);
};

}
#endif // SIMPLEFVM_MESHLOADER_FILEREADER_FILECHECKER_LINECHECK_H