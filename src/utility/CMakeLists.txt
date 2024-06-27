include(GenerateExportHeader)

add_library(
        scad_utility
        src/utility.cpp
)

add_library(
        scad_tidy::scad_utility
        ALIAS
        scad_utility
)

target_link_libraries(
        scad_utility
        PRIVATE
        scad_tidy::scad_tidy_options
        scad_tidy::scad_tidy_warnings
)
target_link_system_libraries(
        scad_utility
        PRIVATE
        Microsoft.GSL::GSL
)

target_include_directories(
        scad_utility
        ${WARNING_GUARD}
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
)

set_target_properties(
        scad_utility
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN yes
)
generate_export_header(
        scad_utility
        EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/scad_utility/scad_utility_export.h
)
if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(scad_utility PUBLIC SCAD_UTILITY_STATIC_DEFINE)
endif()


