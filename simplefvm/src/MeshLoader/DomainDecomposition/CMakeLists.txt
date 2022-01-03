file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(PartsCellsNumsExtraction)
add_subdirectory(DomainPartsChecking)


set(DOMAIN_DECOMPOSITION ${DOMAIN_DECOMPOSITION}
	${SOURCES} 
	${HEADERS}
	${PARTS_CELLS_NUMS_EXTRACTION}
	${DOMAIN_PARTS_CHECKING}
PARENT_SCOPE)