# -----------------------------------------------------------------------------
# Compile options defining
# -----------------------------------------------------------------------------


# Check compiler version.
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS 4.8.1)
        message(FATAL_ERROR "This compiler ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is not supported. GCC 4.8.1 or newer is required.")
    endif()
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS 3.3)
        message(FATAL_ERROR "This compiler ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is not supported. Clang 3.3 or newer is required.")
    endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    if("${MSVC_VERSION}" VERSION_LESS 1910)
        message(FATAL_ERROR "This compiler ${CMAKE_CXX_COMPILER_ID} ${MSVC_VERSION} is not supported. MSVC 15.0 or newer is required.")
    endif()    
endif()



if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))

    # Configuration-specific compiler settings.
    set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g")
    set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os")
    set(CMAKE_CXX_FLAGS_RELEASE        "-O3")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

    add_compile_options(-Wfatal-errors)
    add_compile_options(-Wno-unused-parameter)
    add_compile_options(-Wall)
    add_compile_options(-Wextra)
    add_compile_options(-Wpedantic)
    add_compile_options(-pedantic-errors)
    add_compile_options(-Wcast-align)
    add_compile_options(-Wcast-qual)
    add_compile_options(-Wenum-compare)
    add_compile_options(-Wnon-virtual-dtor)
    add_compile_options(-Woverloaded-virtual)
    add_compile_options(-Wredundant-decls)
    add_compile_options(-Wctor-dtor-privacy)
    add_compile_options(-Wold-style-cast)
    add_compile_options(-Wfloat-equal)
    add_compile_options(-Wdouble-promotion)
    add_compile_options(-Warray-bounds)
    add_compile_options(-Wdiv-by-zero)
    add_compile_options(-Wsign-promo)

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        add_compile_options(-Wbool-compare)
        add_compile_options(-Wduplicated-cond)
        add_compile_options(-Wlogical-op)
    endif()

elseif(MSVC)

    # Configuration-specific compiler settings.
    set(CMAKE_CXX_FLAGS_DEBUG          "/Od")
    set(CMAKE_CXX_FLAGS_MINSIZEREL     "/O1")
    set(CMAKE_CXX_FLAGS_RELEASE        "/O2")

    add_compile_options(/MP)

else()
    message(WARNING "Your compiler is not tested.")
endif()