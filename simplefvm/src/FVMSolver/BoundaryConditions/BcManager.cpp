#include "BcManager.h"

namespace fvmsolver {

BcManager::BcManager(DataManager& dataManager) : 
                        bcNamesValidation_(
                            dataManager.getMeshInfoP(),
                            pPartsTypeInfo_),
                        bcDefinitionStatusCheck_(
                            dataManager.getMeshInfoP(),
                            pPartsTypeInfo_) {

}


void BcManager::checkBoundaryConditions() {
    bcNamesValidation_.validateNames();
    bcDefinitionStatusCheck_.checkStatus();
}


void BcManager::defineInteriorPart(const std::string name) {
    pPartsTypeInfo_.defineTypeAsInterior(name);
}


void BcManager::defineVelocityInletPart(const std::string name) {
    pPartsTypeInfo_.defineTypeAsVelocityInlet(name);
}


void BcManager::definePressureInletPart(const std::string name) {
    pPartsTypeInfo_.defineTypeAsPressureInlet(name);
}


void BcManager::definePressureOutletPart(const std::string name) {
    pPartsTypeInfo_.defineTypeAsPressureOutlet(name);
}


void BcManager::defineMovingWallPart(const std::string name, 
                                     const double wallVelocity) {

    pPartsTypeInfo_.defineTypeAsMovingWall(name);

    uPtrMovingWallBcParamsStore bcParamsStore_ = uPtrMovingWallBcParamsStore(
        new MovingWallBcParamsStore());

    bcParamsStore_->setWallVelocity(wallVelocity);

    mapMovingWallBcParamsSet_.insert(std::make_pair(
        name,std::move(bcParamsStore_)));
}


void BcManager::defineStaticWallPart(const std::string name) {
    pPartsTypeInfo_.defineTypeAsStaticWall(name);
}


PartsTypeInfo& BcManager::getPartsTypeInfo() {
    return pPartsTypeInfo_;
}


MovingWallBcParamsStore& BcManager::getMovingWallBcParamsStore(std::string bcName) {
    return *(mapMovingWallBcParamsSet_[bcName]);
}

}