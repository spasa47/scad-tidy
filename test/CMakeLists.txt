cmake_minimum_required(VERSION 3.15...3.23)

project(
  CmakeConfigPackageTests
  LANGUAGES CXX
  VERSION "${PROJECT_VERSION}")

# ---- Test as standalone project the exported config package ----

if(PROJECT_IS_TOP_LEVEL OR TEST_INSTALLED_VERSION)
  enable_testing()

  find_package(scad_tidy CONFIG REQUIRED) # for cli, project_options, ...

  if(NOT TARGET scad_tidy_options)
    message(FATAL_ERROR "Required config package not found!")
    return() # be strictly paranoid for Template Janitor github action! CK
  endif()
endif()

# Provide a simple smoke test to make sure that the CLI works and can display a --help message
add_test(NAME cli.has_help_short COMMAND scad_tidy_cli -h)
add_test(NAME cli.has_help_full COMMAND scad_tidy_cli --help)

# Provide a test to verify that the version being reported from the application
# matches the version given to CMake. This will be important once you package
# your program. Real world shows that this is the kind of simple mistake that is easy
# to make, but also easy to test for.s
add_test(NAME cli.version_matches COMMAND scad_tidy_cli --version)
set_tests_properties(cli.version_matches PROPERTIES PASS_REGULAR_EXPRESSION
                                                    "${PROJECT_VERSION};^.+$;[0-9]+\.[0-9]+\.[0-9]+")

#add_subdirectory(grammar)
