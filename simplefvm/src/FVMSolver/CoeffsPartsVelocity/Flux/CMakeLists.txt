file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(FLUX ${FLUX}
	${SOURCES}
	${HEADERS}
PARENT_SCOPE)