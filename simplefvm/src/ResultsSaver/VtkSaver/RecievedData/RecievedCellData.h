#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_RECIEVEDCELLDATA_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_RECIEVEDCELLDATA_H

#include <cstddef>

#include "DataStores/FieldsStores/FieldsStore.h"


namespace resultssaver {

class RecievedCellData {
public:
    RecievedCellData(datastores::FieldsStore& fields);

    double getPressValue(size_t cellNum) const;
    double getUVelValue(size_t cellNum) const;
    double getVVelValue(size_t cellNum) const;

private:
    datastores::FieldsStore& fields_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_RECIEVEDDATA_RECIEVEDCELLDATA_H