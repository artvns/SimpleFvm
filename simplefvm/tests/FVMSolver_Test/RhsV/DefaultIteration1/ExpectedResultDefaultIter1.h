#ifndef SIMPLEFVM_FVMSOLVERTEST_RHSV_DEFAULTITERATION1_EXPECTEDRESULTDEFAULTITER1_H
#define SIMPLEFVM_FVMSOLVERTEST_RHSV_DEFAULTITERATION1_EXPECTEDRESULTDEFAULTITER1_H

#include <cstddef>
#include <vector>


namespace rhs_v {

class ExpectedResultDefaultIter1 {
public:
    ExpectedResultDefaultIter1();

    double getRhsValue(size_t step);

private:
    std::vector<double> rhs_;

    void createResVector();
    void addDataRow(size_t step, double rhs);
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_RHSV_DEFAULTITERATION1_EXPECTEDRESULTDEFAULTITER1_H