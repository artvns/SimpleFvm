#include "ConsoleTextColor.h"


void coutText_GREEN(const std::string text) {
	#ifdef _MSC_VER
		int colorId_GREEN_ = 2;
        int colorId_LIGHTGRAY_ = 7;

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, colorId_GREEN_);
        std::cout << text;
        SetConsoleTextAttribute(handle, colorId_LIGHTGRAY_);
    #elif __GNUC__ || __clang__ || __MINGW32__ || __MINGW64__
        std::cout << "\x1b[32m" << text  << "\x1b[0m";
    #endif
}