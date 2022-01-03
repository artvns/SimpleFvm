#ifndef SIMPLEFVM_FVMSOLVER_TOOLS_DATASETS_SETSCREATORINTERPOLATOR_H
#define SIMPLEFVM_FVMSOLVER_TOOLS_DATASETS_SETSCREATORINTERPOLATOR_H

#include <cstddef>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/DataReciever/DataManager.h"
#include "FVMSolver/MeshInformation/MeshInfoManager.h"


namespace fvmsolver {

template <class T, class D, class L>
class SetsCreatorInterpolator {
public:
    SetsCreatorInterpolator(MeshInfoManager& meshInfoManager) : 
                                meshInfoManager_(meshInfoManager) {}

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> createSetForU(D& dataPort);
    std::shared_ptr<MapAdt<std::unique_ptr<T>>> createSetForV(D& dataPort);

private:
    MeshInfoManager& meshInfoManager_;
};


template <class T, class D, class L>
std::shared_ptr<MapAdt<std::unique_ptr<T>>> SetsCreatorInterpolator<T, D, L>::createSetForU(D& dataPort) {

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> pDataSetU_ = nullptr;
    pDataSetU_ = std::shared_ptr<MapAdt<std::unique_ptr<T>>>(new MapAdt<std::unique_ptr<T>>());

    size_t parts = meshInfoManager_.getMeshInfoP()->getDomainPartsAmount();

    for (size_t i = 0; i < parts; i++) {
        std::string name = meshInfoManager_.getMeshInfoP()->getPartName(i);

        std::unique_ptr<T> pInnerObj_ = std::unique_ptr<T>(new L(dataPort.createPortU(name)));
        pDataSetU_->addObjectUniquePtr(name, std::move(pInnerObj_));
    }
    return pDataSetU_;
}



template <class T, class D, class L>
std::shared_ptr<MapAdt<std::unique_ptr<T>>> SetsCreatorInterpolator<T, D, L>::createSetForV(D& dataPort) {

    std::shared_ptr<MapAdt<std::unique_ptr<T>>> pDataSetV_ = nullptr;
    pDataSetV_ = std::shared_ptr<MapAdt<std::unique_ptr<T>>>(new MapAdt<std::unique_ptr<T>>());

    size_t parts = meshInfoManager_.getMeshInfoP()->getDomainPartsAmount();

    for (size_t i = 0; i < parts; i++) {
        std::string name = meshInfoManager_.getMeshInfoP()->getPartName(i);

        std::unique_ptr<T> pInnerObj_ = std::unique_ptr<T>(new L(dataPort.createPortV(name)));
        pDataSetV_->addObjectUniquePtr(name, std::move(pInnerObj_));
    }
    return pDataSetV_;    
}

}
#endif // SIMPLEFVM_FVMSOLVER_TOOLS_DATASETS_SETSCREATORINTERPOLATOR_H