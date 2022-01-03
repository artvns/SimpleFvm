#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_PREPARATORYOPERATIONSEXCEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_PREPARATORYOPERATIONSEXCEPTION_H

#include <string>
#include <exception>


namespace customexceptions {

class PreparatoryOperationsException : public std::exception {
public:
    PreparatoryOperationsException(const std::string errorMessage);

    virtual const char* what() const noexcept override;
    
private:
	const std::string errorMessage_ = "";
};

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_PREPARATORYOPERATIONSEXCEPTION_H