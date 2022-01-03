file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(CellNumsPacker)

set(SOLVER_DATA_PACKERS ${SOLVER_DATA_PACKERS}
		${SOURCES} 
		${HEADERS}
		${CELL_NUMS_PACKER}
PARENT_SCOPE)