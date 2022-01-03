#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_NUMSSETSCREATORU_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_NUMSSETSCREATORU_H

#include <string>
#include <vector>

#include "AbstractNumsSetsCreator.h"


namespace meshloader {

class NumsSetsCreatorU : public AbstractNumsSetsCreator {
public:
    NumsSetsCreatorU(Mesh& mesh, NumsSets& numsSetsP, NumsSets& numsSetsVel);

protected:
    void createInteriorSet(char setName) override;
    void createFacesSets(char setName) override;

private:
    bool isGhostCellE_E(size_t globNum);
};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_NUMSSETSCREATORU_H