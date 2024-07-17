cmake_minimum_required(VERSION 3.28)

# Only set the cxx_standard if it is not set by someone else
if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  scad_tidy
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES CXX C)

add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR_EXECUTABLE "${PROJECT_SOURCE_DIR}/thirdparty/antlr-${ANTLR_TAG}-complete.jar") # a local path for antlr.jar
set(ANTLR4_WITH_STATIC_CRT OFF) # using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR_BUILD_SHARED ON) # in my case I built the shared version
set(ANTLR_TAG 4.13.1) # to specify the GitHub tag for the jar too
set(DISABLE_WARNINGS ON) # Antlr gives a few deprecation warnings for me
set(ANTLR_BUILD_CPP_TESTS OFF) # to avoid creating dist folder
if(NOT EXISTS "${ANTLR_EXECUTABLE}")
  file(DOWNLOAD "https://www.antlr.org/download/antlr-${ANTLR_TAG}-complete.jar" "${ANTLR_EXECUTABLE}")
endif()
#set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/thirdparty/antlr4/antlr-4.10.1-complete.jar)
#find_package(ANTLR REQUIRED)

set(CPM_USE_NAMED_CACHE_DIRECTORIES ON)

include(cmake/PreventInSourceBuilds.cmake)
include(ProjectOptions.cmake)

scad_tidy_setup_options()

scad_tidy_global_options()

include(Dependencies.cmake)
scad_tidy_setup_dependencies()

scad_tidy_local_options()

# don't know if this should be set globally from here or not...
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(GIT_SHA
    "Unknown"
    CACHE STRING "SHA this build was generated from")
string(
  SUBSTRING "${GIT_SHA}"
            0
            8
            GIT_SHORT_SHA)

option(scad_tidy_BUILD_TESTS "Build tests" ON)

option(scad_tidy_BUILD_DOCS "Generate documentation" ON)

if(scad_tidy_BUILD_DOCS)
  include(cmake/Doxygen.cmake)
  scad_tidy_enable_doxygen("awesome-sidebar")
endif()

target_compile_features(scad_tidy_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})

add_library(scad_tidy::scad_tidy_options ALIAS scad_tidy_options)
add_library(scad_tidy::scad_tidy_warnings ALIAS scad_tidy_warnings)

# configure files based on CMake configuration options
add_subdirectory(configured_files)

# Adding the src:
add_subdirectory(src)

# Don't even look at tests if we're not top level
if(NOT PROJECT_IS_TOP_LEVEL)
  return()
endif()

# Adding the tests:
set(BUILD_TESTING ${scad_tidy_BUILD_TESTS})
include(CTest)

if(BUILD_TESTING)
  message(AUTHOR_WARNING "Building Tests. Be sure to check out test/constexpr_tests.cpp for constexpr testing")
  list(APPEND CMAKE_MODULE_PATH ${doctest_SOURCE_DIR}/scripts/cmake)
  add_subdirectory(test)
endif()

if(scad_tidy_BUILD_FUZZ_TESTS)
  message(AUTHOR_WARNING "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html")
  if(NOT scad_tidy_ENABLE_ADDRESS_SANITIZER AND NOT scad_tidy_ENABLE_THREAD_SANITIZER)
    message(WARNING "You need asan or tsan enabled for meaningful fuzz testing")
  endif()
  # add_subdirectory(fuzz_test)

endif()

# If MSVC is being used, and ASAN is enabled, we need to set the debugger environment
# so that it behaves well with MSVC's debugger, and we can run the target from visual studio
if(MSVC)
  get_all_installable_targets(all_targets)
  message("all_targets=${all_targets}")
  set_target_properties(${all_targets} PROPERTIES VS_DEBUGGER_ENVIRONMENT "PATH=$(VC_ExecutablePath_x64);%PATH%")
endif()

# set the startup project for the "play" button in MSVC
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT scad_tidy_cli)

if(CMAKE_SKIP_INSTALL_RULES)
  return()
endif()

include(cmake/PackageProject.cmake)

# Add other targets that you want installed here, by default we just package the one executable
# we know we want to ship
scad_tidy_package_project(
  TARGETS
  scad_tidy_cli
  scad_tidy_options
  scad_tidy_warnings)

# Experience shows that explicit package naming can help make it easier to sort
# out potential ABI related issues before they start, while helping you
# track a build to a specific GIT SHA
set(CPACK_PACKAGE_FILE_NAME
    "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}-${GIT_SHORT_SHA}-${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}"
)

include(CPack)
