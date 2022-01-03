#ifndef SIMPLEFVM_DATASTORES_MESHINFORMATIONSTORE_MESHINFOSTORE_H
#define SIMPLEFVM_DATASTORES_MESHINFORMATIONSTORE_MESHINFOSTORE_H

#include <cstddef>
#include <string>
#include <vector>

#include "../Adt/ArrayAdt.cpp"
#include "../Adt/MapAdt.cpp"


namespace datastores {

class MeshInfoStore {
public:
    MeshInfoStore();

    void createArrays(size_t parts);

    ArrayAdt<std::string>& getPartName();
    MapAdt<size_t>& getPartCellsAmount();
    
    std::vector<std::string>& getBcNamesVector();

    size_t getDomainPartsAmount() const;
    void setDomainPartsAmount(size_t partsAmount);

    size_t getAllCellsAmount() const;
    void setAllCellsAmount(size_t allCellsAmount);

private:
    ArrayAdt<std::string> partNames_;
    MapAdt<size_t> partCellsAmount_;

    std::vector<std::string> bcNamesVector_;

    size_t domainPartsAmount_ = 0;
    size_t interiorPartsAmount_ = 0;
    size_t bcPartsAmount_ = 0;
    size_t allCellsAmount_ = 0;
};

}
#endif // SIMPLEFVM_DATASTORES_MESHINFORMATIONSTORE_MESHINFOSTORE_H