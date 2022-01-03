#include "SleSolverException.h"



namespace customexceptions {


SleSolverException::SleSolverException(
                std::string errorMessage) : 
                                errorMessage_(errorMessage) {
                                    
}
	
const char* SleSolverException::what() const noexcept { 
    return errorMessage_.c_str(); 
}

}