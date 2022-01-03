file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(DefaultIteration1)
add_subdirectory(DefaultIteration2)

set(DIFFUSION_V ${DIFFUSION_V}
		${SOURCES} 
		${HEADERS}
		${DEFAULT_ITERATION_1}
		${DEFAULT_ITERATION_2}
PARENT_SCOPE)