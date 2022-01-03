#include "MeshLoadStateException.h"



namespace customexceptions {


MeshLoadStateException::MeshLoadStateException(
                        std::string errorMessage, 
                        size_t rowNumber, 
                        size_t columnNumber) :
                                errorMessage_(errorMessage),
                                rowNumber_(rowNumber),
                                columnNumber_(columnNumber) {

}

	
const char* MeshLoadStateException::what() const noexcept {
    return errorMessage_.c_str();
}

size_t MeshLoadStateException::getLineNumber() const noexcept {
    return rowNumber_;
}

size_t MeshLoadStateException::getColumnNumber() const noexcept {
    return columnNumber_;
}

}