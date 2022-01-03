#include "PreparatoryOperationsException.h"



namespace customexceptions {


PreparatoryOperationsException::PreparatoryOperationsException(
                        const std::string errorMessage) :
                                        errorMessage_(errorMessage)  {
                                    
}
	
const char* PreparatoryOperationsException::what() const noexcept { 
    return errorMessage_.c_str(); 
}

}