file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(RHS_VELOCITY ${RHS_VELOCITY}
	${SOURCES}
	${HEADERS}
PARENT_SCOPE)