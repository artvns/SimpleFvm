#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_SLESOLVEREXCEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_SLESOLVEREXCEPTION_H

#include <string>
#include <exception>


namespace customexceptions {

class SleSolverException : public std::exception {
public: 
    SleSolverException(std::string errorMessage);
	
    virtual const char* what() const noexcept override;

private:
	std::string errorMessage_ = "";
};

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_SLESOLVEREXCEPTION_H