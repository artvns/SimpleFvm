#ifndef SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_ABSTRACTNUMSSETSCREATOR_H
#define SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_ABSTRACTNUMSSETSCREATOR_H

#include <cstddef>
#include <string>
#include <vector>

#include "MeshLoader/LoaderDataStores/NumsSets.h"
#include "MeshLoader/MeshContainer/Mesh.h"


namespace meshloader {

class AbstractNumsSetsCreator {
public:
    AbstractNumsSetsCreator(Mesh& mesh, 
                            NumsSets& numsSetsP, 
                            NumsSets& numsSetsVel);
                            
    virtual~AbstractNumsSetsCreator() = 0;

    void createNamedSets();

protected:
    Mesh& mesh_;
    NumsSets& numsSetsP_;
    NumsSets& numsSetsVel_;

    std::vector<size_t> numsSet_;

    virtual void createInteriorSet(char setName) = 0;
    virtual void createFacesSets(char setName) = 0;

    bool isGhostCellW(size_t globNum);
    bool isGhostCellE(size_t globNum);
    bool isGhostCellN(size_t globNum);
    bool isGhostCellS(size_t globNum);

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_STAGGEREDMESHPART_VELOCITYNUMBERINGSETS_ABSTRACTNUMSSETSCREATOR_H