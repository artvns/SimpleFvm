#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_ABSTRACTVALUEPACKER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_ABSTRACTVALUEPACKER_H

#include <cstddef>

#include <vtkNew.h>
#include <vtkDoubleArray.h>

#include "../RecievedData/RecievedCellData.h"
#include "../RecievedData/MeshInformation.h"


namespace resultssaver {


class AbstractValuePacker {
public:
    AbstractValuePacker(const RecievedCellData& recievedData, 
                        const MeshInformation& meshInfo);

    virtual ~AbstractValuePacker() = 0;

    virtual void packSaverCellValues() = 0;

    vtkNew<vtkDoubleArray>& getCellValues();

protected:
    size_t cellsAmount_ = 0;
    const RecievedCellData& recievedData_;
    vtkNew<vtkDoubleArray> cellValues_;

private:

};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_ABSTRACTVALUEPACKER_H