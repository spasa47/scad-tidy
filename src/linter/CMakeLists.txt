include(GenerateExportHeader)

add_library(
        scad_linter
        src/ScadLinter.cpp
)

add_library(
        scad_tidy::scad_linter
        ALIAS
        scad_linter
)

target_link_libraries(
        scad_linter
        PRIVATE
        scad_tidy::scad_tidy_options
        scad_tidy::scad_tidy_warnings
        scad_tidy::scad_tidy_grammar
)
target_link_system_libraries(
        scad_linter
        PRIVATE
        antlr4_static
        Microsoft.GSL::GSL
)
target_include_system_directories(scad_linter
        PRIVATE
        "${antlr4_SOURCE_DIR}/runtime/Cpp/runtime/src"
        ${ANTLR_OpenScadLexer_OUTPUT_DIR}
        ${ANTLR_OpenScadParser_OUTPUT_DIR}
)
target_include_directories(
        scad_linter
        ${WARNING_GUARD}
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
)

set_target_properties(
        scad_linter
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN yes
)
generate_export_header(
        scad_linter
        EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/scad_linter/scad_linter_export.h
)
if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(scad_linter PUBLIC SCAD_LINTER_STATIC_DEFINE)
endif()


