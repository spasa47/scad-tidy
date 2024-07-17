add_executable(
  scad_tidy_cli
  src/main.cpp
  src/constant/cli_string_constants.hpp
  src/cli/MainCLI.cpp
  src/cli/MainCLI.hpp
  src/constant/cli_flags_constants.hpp
  src/cli/command/CommandEnum.hpp)

target_link_libraries(
  scad_tidy_cli
  PRIVATE scad_tidy::scad_tidy_options
          scad_tidy::scad_tidy_warnings
          scad_tidy::scad_tidy_grammar
          scad_tidy::scad_formatter
          scad_tidy::scad_linter
          scad_tidy::scad_utility
          scad_tidy::scad_common)
target_link_system_libraries(
  scad_tidy_cli
  PRIVATE
  antlr4_static
  Microsoft.GSL::GSL
  tabulate::tabulate
  fmt::fmt
  spdlog::spdlog
  argparse::argparse)
target_include_system_directories(
  scad_tidy_cli
  PRIVATE
  "${antlr4_SOURCE_DIR}/runtime/Cpp/runtime/src"
  ${ANTLR_OpenScadLexer_OUTPUT_DIR}
  ${ANTLR_OpenScadParser_OUTPUT_DIR})
target_include_directories(scad_tidy_cli PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")
