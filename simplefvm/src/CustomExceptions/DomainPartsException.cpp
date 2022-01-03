#include "DomainPartsException.h"



namespace customexceptions {


DomainPartsException::DomainPartsException(
            std::string errorMessage, 
            const std::vector<char> problemPartNames) : 
                                errorMessage_(errorMessage),
                                problemPartNames_(problemPartNames) {

}

	
const char* DomainPartsException::what() const noexcept {
    return errorMessage_.c_str();
}

void DomainPartsException::outputProblemPartNames() const noexcept {
    for (size_t i = 0; i < problemPartNames_.size(); ++i) {
        std::cerr << problemPartNames_.at(i) << '\n';
    }
    std::cerr << '\n';
}

}