#include "Fields_DefaultIter1.h"

namespace commoninitdata {

Fields_DefaultIter1::Fields_DefaultIter1() :
                            fieldsMask_(fields_) {

}


fvmsolver::SolverFieldsMask& Fields_DefaultIter1::getFieldsMask() {
    return fieldsMask_;
}


void Fields_DefaultIter1::createFields() {
    fields_.createArrays(cells_u_, cells_v_, cells_p_);
    createU();
    createV();
    createP();
}


void Fields_DefaultIter1::createU() {
    fields_.get_u().setValue(0  ,    0.0 );
    fields_.get_u().setValue(1  ,    0.0 );
    fields_.get_u().setValue(2  ,    0.0 );
    fields_.get_u().setValue(3  ,    0.0 );
    fields_.get_u().setValue(4  ,    0.0 );
    fields_.get_u().setValue(5  ,    0.0 );
    fields_.get_u().setValue(6  ,    0.0 );
    fields_.get_u().setValue(7  ,    0.0 );
    fields_.get_u().setValue(8  ,    0.0 );
    fields_.get_u().setValue(9  ,    0.0 );
    fields_.get_u().setValue(10  ,   0.0 );
    fields_.get_u().setValue(11  ,   0.0 );
    fields_.get_u().setValue(12  ,   0.0 );
    fields_.get_u().setValue(13  ,   0.0 );
    fields_.get_u().setValue(14  ,   0.0 );
    fields_.get_u().setValue(15  ,   0.0 );
    fields_.get_u().setValue(16  ,   0.0 );
    fields_.get_u().setValue(17  ,   0.0 );
    fields_.get_u().setValue(18  ,   0.0 );
    fields_.get_u().setValue(19  ,   0.0 );
    fields_.get_u().setValue(20  ,   0.0 );
    fields_.get_u().setValue(21  ,   0.0 );
    fields_.get_u().setValue(22  ,   0.0 );
    fields_.get_u().setValue(23  ,   0.0 );
    fields_.get_u().setValue(24  ,   0.0 );
    fields_.get_u().setValue(25  ,   0.0 );
    fields_.get_u().setValue(26  ,   0.0 );
    fields_.get_u().setValue(27  ,   0.0 );
    fields_.get_u().setValue(28  ,   0.0 );
    fields_.get_u().setValue(29  ,   0.0 );
    fields_.get_u().setValue(30  ,   0.0 );
    fields_.get_u().setValue(31  ,   0.0 );
    fields_.get_u().setValue(32  ,   0.0 );
    fields_.get_u().setValue(33  ,   0.0 );
    fields_.get_u().setValue(34  ,   0.0 );
    fields_.get_u().setValue(35  ,   0.0 );
    fields_.get_u().setValue(36  ,   0.0 );
    fields_.get_u().setValue(37  ,   0.0 );
    fields_.get_u().setValue(38  ,   0.0 );
    fields_.get_u().setValue(39  ,   0.0 );
    fields_.get_u().setValue(40  ,   0.0 );
    fields_.get_u().setValue(41  ,   0.0 );
    fields_.get_u().setValue(42  ,   0.0 );
    fields_.get_u().setValue(43  ,   0.0 );
    fields_.get_u().setValue(44  ,   0.0 );
}


void Fields_DefaultIter1::createV() {
    fields_.get_v().setValue(0  ,    0.0 );
    fields_.get_v().setValue(1  ,    0.0 );
    fields_.get_v().setValue(2  ,    0.0 );
    fields_.get_v().setValue(3  ,    0.0 );
    fields_.get_v().setValue(4  ,    0.0 );
    fields_.get_v().setValue(5  ,    0.0 );
    fields_.get_v().setValue(6  ,    0.0 );
    fields_.get_v().setValue(7  ,    0.0 );
    fields_.get_v().setValue(8  ,    0.0 );
    fields_.get_v().setValue(9  ,    0.0 );
    fields_.get_v().setValue(10  ,   0.0 );
    fields_.get_v().setValue(11  ,   0.0 );
    fields_.get_v().setValue(12  ,   0.0 );
    fields_.get_v().setValue(13  ,   0.0 );
    fields_.get_v().setValue(14  ,   0.0 );
    fields_.get_v().setValue(15  ,   0.0 );
    fields_.get_v().setValue(16  ,   0.0 );
    fields_.get_v().setValue(17  ,   0.0 );
    fields_.get_v().setValue(18  ,   0.0 );
    fields_.get_v().setValue(19  ,   0.0 );
    fields_.get_v().setValue(20  ,   0.0 );
    fields_.get_v().setValue(21  ,   0.0 );
    fields_.get_v().setValue(22  ,   0.0 );
    fields_.get_v().setValue(23  ,   0.0 );
    fields_.get_v().setValue(24  ,   0.0 );
    fields_.get_v().setValue(25  ,   0.0 );
    fields_.get_v().setValue(26  ,   0.0 );
    fields_.get_v().setValue(27  ,   0.0 );
    fields_.get_v().setValue(28  ,   0.0 );
    fields_.get_v().setValue(29  ,   0.0 );
    fields_.get_v().setValue(30  ,   0.0 );
    fields_.get_v().setValue(31  ,   0.0 );
    fields_.get_v().setValue(32  ,   0.0 );
    fields_.get_v().setValue(33  ,   0.0 );
    fields_.get_v().setValue(34  ,   0.0 );
    fields_.get_v().setValue(35  ,   0.0 );
    fields_.get_v().setValue(36  ,   0.0 );
    fields_.get_v().setValue(37  ,   0.0 );
    fields_.get_v().setValue(38  ,   0.0 );
    fields_.get_v().setValue(39  ,   0.0 );
    fields_.get_v().setValue(40  ,   0.0 );
    fields_.get_v().setValue(41  ,   0.0 );
    fields_.get_v().setValue(42  ,   0.0 );
    fields_.get_v().setValue(43  ,   0.0 );
    fields_.get_v().setValue(44  ,   0.0 );
}


void Fields_DefaultIter1::createP() {
    fields_.get_p().setValue(0  ,    0.0 );
    fields_.get_p().setValue(1  ,    0.0 );
    fields_.get_p().setValue(2  ,    0.0 );
    fields_.get_p().setValue(3  ,    0.0 );
    fields_.get_p().setValue(4  ,    0.0 );
    fields_.get_p().setValue(5  ,    0.0 );
    fields_.get_p().setValue(6  ,    0.0 );
    fields_.get_p().setValue(7  ,    0.0 );
    fields_.get_p().setValue(8  ,    0.0 );
    fields_.get_p().setValue(9  ,    0.0 );
    fields_.get_p().setValue(10  ,   0.0 );
    fields_.get_p().setValue(11  ,   0.0 );
    fields_.get_p().setValue(12  ,   0.0 );
    fields_.get_p().setValue(13  ,   0.0 );
    fields_.get_p().setValue(14  ,   0.0 );
    fields_.get_p().setValue(15  ,   0.0 );
    fields_.get_p().setValue(16  ,   0.0 );
    fields_.get_p().setValue(17  ,   0.0 );
    fields_.get_p().setValue(18  ,   0.0 );
    fields_.get_p().setValue(19  ,   0.0 );
    fields_.get_p().setValue(20  ,   0.0 );
    fields_.get_p().setValue(21  ,   0.0 );
    fields_.get_p().setValue(22  ,   0.0 );
    fields_.get_p().setValue(23  ,   0.0 );
    fields_.get_p().setValue(24  ,   0.0 );
    fields_.get_p().setValue(25  ,   0.0 );
    fields_.get_p().setValue(26  ,   0.0 );
    fields_.get_p().setValue(27  ,   0.0 );
    fields_.get_p().setValue(28  ,   0.0 );
    fields_.get_p().setValue(29  ,   0.0 );
    fields_.get_p().setValue(30  ,   0.0 );
    fields_.get_p().setValue(31  ,   0.0 );
    fields_.get_p().setValue(32  ,   0.0 );
    fields_.get_p().setValue(33  ,   0.0 );
    fields_.get_p().setValue(34  ,   0.0 );
    fields_.get_p().setValue(35  ,   0.0 );
    fields_.get_p().setValue(36  ,   0.0 );
    fields_.get_p().setValue(37  ,   0.0 );
    fields_.get_p().setValue(38  ,   0.0 );
    fields_.get_p().setValue(39  ,   0.0 );
    fields_.get_p().setValue(40  ,   0.0 );
    fields_.get_p().setValue(41  ,   0.0 );
    fields_.get_p().setValue(42  ,   0.0 );
    fields_.get_p().setValue(43  ,   0.0 );
    fields_.get_p().setValue(44  ,   0.0 );
}

}