#include "PartTypeChooserModule.h"

#include "SolverPartTypeChooser.h"

namespace mainsolver {

PartTypeChooserModule::PartTypeChooserModule() : 
                    spObj_(new SolverPartTypeChooser()) {

}

PartTypeChooserModule::~PartTypeChooserModule() {
    delete spObj_;
    spObj_ = nullptr;
}

void PartTypeChooserModule::set_INTERIOR(std::string partName) {
    spObj_->set_INTERIOR(partName);
}

void PartTypeChooserModule::set_MOVING_WALL(std::string partName, 
                                            const double wallVelocity) {

    spObj_->set_MOVING_WALL(partName, wallVelocity);  
}

void PartTypeChooserModule::set_STATIC_WALL(std::string partName) {
    spObj_->set_STATIC_WALL(partName);
}

SolverPartTypeChooser& PartTypeChooserModule::getPartTypeChooser() const {
    return  *spObj_;
}

}