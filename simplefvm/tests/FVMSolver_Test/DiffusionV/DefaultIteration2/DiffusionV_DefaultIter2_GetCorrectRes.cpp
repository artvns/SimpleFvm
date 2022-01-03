#include <gtest/gtest.h>
#include <memory>

#include "FVMSolver/CoeffsPartsVelocity/Diffusion/DiffusionPort.h"
#include "FVMSolver/CoeffsPartsVelocity/Diffusion/VDiffusion.h"

#include "../../CommonInitData/CommonData.h"
#include "InitialDataDefaultIter2.h"
#include "ExpectedResultDefaultIter2.h"


namespace diffusion_v {

class DiffusionV_DefaultIter2_GetCorrectRes : public ::testing::Test {
private:
    using uPtrCommonData = std::unique_ptr<commoninitdata::CommonData>;
    using uPtrDataPort = std::unique_ptr<fvmsolver::DiffusionPort>;
    using uPtrTestedBlock = std::unique_ptr<fvmsolver::VDiffusion>;
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
            new DiffusionPort(
                pInitialData_->getFluidPropertiesMask(),
                pInitialData_->getMeshParametersMask(),
                pInitialData_->getCellNumsGlobalMask()
            )
        );
        
        pVDiffusion_ = uPtrTestedBlock(
            new VDiffusion(std::move(pDataPort_)));
	}

	void TearDown() {

	}

    uPtrCommonData spCommonData_ = nullptr;
    uPtrInitialData pInitialData_ = nullptr;
    uPtrExpectedResult pExpactedRes_ = nullptr;
    uPtrDataPort pDataPort_ = nullptr;
    uPtrTestedBlock pVDiffusion_ = nullptr;
};


TEST_F(DiffusionV_DefaultIter2_GetCorrectRes, test_1) {
    size_t cells_ = 20;

    for (size_t i = 0; i < cells_; i++) {
        pVDiffusion_->calculate(i);

        ASSERT_DOUBLE_EQ (pVDiffusion_->getDw(),  pExpactedRes_->getDw(i));
        ASSERT_DOUBLE_EQ (pVDiffusion_->getDe(),  pExpactedRes_->getDe(i)); 
        ASSERT_DOUBLE_EQ (pVDiffusion_->getDn(),  pExpactedRes_->getDn(i)); 
        ASSERT_DOUBLE_EQ (pVDiffusion_->getDs(),  pExpactedRes_->getDs(i)); 
    }
}

}