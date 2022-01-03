#ifndef SIMPLEFVM_CUSTOMEXCEPTIONS_FLUIDPROPERTIESECXEPTION_H
#define SIMPLEFVM_CUSTOMEXCEPTIONS_FLUIDPROPERTIESECXEPTION_H

#include <string>
#include <exception>


namespace customexceptions {

class FluidPropertiesEcxeption : public std::exception {
public: 
    FluidPropertiesEcxeption(std::string errorMessage, const double propValue);

    virtual const char* what() const noexcept override;
    double getPropertyValue() const noexcept;

private:
	std::string errorMessage_ = "";
    const double propValue_ = 0;
};  

}
#endif // SIMPLEFVM_CUSTOMEXCEPTIONS_FLUIDPROPERTIESECXEPTION_H