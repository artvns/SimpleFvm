#include <gtest/gtest.h>
#include <memory>

#include "FVMSolver/CoeffsPartsVelocity/RhsVelocity/RhsVPort.h"
#include "FVMSolver/CoeffsPartsVelocity/RhsVelocity/RhsV.h"

#include "../../CommonInitData/CommonData.h"
#include "InitialDataDefaultIter2.h"
#include "ExpectedResultDefaultIter2.h"


namespace rhs_v {

class RhsV_DefaultIter2_GetCorrectRes : public ::testing::Test {
private:
    using uPtrCommonData = std::unique_ptr<commoninitdata::CommonData>;
    using uPtrDataPort = std::unique_ptr<fvmsolver::RhsVPort>;
    using uPtrTestedBlock = std::unique_ptr<fvmsolver::RhsV>;
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

        pDataPort_ = uPtrDataPort(
            new RhsVPort(
                pInitialData_->getFieldsMask(),
                pInitialData_->getMeshParametersMask(),
                pInitialData_->getCellNumsGlobalMask(),
                pInitialData_->getAdjCellGlobalNumsVMask()
            )
        );

        pTestedBlock_ = uPtrTestedBlock(
            new RhsV(std::move(pDataPort_)));
	}

	void TearDown() {

	}

    uPtrCommonData spCommonData_ = nullptr;
    uPtrInitialData pInitialData_ = nullptr;
    uPtrExpectedResult pExpactedRes_ = nullptr;
    uPtrDataPort pDataPort_ = nullptr;
    uPtrTestedBlock pTestedBlock_ = nullptr;
};


TEST_F(RhsV_DefaultIter2_GetCorrectRes, test_1) {
    size_t cells_ = 20;

    for (size_t i = 0; i < cells_; i++) {
        pTestedBlock_->calculate(
            i, pInitialData_->getSc(i), pInitialData_->get_ap(i));

        ASSERT_NEAR (pTestedBlock_->getRhsValue(),  
                        pExpactedRes_->getRhsValue(i), 1.0e-09);
    }
}

}