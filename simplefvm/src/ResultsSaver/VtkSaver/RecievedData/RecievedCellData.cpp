#include "RecievedCellData.h"

namespace resultssaver {

RecievedCellData::RecievedCellData(
        datastores::FieldsStore& fields) : fields_(fields) {

}

double RecievedCellData::getPressValue(size_t cellNum) const {
    return fields_.get_p().getValue(cellNum);
}

double RecievedCellData::getUVelValue(size_t cellNum) const {
    return fields_.get_uCellCentered().getValue(cellNum);
}

double RecievedCellData::getVVelValue(size_t cellNum) const {
    return fields_.get_vCellCentered().getValue(cellNum);
}

}