file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(CoeffsPressure)
add_subdirectory(RhsPressure)

set(COEFFS_PARTS_PRESSURE ${COEFFS_PARTS_PRESSURE}
		${SOURCES}
		${HEADERS}
		${COEFFS_PRESSURE}
		${RHS_PRESSURE}
PARENT_SCOPE)