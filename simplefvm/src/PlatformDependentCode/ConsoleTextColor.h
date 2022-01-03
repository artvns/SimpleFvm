#ifndef SIMPLEFVM_PLATFORMDEPENDENTCODE_CONSOLETEXTCOLOR_H
#define SIMPLEFVM_PLATFORMDEPENDENTCODE_CONSOLETEXTCOLOR_H

#include <string>
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif


void coutText_GREEN(const std::string text);


#endif // SIMPLEFVM_PLATFORMDEPENDENTCODE_CONSOLETEXTCOLOR_H