include(GenerateExportHeader)

add_library(scad_common src/error/ErrorCode.cpp ../../include/scad_common/error/ErrorCode.hpp
                        ../../include/scad_common/linter/LinterRules.hpp)

add_library(scad_tidy::scad_common ALIAS scad_common)

target_link_libraries(scad_common PRIVATE scad_tidy::scad_tidy_options scad_tidy::scad_tidy_warnings
                                          scad_tidy::scad_utility)
target_link_system_libraries(scad_common PRIVATE Microsoft.GSL::GSL)

target_include_directories(scad_common ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                               $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

set_target_properties(
  scad_common
  PROPERTIES VERSION ${PROJECT_VERSION}
             CXX_VISIBILITY_PRESET hidden
             VISIBILITY_INLINES_HIDDEN yes)
generate_export_header(scad_common EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/scad_common/scad_common_export.h)
if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(scad_common PUBLIC SCAD_COMMON_STATIC_DEFINE)
endif()
