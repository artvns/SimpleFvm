file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(FIELDS_INTERPOLATION ${FIELDS_INTERPOLATION}
	${SOURCES}
	${HEADERS}
PARENT_SCOPE)