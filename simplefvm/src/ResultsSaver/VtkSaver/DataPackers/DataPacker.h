#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_DATAPACKER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_DATAPACKER_H

#include <cstddef>

#include <vtkNew.h>
#include <vtkDoubleArray.h>

#include "../RecievedData/DataMasks.h"

#include "PressurePacker.h"
#include "VelocityPacker.h"


namespace resultssaver {

class DataPacker {
public:
    DataPacker(DataMasks& dataMasks);

    void packData();
    vtkNew<vtkDoubleArray>& getPressure();
    vtkNew<vtkDoubleArray>& getVelocity();

private:
    PressurePacker pressurePacker_;
    VelocityPacker velocityPacker_;
};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_DATAPACKER_H