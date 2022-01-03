#ifndef SIMPLEFVM_MESHLOADER_FILEREADER_MESHFILEREADER_H
#define SIMPLEFVM_MESHLOADER_FILEREADER_MESHFILEREADER_H

#include <string>

#include "MeshLoader/LoaderDataStores/BaseMatrix.h"

#include "IFileReader.h"


namespace meshloader {

class MeshFileReader {
public:
    MeshFileReader(IFileReader& fileReader, BaseMatrix& baseMatrix);

    void readMeshFile(const std::string fileName);

private:
    IFileReader& fileReader_;
    BaseMatrix& baseMatrix_;
};

}
#endif // SIMPLEFVM_MESHLOADER_FILEREADER_MESHFILEREADER_H