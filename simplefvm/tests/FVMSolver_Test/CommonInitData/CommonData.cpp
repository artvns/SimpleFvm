#include "CommonData.h"

namespace commoninitdata {

CommonData::CommonData() {

}

DataDefaultIter1& CommonData::getCommonDataDefaultIter1() {
    return dataDefaultIter1_;
}

DataDefaultIter2& CommonData::getCommonDataDefaultIter2() {
    return dataDefaultIter2_;
}

}