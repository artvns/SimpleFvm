file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(SOURCE_TERM ${SOURCE_TERM}
	${SOURCES}
	${HEADERS}
PARENT_SCOPE)