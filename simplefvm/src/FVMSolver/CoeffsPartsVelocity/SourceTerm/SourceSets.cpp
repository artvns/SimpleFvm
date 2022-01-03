#include "SourceSets.h"

namespace fvmsolver {

SourceSets::SourceSets(
                DataManager& dataManager,
                MeshInfoManager& meshInfoManager,
                BcManager& bcManager) : 
                            dataPorts_(dataManager, bcManager),
                            meshInfoManager_(meshInfoManager) {

}

SourceSets::shPtrMapAbstSource SourceSets::createSetForU() {
    pSourceSetU_ = shPtrMapAbstSource(
        new MapAdt<std::unique_ptr<AbstractSource>>());

    size_t part = meshInfoManager_.getMeshInfoU()->getDomainPartsAmount();

    for (size_t i = 0; i < part; i++) {
        std::string name = meshInfoManager_.getMeshInfoU()->getPartName(i);

        std::unique_ptr<AbstractSource> spInnerObj_ = nullptr;

        if (meshInfoManager_.getMeshInfoU()->isInterior(name)) {
            spInnerObj_ = std::unique_ptr<InteriorSource>(new InteriorSource());
            pSourceSetU_->addObjectUniquePtr(name, std::move(spInnerObj_));
        }
        else if (meshInfoManager_.getMeshInfoU()->isStaticWall(name)) {
            spInnerObj_ = std::unique_ptr<StaticWallSource>(
                new StaticWallSource(dataPorts_.createPortU(name)));
            pSourceSetU_->addObjectUniquePtr(name, std::move(spInnerObj_));
        }
        else if (meshInfoManager_.getMeshInfoU()->isMovingWall(name)) {
            spInnerObj_ = std::unique_ptr<MovingWallSource>(
                new MovingWallSource(dataPorts_.createPortU(name)));
            pSourceSetU_->addObjectUniquePtr(name, std::move(spInnerObj_));
        }
    }
 
    return pSourceSetU_;
}

SourceSets::shPtrMapAbstSource SourceSets::createSetForV() {
    pSourceSetV_ = shPtrMapAbstSource(
        new MapAdt<std::unique_ptr<AbstractSource>>());

    size_t part = meshInfoManager_.getMeshInfoV()->getDomainPartsAmount();

    for (size_t i = 0; i < part; i++) {
        std::string name = meshInfoManager_.getMeshInfoV()->getPartName(i);

        std::unique_ptr<AbstractSource> spInnerObj_ = nullptr;


        if (meshInfoManager_.getMeshInfoV()->isInterior(name)) {
            spInnerObj_ = std::unique_ptr<InteriorSource>(new InteriorSource());
            pSourceSetV_->addObjectUniquePtr(name, std::move(spInnerObj_));
        }
        else if (meshInfoManager_.getMeshInfoV()->isStaticWall(name)) {
            spInnerObj_ = std::unique_ptr<StaticWallSource>(
                new StaticWallSource(dataPorts_.createPortV(name)));
            pSourceSetV_->addObjectUniquePtr(name, std::move(spInnerObj_));    
        }
        else if (meshInfoManager_.getMeshInfoV()->isMovingWall(name)) {
            spInnerObj_ = std::unique_ptr<MovingWallSource>(
                new MovingWallSource(dataPorts_.createPortV(name)));
            pSourceSetV_->addObjectUniquePtr(name, std::move(spInnerObj_));    
        }
    }
    return pSourceSetV_;
}

}