#ifndef SIMPLEFVM_MESHLOADER_FILEREADER_IFILEREADER_H
#define SIMPLEFVM_MESHLOADER_FILEREADER_IFILEREADER_H

#include <string>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"


namespace meshloader {

class IFileReader {
public:
    virtual void load(std::string fileName, BaseMatrix& baseMatrix) = 0;

    virtual ~IFileReader() {};
};

}
#endif // SIMPLEFVM_MESHLOADER_FILEREADER_IFILEREADER_H