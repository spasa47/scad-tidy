include(GenerateExportHeader)

add_library(scad_formatter src/Formatter.cpp ../../include/scad_formatter/Formatter.hpp)

add_library(scad_tidy::scad_formatter ALIAS scad_formatter)

target_link_libraries(
  scad_formatter
  PRIVATE scad_tidy::scad_tidy_options
          scad_tidy::scad_tidy_warnings
          scad_tidy::scad_tidy_grammar
          scad_tidy::scad_common)
target_link_system_libraries(
  scad_formatter
  PRIVATE
  antlr4_static
  Microsoft.GSL::GSL)
target_include_system_directories(
  scad_formatter
  PRIVATE
  "${antlr4_SOURCE_DIR}/runtime/Cpp/runtime/src"
  ${ANTLR_OpenScadLexer_OUTPUT_DIR}
  ${ANTLR_OpenScadParser_OUTPUT_DIR})
target_include_directories(scad_formatter ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                                  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

set_target_properties(
  scad_formatter
  PROPERTIES VERSION ${PROJECT_VERSION}
             CXX_VISIBILITY_PRESET hidden
             VISIBILITY_INLINES_HIDDEN yes)
generate_export_header(scad_formatter EXPORT_FILE_NAME
                       ${PROJECT_BINARY_DIR}/include/scad_formatter/scad_formatter_export.h)
if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(scad_formatter PUBLIC SCAD_FORMATTER_STATIC_DEFINE)
endif()
