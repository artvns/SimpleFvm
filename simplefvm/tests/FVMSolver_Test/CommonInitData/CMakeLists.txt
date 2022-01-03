file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(DataDefaultIteration1)
add_subdirectory(DataDefaultIteration2)

set(COMMON_INIT_DATA ${COMMON_INIT_DATA}
		${SOURCES} 
		${HEADERS}
		${DATA_DEFAULT_ITERATION_1}
		${DATA_DEFAULT_ITERATION_2}
PARENT_SCOPE)