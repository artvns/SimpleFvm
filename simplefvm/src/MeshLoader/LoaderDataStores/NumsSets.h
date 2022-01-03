#ifndef SIMPLEFVM_MESHLOADER_LOADERDATASTORES_NUMSSETS_H
#define SIMPLEFVM_MESHLOADER_LOADERDATASTORES_NUMSSETS_H

#include <cstddef>
#include <string>
#include <vector>
#include <map>


namespace meshloader {

class NumsSets {
public:
    NumsSets();

    void addNumsSet(char partName, std::vector<size_t> numsSet);
    std::vector<size_t>& getNumsSet(char partName);
    std::vector<char>& getPartNamesSet();
    size_t getSetsAmount();
    size_t getSetNumsAmount(char partName);

private:
    size_t setsAmount_ = 0;
    std::vector<char> partNames_;
    std::map<char, std::vector<size_t>> mapNums_;
};

}
#endif // SIMPLEFVM_MESHLOADER_LOADERDATASTORES_NUMSSETS_H