#include <gtest/gtest.h>

#include "FVMSolver/CoeffsPartsVelocity/DifferencingScheme/HybridDifferencingScheme.h"


TEST(HybridDifferencingScheme_test, a_w__a_s_Test) {
    using namespace fvmsolver;
    
    HybridDifferencingScheme hds;

    ASSERT_DOUBLE_EQ (hds.a_w(-0.5, -1.5),  0.0);
    ASSERT_DOUBLE_EQ (hds.a_w(-0.5, 1.5),   1.5);
    ASSERT_DOUBLE_EQ (hds.a_w(0.5, -1.5),   0.0);
    ASSERT_DOUBLE_EQ (hds.a_w(0.5, 0.0),    0.5);
    ASSERT_DOUBLE_EQ (hds.a_w(-0.5, 0.0),   0.0);

    ASSERT_DOUBLE_EQ (hds.a_s(-0.5, -1.5),  0.0);
    ASSERT_DOUBLE_EQ (hds.a_s(-0.5, 1.5),   1.5);
    ASSERT_DOUBLE_EQ (hds.a_s(0.5, -1.5),   0.0);
    ASSERT_DOUBLE_EQ (hds.a_s(0.5, 0.0),    0.5);
    ASSERT_DOUBLE_EQ (hds.a_s(-0.5, 0.0),   0.0);
}

TEST(HybridDifferencingScheme_test, a_e__a_n_Test) {
    using namespace fvmsolver;
    
    HybridDifferencingScheme hds;

    ASSERT_DOUBLE_EQ (hds.a_e(-0.5, -1.5),  1.5);
    ASSERT_DOUBLE_EQ (hds.a_e(-0.5, 1.5),   0.0);
    ASSERT_DOUBLE_EQ (hds.a_e(0.5, -1.5),   1.5);
    ASSERT_DOUBLE_EQ (hds.a_e(0.5, 0.0),    0.5);
    ASSERT_DOUBLE_EQ (hds.a_e(-0.5, 0.0),   0.0);

    ASSERT_DOUBLE_EQ (hds.a_n(-0.5, -1.5),  1.5);
    ASSERT_DOUBLE_EQ (hds.a_n(-0.5, 1.5),   0.0);
    ASSERT_DOUBLE_EQ (hds.a_n(0.5, -1.5),   1.5);
    ASSERT_DOUBLE_EQ (hds.a_n(0.5, 0.0),    0.5);
    ASSERT_DOUBLE_EQ (hds.a_n(-0.5, 0.0),   0.0);
}