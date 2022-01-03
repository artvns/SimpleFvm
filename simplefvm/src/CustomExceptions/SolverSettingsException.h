#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_SOLVERSETTINGSEXCEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_SOLVERSETTINGSEXCEPTION_H

#include <string>
#include <exception>


namespace customexceptions {

class SolverSettingsException : public std::exception {
public: 
    SolverSettingsException(std::string errorMessage);
	
    virtual const char* what() const noexcept override;

private:
	std::string errorMessage_ = "";
};

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_SOLVERSETTINGSEXCEPTION_H