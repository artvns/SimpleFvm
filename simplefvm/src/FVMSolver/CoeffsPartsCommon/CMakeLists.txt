file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(CellNumbers)
add_subdirectory(CellTypes)
add_subdirectory(DataExchanger)

set(COEFFS_PARTS_COMMON ${COEFFS_PARTS_COMMON}
	${SOURCES}
	${HEADERS}
	${CELL_NUMBERS}
	${CELL_TYPES}
	${DATA_EXCHANGER}
PARENT_SCOPE)