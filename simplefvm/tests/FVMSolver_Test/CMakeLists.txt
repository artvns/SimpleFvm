set(BINARY FVMSolverTest)

project(${BINARY})

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")


add_subdirectory(CommonInitData)
add_subdirectory(DifferencingScheme)
add_subdirectory(DiffusionU)
add_subdirectory(DiffusionV)
add_subdirectory(FluxU)
add_subdirectory(FluxV)
add_subdirectory(RhsU)
add_subdirectory(RhsV)
add_subdirectory(CoeffsPress)
add_subdirectory(RhsPress)


set(SOURCES_AND_HEADERS 
		${SOURCES} 
		${HEADERS}
        ${COMMON_INIT_DATA}
        ${DIFFERENCING_SCHEME}
        ${DIFFUSION_U}
        ${DIFFUSION_V}
        ${FLUX_U}
        ${FLUX_V}
        ${RHS_U}
        ${RHS_V}
        ${COEFFS_PRESS}
        ${RHS_PRESS}
)

add_executable(${BINARY} ${SOURCES_AND_HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})


target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PROJECT_ROOT_DIRECTORY}/simplefvm/src
    ${PROJECT_ROOT_DIRECTORY}/simplefvm/tests
)


target_link_libraries(${BINARY} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${BINARY} SimpleFvm)