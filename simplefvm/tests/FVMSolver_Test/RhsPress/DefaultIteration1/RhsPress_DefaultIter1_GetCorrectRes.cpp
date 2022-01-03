#include <gtest/gtest.h>
#include <memory>

#include "FVMSolver/CoeffsPartsPressure/RhsPressure/RhsPressPort.h"
#include "FVMSolver/CoeffsPartsPressure/RhsPressure/RhsPress.h"

#include "../../CommonInitData/CommonData.h"
#include "InitialDataDefaultIter1.h"
#include "ExpectedResultDefaultIter1.h"


namespace rhs_p {

class RhsPress_DefaultIter1_GetCorrectRes : public ::testing::Test {
private:
    using uPtrCommonData = std::unique_ptr<commoninitdata::CommonData>;
    using uPtrDataPort = std::unique_ptr<fvmsolver::RhsPressPort>;
    using uPtrTestedBlock = std::unique_ptr<fvmsolver::RhsPress>;
    using uPtrInitialData = std::unique_ptr<InitialDataDefaultIter1>;
    using uPtrExpectedResult = std::unique_ptr<ExpectedResultDefaultIter1>;

protected:
    void SetUp() {
        spCommonData_ = uPtrCommonData(new commoninitdata::CommonData());

        pInitialData_ = uPtrInitialData(
            new InitialDataDefaultIter1(
                spCommonData_->getCommonDataDefaultIter1()));
            
        pExpactedRes_ = uPtrExpectedResult(
            new ExpectedResultDefaultIter1());

        pDataPort_ = uPtrDataPort(
            new RhsPressPort(
                pInitialData_->getFluidPropsMask(),
                pInitialData_->getMeshParametersMask(),
                pInitialData_->getCellNumsGlobalMask(),
                pInitialData_->getAdjCellInteriorNumsPMask(),
                pInitialData_->getScalarsStore()
            )
        );

        pTestedBlock_ = uPtrTestedBlock(
            new RhsPress(std::move(pDataPort_)));
	}

	void TearDown() {

	}

    uPtrCommonData spCommonData_ = nullptr;
    uPtrInitialData pInitialData_ = nullptr;
    uPtrExpectedResult pExpactedRes_ = nullptr;
    uPtrDataPort pDataPort_ = nullptr;
    uPtrTestedBlock pTestedBlock_ = nullptr;
};


TEST_F(RhsPress_DefaultIter1_GetCorrectRes, test_1) {
    size_t cells_ = 6;

    for (size_t i = 0; i < cells_; i++) {
        pTestedBlock_->calculate(i);

        ASSERT_NEAR (pTestedBlock_->getRhsValue(),  
                        pExpactedRes_->getRhsValue(i), 1.0e-09);
    }
}

}