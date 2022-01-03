#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_MESHLOADSTATEEXCEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_MESHLOADSTATEEXCEPTION_H

#include <cstddef>
#include <string>
#include <exception>


namespace customexceptions {

class MeshLoadStateException : public std::exception {
public:
    MeshLoadStateException(std::string errorMessage, 
                            size_t rowNumber, 
                            size_t columnNumber);
	
    virtual const char* what() const noexcept override;
    size_t getLineNumber() const noexcept;
    size_t getColumnNumber() const noexcept;

private:
	std::string errorMessage_ = "";
    size_t rowNumber_ = 0;
    size_t columnNumber_ = 0;
};  

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_MESHLOADSTATEEXCEPTION_H