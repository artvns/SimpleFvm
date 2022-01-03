#ifndef SIMPLEFVM_MESHLOADER_MESHTEMPLATES_TEMPLATECREATOR_H
#define SIMPLEFVM_MESHLOADER_MESHTEMPLATES_TEMPLATECREATOR_H

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"

#include "MeshTemplateP.h"


namespace meshloader {

class TemplateCreator {
public:
    TemplateCreator(BaseMatrix&  baseMatrix_, BaseMatrix& templateMatrixP);

    void createTemplate();

private:
    BaseMatrix& baseMatrix_;
    BaseMatrix& templateMatrixP_;
};

}
#endif // SIMPLEFVM_MESHLOADER_MESHTEMPLATES_TEMPLATECREATOR_H