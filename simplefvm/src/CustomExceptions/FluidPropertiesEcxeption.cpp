#include "FluidPropertiesEcxeption.h"



namespace customexceptions {


FluidPropertiesEcxeption::FluidPropertiesEcxeption(
                std::string errorMessage,
                const double propValue) : 
                                errorMessage_(errorMessage),
                                propValue_(propValue) {
                                    
}
	
const char* FluidPropertiesEcxeption::what() const noexcept { 
    return errorMessage_.c_str(); 
}

double FluidPropertiesEcxeption::getPropertyValue() const noexcept { 
    return propValue_; 
}

}