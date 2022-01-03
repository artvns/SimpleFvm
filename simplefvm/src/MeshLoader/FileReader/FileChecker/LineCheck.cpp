#include "LineCheck.h"

namespace meshloader {

LineCheck::LineCheck() {

}

void LineCheck::checkLine(const std::string& line, const size_t lineNumber) {
    lineNumber_ = lineNumber + 1;

    if (!isContinuousLine(line)) {
        throw customexceptions::MeshLoadStateException(
                "Mesh file contains unacceptable symbol in:",
                lineNumber_, 
                columnNumber_);
    }

}

bool LineCheck::isContinuousLine(const std::string& line) {
    bool isCorrectLine_ = true;

    for (size_t i = 0; i < line.length(); i++) {
        if (!((line[i] >= 'a' && line[i] <= 'z') | ('0' == line[i]))) {
            isCorrectLine_ = false;
            columnNumber_ = i + 1;
            break;
        }
    }
          
    return isCorrectLine_;
}

}