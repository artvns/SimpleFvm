#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_NUMSSETSCREATORV_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_NUMSSETSCREATORV_H

#include <string>
#include <vector>

#include "AbstractNumsSetsCreator.h"


namespace meshloader {

class NumsSetsCreatorV : public AbstractNumsSetsCreator {
public:
    NumsSetsCreatorV(Mesh& mesh, NumsSets& numsSetsP, NumsSets& numsSetsVel);

protected:
    void createInteriorSet(char setName) override;
    void createFacesSets(char setName) override;

private:
    bool isGhostCellN_N(size_t globNum);
};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_NUMSSETSCREATORV_H