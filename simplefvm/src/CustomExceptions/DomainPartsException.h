#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_DOMAINPARTSEXCEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_DOMAINPARTSEXCEPTION_H

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include <exception>


namespace customexceptions {

class DomainPartsException : public std::exception {
public:
    DomainPartsException(std::string errorMessage, 
                            const std::vector<char> problemPartNames);
	
    virtual const char* what() const noexcept override;
    void outputProblemPartNames() const noexcept;

private:
	std::string errorMessage_ = "";
    const std::vector<char> problemPartNames_;
};

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_DOMAINPARTSEXCEPTION_H