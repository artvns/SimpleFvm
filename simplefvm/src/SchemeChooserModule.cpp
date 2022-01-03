#include "SchemeChooserModule.h"

#include "SolverSchemeChooser.h"

namespace mainsolver {

SchemeChooserModule::SchemeChooserModule() : 
                spObj_(new SolverSchemeChooser()) {

}

SchemeChooserModule::~SchemeChooserModule() {
    delete spObj_;
    spObj_ = nullptr;
}

void SchemeChooserModule::select_CENTRAL() {
    spObj_->select_CENTRAL();
}

void SchemeChooserModule::select_UPWIND() {
    spObj_->select_UPWIND();
}

void SchemeChooserModule::select_HYBRID() {
    spObj_->select_HYBRID();
}

bool SchemeChooserModule::isCENTRAL() {
    return spObj_->isCENTRAL();
}

bool SchemeChooserModule::isUPWIND() {
    return spObj_->isUPWIND();
}

bool SchemeChooserModule::isHYBRID() {
    return spObj_->isHYBRID();
}

SolverSchemeChooser& SchemeChooserModule::getSchemeChooser() const {
    return  *spObj_;
}

}