#include "AbstractDataExchanger.h"

namespace fvmsolver {

AbstractDataExchanger::AbstractDataExchanger() {

}

AbstractDataExchanger::~AbstractDataExchanger() {
    
}

double AbstractDataExchanger::get_dw() {
    return dw_var_;
}
double AbstractDataExchanger::get_de() {
    return de_var_; 
}
double AbstractDataExchanger::get_dn() {
    return dn_var_;   
}
double AbstractDataExchanger::get_ds() {
    return ds_var_;    
}

}