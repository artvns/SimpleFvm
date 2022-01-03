# Version info
set (PROJECT_MAJOR_VERSION 1)
set (PROJECT_MINOR_VERSION 0)
set (PROJECT_PATCH_VERSION 0)
set (PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION})


# Project info
set(PACKAGE_NAME            SimpleFvm)
set(PACKAGE_LANGUAGES       C CXX)
set(CMAKE_CXX_STANDARD      11)
set(CMAKE_C_STANDARD        99)
set(CMAKE_BUILD_TYPE        Debug)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

project(${PACKAGE_NAME} 
    VERSION ${PROJECT_VERSION} 
    LANGUAGES ${PACKAGE_LANGUAGES}
)


# Options
option(BUILD_SHARED_LIB "Build shared library." ON)

if (MSVC)
    option(BUILD_TESTING "Build all tests." OFF)
else()
    option(BUILD_TESTING "Build all tests." ON)
endif()


if (BUILD_SHARED_LIB)
    add_definitions(-DSIMPLEFVM_CREATE_SHARED_LIBRARY=1)
else()
    add_definitions(-DSIMPLEFVM_CREATE_SHARED_LIBRARY=0)
endif()


# Path for cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


include(CompilerSettings)


# Libraries
find_package(Eigen3 3.3.7 REQUIRED NO_MODULE)
if (NOT EIGEN3_FOUND)
    message("Skipping project: ${EIGEN3_NOT_FOUND_MESSAGE}")
    return ()
endif()
message (STATUS "EIGEN3_VERSION: ${Eigen3_VERSION}")


find_package(VTK 8.2.0 REQUIRED)
if (NOT VTK_FOUND)
    message("Skipping project: ${VTK_NOT_FOUND_MESSAGE}")
    return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")


find_package(GTest REQUIRED)
if (NOT GTEST_FOUND)
    message("Skipping project: ${GTEST_NOT_FOUND_MESSAGE}")
    return ()
endif()


add_subdirectory(src)


# Testing
if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()