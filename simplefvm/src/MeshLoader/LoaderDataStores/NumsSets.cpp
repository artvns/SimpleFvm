#include "NumsSets.h"

namespace meshloader {

NumsSets::NumsSets() {

}

void NumsSets::addNumsSet(char partName, std::vector<size_t> numsSet) {
    partNames_.push_back(partName);
    mapNums_.insert(std::make_pair(partName, numsSet));
    setsAmount_++;
}

std::vector<size_t>& NumsSets::getNumsSet(char partName) {
    return mapNums_[partName];
}

std::vector<char>& NumsSets::getPartNamesSet() {
    return partNames_;
}

size_t NumsSets::getSetsAmount() {
    return setsAmount_;
}

size_t NumsSets::getSetNumsAmount(char partName) {
    return mapNums_[partName].size();
}

}