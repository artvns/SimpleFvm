file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_subdirectory(Diffusion)
add_subdirectory(Flux)
add_subdirectory(SourceTerm)
add_subdirectory(DifferencingScheme)
add_subdirectory(RhsVelocity)

set(COEFFS_PARTS_VELOCITY ${COEFFS_PARTS_VELOCITY}
		${SOURCES}
		${HEADERS}
		${DIFFUSION}
		${FLUX}
		${SOURCE_TERM}
		${DIFFERENCING_SCHEME}
		${RHS_VELOCITY}
PARENT_SCOPE)