#ifndef SIMPLEFVM_MSOLVERMACROS_H
#define SIMPLEFVM_MSOLVERMACROS_H


#ifndef SFVM_API_

#ifndef SIMPLEFVM_LINKED_AS_SHARED_LIBRARY
#define SIMPLEFVM_LINKED_AS_SHARED_LIBRARY 0
#endif  //SIMPLEFVM_LINKED_AS_SHARED_LIBRARY


#ifdef _MSC_VER
    #if SIMPLEFVM_CREATE_SHARED_LIBRARY
        #define SFVM_API_ __declspec(dllexport)
    #elif SIMPLEFVM_LINKED_AS_SHARED_LIBRARY
        #define SFVM_API_ __declspec(dllimport)
    #endif

#elif __GNUC__ >= 4 || defined(__clang__)
    #define SFVM_API_ __attribute__((visibility ("default")))
#endif  // _MSC_VER

#endif  // SFVM_API_


#ifndef SFVM_API_
    #define SFVM_API_
#endif  // SFVM_API_


#endif  // SIMPLEFVM_MSOLVERMACROS_H