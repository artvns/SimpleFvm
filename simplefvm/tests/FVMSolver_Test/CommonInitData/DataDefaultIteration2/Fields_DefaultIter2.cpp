#include "Fields_DefaultIter2.h"

namespace commoninitdata {

Fields_DefaultIter2::Fields_DefaultIter2() :
                            fieldsMask_(fields_) {
}


fvmsolver::SolverFieldsMask& Fields_DefaultIter2::getFieldsMask() {
    return fieldsMask_;
}


void Fields_DefaultIter2::createFields() {
    fields_.createArrays(cells_u_, cells_v_, cells_p_);
    createU();
    createV();
    createP();
}


void Fields_DefaultIter2::createU() {
    fields_.get_u().setValue(0  ,             0.0 );
    fields_.get_u().setValue(1  ,     0.000255249 );
    fields_.get_u().setValue(2  ,     0.000290833 );
    fields_.get_u().setValue(3  ,     0.000290833 );
    fields_.get_u().setValue(4  ,     0.000255249 );
    fields_.get_u().setValue(5  ,             0.0 );
    fields_.get_u().setValue(6  ,      3.7333e-06 );
    fields_.get_u().setValue(7  ,     6.78341e-07 );
    fields_.get_u().setValue(8  ,     6.78341e-07 );
    fields_.get_u().setValue(9  ,      3.7333e-06 );
    fields_.get_u().setValue(10  ,            0.0 );
    fields_.get_u().setValue(11  ,   -2.28398e-05 );
    fields_.get_u().setValue(12  ,   -4.14567e-05 );
    fields_.get_u().setValue(13  ,   -4.14567e-05 );
    fields_.get_u().setValue(14  ,   -2.28398e-05 );
    fields_.get_u().setValue(15  ,            0.0 );
    fields_.get_u().setValue(16  ,   -2.19277e-05 );
    fields_.get_u().setValue(17  ,   -3.91413e-05 );
    fields_.get_u().setValue(18  ,   -3.91413e-05 );
    fields_.get_u().setValue(19  ,   -2.19277e-05 );
    fields_.get_u().setValue(20  ,            0.0 );
    fields_.get_u().setValue(21  ,    -1.6745e-05 );
    fields_.get_u().setValue(22  ,   -3.03716e-05 );
    fields_.get_u().setValue(23  ,   -3.03716e-05 );
    fields_.get_u().setValue(24  ,    -1.6745e-05 );
    fields_.get_u().setValue(25  ,            0.0 );
    fields_.get_u().setValue(26  ,            0.0 );
    fields_.get_u().setValue(27  ,            0.0 );
    fields_.get_u().setValue(28  ,            0.0 );
    fields_.get_u().setValue(29  ,            0.0 );
    fields_.get_u().setValue(30  ,            0.0 );
    fields_.get_u().setValue(31  ,            0.0 );
    fields_.get_u().setValue(32  ,            0.0 );
    fields_.get_u().setValue(33  ,            0.0 );
    fields_.get_u().setValue(34  ,            0.0 );
    fields_.get_u().setValue(35  ,            0.0 );
    fields_.get_u().setValue(36  ,            0.0 );
    fields_.get_u().setValue(37  ,            0.0 );
    fields_.get_u().setValue(38  ,            0.0 );
    fields_.get_u().setValue(39  ,            0.0 );
    fields_.get_u().setValue(40  ,            0.0 );
    fields_.get_u().setValue(41  ,            0.0 );
    fields_.get_u().setValue(42  ,            0.0 );
    fields_.get_u().setValue(43  ,            0.0 );
    fields_.get_u().setValue(44  ,            0.0 );
}


void Fields_DefaultIter2::createV() {
    fields_.get_v().setValue(0  ,     0.000120583 );
    fields_.get_v().setValue(1  ,     4.43891e-05 );
    fields_.get_v().setValue(2  ,    -1.91885e-21 );
    fields_.get_v().setValue(3  ,    -4.43891e-05 );
    fields_.get_v().setValue(4  ,    -0.000120583 );
    fields_.get_v().setValue(5  ,     8.06569e-05 );
    fields_.get_v().setValue(6  ,     4.65132e-05 );
    fields_.get_v().setValue(7  ,    -5.02463e-21 );
    fields_.get_v().setValue(8  ,    -4.65132e-05 );
    fields_.get_v().setValue(9  ,    -8.06569e-05 );
    fields_.get_v().setValue(10  ,    4.38533e-05 );
    fields_.get_v().setValue(11  ,    2.99746e-05 );
    fields_.get_v().setValue(12  ,   -2.47253e-21 );
    fields_.get_v().setValue(13  ,   -2.99746e-05 );
    fields_.get_v().setValue(14  ,   -4.38533e-05 );
    fields_.get_v().setValue(15  ,    1.76249e-05 );
    fields_.get_v().setValue(16  ,     1.3474e-05 );
    fields_.get_v().setValue(17  ,    4.91728e-22 );
    fields_.get_v().setValue(18  ,    -1.3474e-05 );
    fields_.get_v().setValue(19  ,   -1.76249e-05 );
    fields_.get_v().setValue(20  ,            0.0 );
    fields_.get_v().setValue(21  ,            0.0 );
    fields_.get_v().setValue(22  ,            0.0 );
    fields_.get_v().setValue(23  ,            0.0 );
    fields_.get_v().setValue(24  ,            0.0 );
    fields_.get_v().setValue(25  ,            0.0 );
    fields_.get_v().setValue(26  ,            0.0 );
    fields_.get_v().setValue(27  ,            0.0 );
    fields_.get_v().setValue(28  ,            0.0 );
    fields_.get_v().setValue(29  ,            0.0 );
    fields_.get_v().setValue(30  ,            0.0 );
    fields_.get_v().setValue(31  ,            0.0 );
    fields_.get_v().setValue(32  ,            0.0 );
    fields_.get_v().setValue(33  ,            0.0 );
    fields_.get_v().setValue(34  ,            0.0 );
    fields_.get_v().setValue(35  ,            0.0 );
    fields_.get_v().setValue(36  ,            0.0 );
    fields_.get_v().setValue(37  ,            0.0 );
    fields_.get_v().setValue(38  ,            0.0 );
    fields_.get_v().setValue(39  ,            0.0 );
    fields_.get_v().setValue(40  ,            0.0 );
    fields_.get_v().setValue(41  ,            0.0 );
    fields_.get_v().setValue(42  ,            0.0 );
    fields_.get_v().setValue(43  ,            0.0 );
    fields_.get_v().setValue(44  ,            0.0 );
}


void Fields_DefaultIter2::createP() {
    fields_.get_p().setValue(0  ,     -0.00087168 );
    fields_.get_p().setValue(1  ,    -0.000395568 );
    fields_.get_p().setValue(2  ,     1.56653e-20 );
    fields_.get_p().setValue(3  ,     0.000395568 );
    fields_.get_p().setValue(4  ,      0.00087168 );
    fields_.get_p().setValue(5  ,    -0.000575195 );
    fields_.get_p().setValue(6  ,     -0.00031371 );
    fields_.get_p().setValue(7  ,     1.21268e-20 );
    fields_.get_p().setValue(8  ,      0.00031371 );
    fields_.get_p().setValue(9  ,     0.000575195 );
    fields_.get_p().setValue(10  ,   -0.000327298 );
    fields_.get_p().setValue(11  ,   -0.000199345 );
    fields_.get_p().setValue(12  ,   -2.27648e-22 );
    fields_.get_p().setValue(13  ,    0.000199345 );
    fields_.get_p().setValue(14  ,    0.000327298 );
    fields_.get_p().setValue(15  ,   -0.000192517 );
    fields_.get_p().setValue(16  ,   -0.000125644 );
    fields_.get_p().setValue(17  ,   -6.30705e-21 );
    fields_.get_p().setValue(18  ,    0.000125644 );
    fields_.get_p().setValue(19  ,    0.000192517 );
    fields_.get_p().setValue(20  ,   -0.000149181 );
    fields_.get_p().setValue(21  ,   -0.000100797 );
    fields_.get_p().setValue(22  ,   -5.40027e-21 );
    fields_.get_p().setValue(23  ,    0.000100797 );
    fields_.get_p().setValue(24  ,    0.000149181 );
    fields_.get_p().setValue(25  ,            0.0 );
    fields_.get_p().setValue(26  ,            0.0 );
    fields_.get_p().setValue(27  ,            0.0 );
    fields_.get_p().setValue(28  ,            0.0 );
    fields_.get_p().setValue(29  ,            0.0 );
    fields_.get_p().setValue(30  ,            0.0 );
    fields_.get_p().setValue(31  ,            0.0 );
    fields_.get_p().setValue(32  ,            0.0 );
    fields_.get_p().setValue(33  ,            0.0 );
    fields_.get_p().setValue(34  ,            0.0 );
    fields_.get_p().setValue(35  ,            0.0 );
    fields_.get_p().setValue(36  ,            0.0 );
    fields_.get_p().setValue(37  ,            0.0 );
    fields_.get_p().setValue(38  ,            0.0 );
    fields_.get_p().setValue(39  ,            0.0 );
    fields_.get_p().setValue(40  ,            0.0 );
    fields_.get_p().setValue(41  ,            0.0 );
    fields_.get_p().setValue(42  ,            0.0 );
    fields_.get_p().setValue(43  ,            0.0 );
    fields_.get_p().setValue(44  ,            0.0 );
}

}