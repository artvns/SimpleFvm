#ifndef SIMPLEFVM_MESHLOADER_MESHINFOEXTRACTION_MESHINFOEXTRACTOR_H
#define SIMPLEFVM_MESHLOADER_MESHINFOEXTRACTION_MESHINFOEXTRACTOR_H

#include <cstddef>
#include <string>

#include "MeshLoader/LoaderDataStores/MeshInformation.h"
#include "MeshLoader/LoaderDataStores/NumsSets.h"


namespace meshloader {

class MeshInfoExtractor {
public:
    MeshInfoExtractor();

    void extractInfo(MeshInformation& meshInfo, NumsSets& numsSets);

private:

};

}
#endif // SIMPLEFVM_MESHLOADER_MESHINFOEXTRACTION_MESHINFOEXTRACTOR_H