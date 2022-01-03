project(CustomExceptions)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(CUSTOM_EXCEPTIONS ${CUSTOM_EXCEPTIONS}
        ${SOURCES} 
        ${HEADERS}
PARENT_SCOPE)