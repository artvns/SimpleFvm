#ifndef SIMPLEFVM_MESHLOADER_MESHTEMPLATES_MESHTEMPLATEP_H
#define SIMPLEFVM_MESHLOADER_MESHTEMPLATES_MESHTEMPLATEP_H

#include <cstddef>
#include <string>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"


namespace meshloader {

class MeshTemplateP {
public:
    MeshTemplateP(BaseMatrix& baseMatrix, BaseMatrix& templateMatrixP);

    void createTemplate();

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;

    size_t maxLines_  = 0;
    size_t maxColumns_ = 0;

    void createMatrix();
    void initializeWithZeroes();
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHTEMPLATES_MESHTEMPLATEP_H