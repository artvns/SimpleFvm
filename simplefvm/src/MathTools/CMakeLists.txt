project(MathTools)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(SleSolvers)

set(MATH_TOOLS ${MATH_TOOLS}
		${SOURCES} 
		${HEADERS}
		${SLE_SOLVERS}
PARENT_SCOPE)
