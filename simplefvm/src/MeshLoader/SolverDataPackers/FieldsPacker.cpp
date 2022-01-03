#include "FieldsPacker.h"

namespace meshloader {

FieldsPacker::FieldsPacker(DataStoreMasks& dataContainer, 
                           Mesh& mesh) :
                                    dataContainer_(dataContainer),
                                    mesh_(mesh) {

}

void FieldsPacker::packFields() {
    size_t allCellsAmount_ = mesh_.getCellsAmount();

    createStore(allCellsAmount_);

    for (size_t i = 0; i < allCellsAmount_; i++) {
        size_t num_ = mesh_.getCellByIndex(i)->getCellGlobalNum();
        packValueP(i, num_);
        packValueU(i, num_);
        packValueV(i, num_);
    }
}

void FieldsPacker::createStore(size_t storeSize) {
    dataContainer_.getFieldsMask().createStore(
        storeSize, 
        storeSize, 
        storeSize
    );
}

void FieldsPacker::packValueP(size_t idx, size_t cellNum) {
    dataContainer_.getFieldsMask().setP(
        --cellNum, 
        mesh_.getCellByIndex(idx)->getCellP().getValue()
    );
}

void FieldsPacker::packValueU(size_t idx, size_t cellNum) {
    dataContainer_.getFieldsMask().setU(
        --cellNum, 
        mesh_.getCellByIndex(idx)->getCellU().getValue()
    );
}

void FieldsPacker::packValueV(size_t idx, size_t cellNum) {
    dataContainer_.getFieldsMask().setV(
        --cellNum, 
        mesh_.getCellByIndex(idx)->getCellV().getValue()
    );
}

}