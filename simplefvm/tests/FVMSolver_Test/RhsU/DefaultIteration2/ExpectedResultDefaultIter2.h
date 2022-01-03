#ifndef SIMPLEFVM_FVMSOLVERTEST_RHSU_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_RHSU_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H

#include <cstddef>
#include <vector>


namespace rhs_u {

class ExpectedResultDefaultIter2 {
public:
    ExpectedResultDefaultIter2();

    double getRhsValue(size_t step);

private:
    std::vector<double> rhs_;

    void createResVector();
    void addDataRow(size_t step, double rhs);
};

}

#endif // SIMPLEFVM_FVMSOLVERTEST_RHSU_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H