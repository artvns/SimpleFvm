file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(PlatformDependentCode)
add_subdirectory(DataStores)
add_subdirectory(FVMSolver)
add_subdirectory(MeshLoader)
add_subdirectory(MathTools)
add_subdirectory(ResultsSaver)
add_subdirectory(CustomExceptions)


set(SOURCES_AND_HEADERS 
        ${SOURCES} 
        ${HEADERS}
        ${PLATFORM_DEPENDENT_CODE}
        ${EIGEN_INCLUDE_DIRS}
        ${FVM_SOLVER}
        ${MESH_LOADER}
        ${DATA_STORES}
        ${MATH_TOOLS}
        ${RESULTS_SAVER}
        ${CUSTOM_EXCEPTIONS}
)


if (BUILD_SHARED_LIB)
    add_library(${PROJECT_NAME} SHARED ${SOURCES_AND_HEADERS})
else (BUILD_SHARED_LIB)
    add_library(${PROJECT_NAME} STATIC ${SOURCES_AND_HEADERS})
endif (BUILD_SHARED_LIB)


target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PROJECT_SOURCE_DIR}/include/simplefvm/public
)


target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)


#Install
include(GNUInstallDirs)


if (MSVC)
    install(
        TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
    install(
        DIRECTORY ${PROJECT_ROOT_DIRECTORY}/simplefvm/include/simplefvm
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}) 

elseif (("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    set(SIMPLEFVMLIB_INSTALL_DIR ${PROJECT_ROOT_DIRECTORY}/build/install)
    install(
        TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION ${SIMPLEFVMLIB_INSTALL_DIR}/bin
        LIBRARY DESTINATION ${SIMPLEFVMLIB_INSTALL_DIR}/lib
        ARCHIVE DESTINATION ${SIMPLEFVMLIB_INSTALL_DIR}/lib)
    install(
        DIRECTORY ${PROJECT_ROOT_DIRECTORY}/simplefvm/include 
        DESTINATION ${SIMPLEFVMLIB_INSTALL_DIR})
endif()