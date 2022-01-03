set(BINARY IntegrationTests)

project(${BINARY})

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

include_directories(include)

link_directories(build/lib)


add_subdirectory(FileReader)


set(SOURCES_AND_HEADERS 
		${SOURCES} 
		${HEADERS}
		${FILE_READER}
)

link_directories(${PROJECT_ROOT_DIRECTORY}/build/lib)


add_executable(${BINARY} ${SOURCES_AND_HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})


target_include_directories(${PROJECT_NAME} PRIVATE
	${PROJECT_ROOT_DIRECTORY}/simplefvm/include
)


target_link_libraries(${BINARY} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${BINARY} SimpleFvm)


set(PROJECT_OUT_FOLDER ${BINARY}folder)

set_target_properties(${BINARY}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_OUT_FOLDER}
)


add_custom_command(
	TARGET ${BINARY}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/data
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_OUT_FOLDER}/data
	DEPENDS ${BINARY}
)


add_custom_command(
	TARGET ${BINARY}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/target_data
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_OUT_FOLDER}/target_data
	DEPENDS ${BINARY}
)