#ifndef SIMPLEFVM_MESHLOADER_LOADERDATASTORES_MESHINFORMATION_H
#define SIMPLEFVM_MESHLOADER_LOADERDATASTORES_MESHINFORMATION_H

#include <cstddef>
#include <string>
#include <vector>


namespace meshloader {

class MeshInformation {
public:
    MeshInformation();

    void addFaceParameters(std::string faceName, size_t cellsAmount);
    size_t getNumberOfParts() const;
    std::string getFaceName(const size_t i) const;
    size_t getFaceCellsAmount(const size_t i) const;

private:
    size_t numberOfParts_ = 0;
    std::vector<std::string> faceName_;
    std::vector<size_t> cellsAmount_;

    bool isAlreadyAdded(std::string faceName);
};

}
#endif // SIMPLEFVM_MESHLOADER_LOADERDATASTORES_MESHINFORMATION_H