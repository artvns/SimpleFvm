#include "SolverSettingsException.h"



namespace customexceptions {


SolverSettingsException::SolverSettingsException(
                std::string errorMessage) : 
                                errorMessage_(errorMessage) {
                                    
}
	
const char* SolverSettingsException::what() const noexcept { 
    return errorMessage_.c_str(); 
}

}