#include <gtest/gtest.h>
#include <memory>

#include "FVMSolver/CoeffsPartsVelocity/Flux/VFluxPort.h"
#include "FVMSolver/CoeffsPartsVelocity/Flux/VFlux.h"

#include "../../CommonInitData/CommonData.h"
#include "InitialDataDefaultIter1.h"
#include "ExpectedResultDefaultIter1.h"


namespace flux_v {

class FluxV_DefaultIter1_GetCorrectRes : public ::testing::Test {
private:
    using uPtrCommonData = std::unique_ptr<commoninitdata::CommonData>;
    using uPtrDataPort = std::unique_ptr<fvmsolver::VFluxPort>;
    using uPtrTestedBlock = std::unique_ptr<fvmsolver::VFlux>;
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
            new VFluxPort(
                pInitialData_->getFluidPropertiesMask(),
                pInitialData_->getFieldsMask(),
                pInitialData_->getMeshParametersMask(),
                pInitialData_->getCellNumsGlobalMask(),
                pInitialData_->getAdjCellGlobalNumsVMask()
            )
        );

        pVFlux_ = uPtrTestedBlock(
            new VFlux(std::move(pDataPort_)));
	}

	void TearDown() {

	}

    uPtrCommonData spCommonData_ = nullptr;
    uPtrInitialData pInitialData_ = nullptr;
    uPtrExpectedResult pExpactedRes_ = nullptr;
    uPtrDataPort pDataPort_ = nullptr;
    uPtrTestedBlock pVFlux_ = nullptr;
};


TEST_F(FluxV_DefaultIter1_GetCorrectRes, test_1) {
    size_t cells_ = 6;

    for (size_t i = 0; i < cells_; i++) {
        pVFlux_->calculate(i);
        
        ASSERT_DOUBLE_EQ (pVFlux_->getFw(),  pExpactedRes_->getFw(i));
        ASSERT_DOUBLE_EQ (pVFlux_->getFe(),  pExpactedRes_->getFe(i)); 
        ASSERT_DOUBLE_EQ (pVFlux_->getFn(),  pExpactedRes_->getFn(i)); 
        ASSERT_DOUBLE_EQ (pVFlux_->getFs(),  pExpactedRes_->getFs(i)); 
    }
}

}