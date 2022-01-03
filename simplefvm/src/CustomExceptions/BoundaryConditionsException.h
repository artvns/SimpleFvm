#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_BOUNDARYCONDITIONSEXCEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_BOUNDARYCONDITIONSEXCEPTION_H

#include <string>
#include <exception>
#include <vector>
#include <iostream>


namespace customexceptions {

class BoundaryConditionsException : public std::exception {
public:
    BoundaryConditionsException(std::string errorMessage);
    BoundaryConditionsException(std::string errorMessage, 
                                std::vector<std::string> undefinedBcNames);
    
    virtual const char* what() const noexcept override;
    void outputUndefinedBcNames() const noexcept;

private:
	std::string errorMessage_ = "";
    std::vector<std::string> undefinedBcNames_;
};  

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_BOUNDARYCONDITIONSEXCEPTION_H