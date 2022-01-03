#include "BoundaryConditionsException.h"



namespace customexceptions {


BoundaryConditionsException::BoundaryConditionsException(
            std::string errorMessage) : 
                                errorMessage_(errorMessage) {

}


BoundaryConditionsException::BoundaryConditionsException(
            std::string errorMessage, 
            std::vector<std::string> undefinedBcNames) : 
                                errorMessage_(errorMessage),
                                undefinedBcNames_(undefinedBcNames) {
                                    
}


const char* BoundaryConditionsException::what() const noexcept { 
    return errorMessage_.c_str(); 
}


void BoundaryConditionsException::outputUndefinedBcNames() const noexcept {
    for (size_t i = 0; i < undefinedBcNames_.size(); ++i) {
        std::cerr << undefinedBcNames_.at(i) << '\n';
    }
    std::cerr << '\n';
}

}