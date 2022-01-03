#include <gtest/gtest.h>
#include <memory>

#include "FVMSolver/CoeffsPartsVelocity/Flux/UFluxPort.h"
#include "FVMSolver/CoeffsPartsVelocity/Flux/UFlux.h"

#include "../../CommonInitData/CommonData.h"
#include "InitialDataDefaultIter2.h"
#include "ExpectedResultDefaultIter2.h"


namespace flux_u {

class FluxU_DefaultIter2_GetCorrectRes : public ::testing::Test {
private:
    using uPtrCommonData = std::unique_ptr<commoninitdata::CommonData>;
    using uPtrDataPort = std::unique_ptr<fvmsolver::UFluxPort>;
    using uPtrTestedBlock = std::unique_ptr<fvmsolver::UFlux>;
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
            new UFluxPort(
                pInitialData_->getFluidPropertiesMask(),
                pInitialData_->getFieldsMask(),
                pInitialData_->getMeshParametersMask(),
                pInitialData_->getCellNumsGlobalMask(),
                pInitialData_->getAdjCellGlobalNumsUMask()
            )
        );

        pUFlux_ = uPtrTestedBlock(
            new UFlux(std::move(pDataPort_)));
	}

	void TearDown() {

	}

    uPtrCommonData spCommonData_ = nullptr;
    uPtrInitialData pInitialData_ = nullptr;
    uPtrExpectedResult pExpactedRes_ = nullptr;
    uPtrDataPort pDataPort_ = nullptr;
    uPtrTestedBlock pUFlux_ = nullptr;
};


TEST_F(FluxU_DefaultIter2_GetCorrectRes, test_1) {
    size_t cells_ = 6;

    for (size_t i = 0; i < cells_; i++) {
        pUFlux_->calculate(i);

        ASSERT_NEAR (pUFlux_->getFw(),  pExpactedRes_->getFw(i), 1.0e-09);
        ASSERT_NEAR (pUFlux_->getFe(),  pExpactedRes_->getFe(i), 1.0e-09); 
        ASSERT_NEAR (pUFlux_->getFn(),  pExpactedRes_->getFn(i), 1.0e-09); 
        ASSERT_NEAR (pUFlux_->getFs(),  pExpactedRes_->getFs(i), 1.0e-09); 
    }
}

}