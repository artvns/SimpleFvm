#include "TemplateCreator.h"

namespace meshloader {

TemplateCreator::TemplateCreator(
                BaseMatrix& baseMatrix,
                BaseMatrix& templateMatrixP) : 
                            baseMatrix_(baseMatrix),
                            templateMatrixP_(templateMatrixP) {

}

void TemplateCreator::createTemplate() {
    MeshTemplateP templateP_(baseMatrix_, templateMatrixP_);
    templateP_.createTemplate();
}

}