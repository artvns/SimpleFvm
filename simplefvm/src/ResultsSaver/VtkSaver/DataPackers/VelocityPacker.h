#ifndef SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_VELOCITYPACKER_H
#define SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_VELOCITYPACKER_H

#include "AbstractValuePacker.h"


namespace resultssaver {

class VelocityPacker : public AbstractValuePacker {
public:
    VelocityPacker(const RecievedCellData& recievedData, 
                    const MeshInformation& meshInfo);

    void packSaverCellValues() override;

private:

};

}
#endif // SIMPLEFVM_RESULTSSAVER_VTKSAVER_DATAPACKERS_VELOCITYPACKER_H