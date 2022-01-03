#ifndef SIMPLEFVM_FVMSOLVERTEST_COEFFSPRESS_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H
#define SIMPLEFVM_FVMSOLVERTEST_COEFFSPRESS_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H

#include <vector>


namespace coeffs_p {

class ExpectedResultDefaultIter2 {
public:
    ExpectedResultDefaultIter2();

    double getAw(size_t step);
    double getAe(size_t step);
    double getAn(size_t step);
    double getAs(size_t step);

private:
    std::vector<double> Aw_;
    std::vector<double> Ae_;
    std::vector<double> An_;
    std::vector<double> As_;

    void createResVector();
    void addDataRow(size_t step, double Aw_, double Ae_, double An_, double As_);
};

}
#endif // SIMPLEFVM_FVMSOLVERTEST_COEFFSPRESS_DEFAULTITERATION2_EXPECTEDRESULTDEFAULTITER2_H