#include "MeshFileReader.h"

namespace meshloader {

MeshFileReader::MeshFileReader(
                IFileReader& fileReader, 
                BaseMatrix& baseMatrix) : 
                            fileReader_(fileReader),
                            baseMatrix_(baseMatrix) {

}

void MeshFileReader::readMeshFile(const std::string fileName) {
    fileReader_.load(fileName, baseMatrix_);
}

}