file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(Algorithms)

set(SOLUTION_ALGORITHMS ${SOLUTION_ALGORITHMS}
    ${SOURCES}
	${HEADERS}
	${ALGORITHMS}
PARENT_SCOPE)