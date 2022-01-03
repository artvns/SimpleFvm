#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_PRESSUREPACKER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_PRESSUREPACKER_H

#include "AbstractValuePacker.h"


namespace resultssaver {

class PressurePacker : public AbstractValuePacker {
public:
    PressurePacker(const RecievedCellData& recievedData, 
                    const MeshInformation& meshInfo);

    void packSaverCellValues() override;

private:

};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_PRESSUREPACKER_H