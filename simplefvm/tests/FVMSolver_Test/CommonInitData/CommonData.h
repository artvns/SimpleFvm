#ifndef SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_COMMONDATA_H
#define SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_COMMONDATA_H

#include "DataDefaultIteration1/DataDefaultIter1.h"
#include "DataDefaultIteration2/DataDefaultIter2.h"


namespace commoninitdata {

class CommonData {
public:
    CommonData();

    DataDefaultIter1& getCommonDataDefaultIter1();
    DataDefaultIter2& getCommonDataDefaultIter2();

private:
    DataDefaultIter1 dataDefaultIter1_;
    DataDefaultIter2 dataDefaultIter2_;
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_COMMONINITDATA_COMMONDATA_H