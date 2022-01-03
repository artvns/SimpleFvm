file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(SLE ${SLE}
    ${SOURCES}
    ${HEADERS}
PARENT_SCOPE)
