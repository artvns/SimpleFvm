#include <gtest/gtest.h>
#include <memory>

#include "FVMSolver/CoeffsPartsPressure/CoeffsPressure/CoeffsPressPort.h"
#include "FVMSolver/CoeffsPartsPressure/CoeffsPressure/CoeffsPress.h"

#include "../../CommonInitData/CommonData.h"
#include "InitialDataDefaultIter2.h"
#include "ExpectedResultDefaultIter2.h"


namespace coeffs_p {

class CoeffsPress_DefaultIter2_GetCorrectRes : public ::testing::Test {
private:
    using uPtrCommonData = std::unique_ptr<commoninitdata::CommonData>;
    using uPtrDataPort = std::unique_ptr<fvmsolver::CoeffsPressPort>;
    using uPtrTestedBlock = std::unique_ptr<fvmsolver::CoeffsPress>;
    using uPtrInitialData = std::unique_ptr<InitialDataDefaultIter2>;
    using uPtrExpectedResult = std::unique_ptr<ExpectedResultDefaultIter2>;

protected:
    void SetUp() {
        spCommonData_ = uPtrCommonData(new commoninitdata::CommonData());

        pInitialData_ = uPtrInitialData(
            new InitialDataDefaultIter2(
                spCommonData_->getCommonDataDefaultIter2()));
            
        pExpactedRes_ = uPtrExpectedResult(
            new ExpectedResultDefaultIter2());

        pCoeffsPressPort_ = uPtrDataPort(
            new CoeffsPressPort(
                pInitialData_->getFluidPropertiesMask(),
                pInitialData_->getMeshParametersMask(),
                pInitialData_->getCellNumsGlobalMask(),
                pInitialData_->getAdjCellInteriorNumsPMask(),
                pInitialData_->getCoeffsCalculatorsStore()
            )
        );
        
        pCoeffsPress_ = uPtrTestedBlock(
            new CoeffsPress(std::move(pCoeffsPressPort_)));
	}

	void TearDown() {

	}

    uPtrCommonData spCommonData_ = nullptr;
    uPtrInitialData pInitialData_ = nullptr;
    uPtrExpectedResult pExpactedRes_ = nullptr;
    uPtrDataPort pCoeffsPressPort_ = nullptr;
    uPtrTestedBlock pCoeffsPress_ = nullptr;
};


TEST_F(CoeffsPress_DefaultIter2_GetCorrectRes, test_2_compare_with_accuracy) {
    size_t cells_ = 6;

    for (size_t i = 0; i < cells_; i++) {
        pCoeffsPress_->calculate(i);
        ASSERT_NEAR (pCoeffsPress_->getAw(),  pExpactedRes_->getAw(i), 1.0e-06);
        ASSERT_NEAR (pCoeffsPress_->getAe(),  pExpactedRes_->getAe(i), 1.0e-06);
        ASSERT_NEAR (pCoeffsPress_->getAn(),  pExpactedRes_->getAn(i), 1.0e-06);
        ASSERT_NEAR (pCoeffsPress_->getAs(),  pExpactedRes_->getAs(i), 1.0e-06);
    }
}

}