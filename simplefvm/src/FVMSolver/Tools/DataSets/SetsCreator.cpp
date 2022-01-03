#ifndef SIMPLEFVM_FVMSOLVER_TOOLS_DATASETS_SETSCREATOR_H
#define SIMPLEFVM_FVMSOLVER_TOOLS_DATASETS_SETSCREATOR_H

#include <cstddef>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"


namespace fvmsolver {

template <class T, class D, class L>
class SetsCreator {
public:
    SetsCreator(MeshInfoManager& meshInfoManager) : 
                                meshInfoManager_(meshInfoManager) {}

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> createSetForU(D& dataPort);
    std::shared_ptr<MapAdt<std::unique_ptr<T>>> createSetForV(D& dataPort);
    std::shared_ptr<MapAdt<std::unique_ptr<T>>> createSetForP(D& dataPort);

private:
    MeshInfoManager& meshInfoManager_;
};


template <class T, class D, class L>
std::shared_ptr<MapAdt<std::unique_ptr<T>>> SetsCreator<T, D, L>::createSetForU(D& dataPort) {

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> pDataSetU_ = nullptr;
    pDataSetU_ = std::shared_ptr<MapAdt<std::unique_ptr<T>>>(new MapAdt<std::unique_ptr<T>>());

    size_t parts = meshInfoManager_.getMeshInfoU()->getDomainPartsAmount();

    for (size_t i = 0; i < parts; i++) {
        std::string name = meshInfoManager_.getMeshInfoU()->getPartName(i);

        std::unique_ptr<T> pInnerObj_ = std::unique_ptr<T>(new L(dataPort.createPortU(name)));
        pDataSetU_->addObjectUniquePtr(name, std::move(pInnerObj_));
    }
    return pDataSetU_;
}



template <class T, class D, class L>
std::shared_ptr<MapAdt<std::unique_ptr<T>>> SetsCreator<T, D, L>::createSetForV(D& dataPort) {

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> pDataSetV_ = nullptr;
    pDataSetV_ = std::shared_ptr<MapAdt<std::unique_ptr<T>>>(new MapAdt<std::unique_ptr<T>>());

    size_t parts = meshInfoManager_.getMeshInfoV()->getDomainPartsAmount();

    for (size_t i = 0; i < parts; i++) {
        std::string name = meshInfoManager_.getMeshInfoV()->getPartName(i);

        std::unique_ptr<T> pInnerObj_ = std::unique_ptr<T>(new L(dataPort.createPortV(name)));
        pDataSetV_->addObjectUniquePtr(name, std::move(pInnerObj_));
    }
    return pDataSetV_;    
}


template <class T, class D, class L>
std::shared_ptr<MapAdt<std::unique_ptr<T>>> SetsCreator<T, D, L>::createSetForP(D& dataPort) {

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> pDataSetP_ = nullptr;
    pDataSetP_ = std::shared_ptr<MapAdt<std::unique_ptr<T>>>(new MapAdt<std::unique_ptr<T>>());

    size_t parts = meshInfoManager_.getMeshInfoP()->getDomainPartsAmount();

    for (size_t i = 0; i < parts; i++) {
        std::string name = meshInfoManager_.getMeshInfoP()->getPartName(i);

        std::unique_ptr<T> pInnerObj_ = std::unique_ptr<T>(new L(dataPort.createPortP(name)));
        pDataSetP_->addObjectUniquePtr(name, std::move(pInnerObj_));
    }
    return pDataSetP_;
}

}
#endif // SIMPLEFVM_FVMSOLVER_TOOLS_DATASETS_SETSCREATOR_H