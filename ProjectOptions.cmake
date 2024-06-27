include(cmake/SystemLink.cmake)
include(cmake/LibFuzzer.cmake)
include(CMakeDependentOption)
include(CheckCXXCompilerFlag)


macro(scad_tidy_supports_sanitizers)
  if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND NOT WIN32)
    set(SUPPORTS_UBSAN ON)
  else()
    set(SUPPORTS_UBSAN OFF)
  endif()

  if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND WIN32)
    set(SUPPORTS_ASAN OFF)
  else()
    set(SUPPORTS_ASAN ON)
  endif()
endmacro()

macro(scad_tidy_setup_options)
  option(scad_tidy_ENABLE_HARDENING "Enable hardening" ON)
  option(scad_tidy_ENABLE_COVERAGE "Enable coverage reporting" OFF)
  cmake_dependent_option(
    scad_tidy_ENABLE_GLOBAL_HARDENING
    "Attempt to push hardening options to built dependencies"
    ON
    scad_tidy_ENABLE_HARDENING
    OFF)

  scad_tidy_supports_sanitizers()

  if(NOT PROJECT_IS_TOP_LEVEL OR scad_tidy_PACKAGING_MAINTAINER_MODE)
    option(scad_tidy_ENABLE_IPO "Enable IPO/LTO" OFF)
    option(scad_tidy_WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
    option(scad_tidy_ENABLE_USER_LINKER "Enable user-selected linker" OFF)
    option(scad_tidy_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
    option(scad_tidy_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(scad_tidy_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)
    option(scad_tidy_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(scad_tidy_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(scad_tidy_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(scad_tidy_ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
    option(scad_tidy_ENABLE_CPPCHECK "Enable cpp-check analysis" OFF)
    option(scad_tidy_ENABLE_PCH "Enable precompiled headers" OFF)
    option(scad_tidy_ENABLE_CACHE "Enable ccache" OFF)
  else()
    option(scad_tidy_ENABLE_IPO "Enable IPO/LTO" ON)
    option(scad_tidy_WARNINGS_AS_ERRORS "Treat Warnings As Errors" ON)
    option(scad_tidy_ENABLE_USER_LINKER "Enable user-selected linker" OFF)
    option(scad_tidy_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" ${SUPPORTS_ASAN})
    option(scad_tidy_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(scad_tidy_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" ${SUPPORTS_UBSAN})
    option(scad_tidy_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(scad_tidy_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(scad_tidy_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(scad_tidy_ENABLE_CLANG_TIDY "Enable clang-tidy" ON)
    option(scad_tidy_ENABLE_CPPCHECK "Enable cpp-check analysis" ON)
    option(scad_tidy_ENABLE_PCH "Enable precompiled headers" OFF)
    option(scad_tidy_ENABLE_CACHE "Enable ccache" ON)
  endif()

  if(NOT PROJECT_IS_TOP_LEVEL)
    mark_as_advanced(
      scad_tidy_ENABLE_IPO
      scad_tidy_WARNINGS_AS_ERRORS
      scad_tidy_ENABLE_USER_LINKER
      scad_tidy_ENABLE_SANITIZER_ADDRESS
      scad_tidy_ENABLE_SANITIZER_LEAK
      scad_tidy_ENABLE_SANITIZER_UNDEFINED
      scad_tidy_ENABLE_SANITIZER_THREAD
      scad_tidy_ENABLE_SANITIZER_MEMORY
      scad_tidy_ENABLE_UNITY_BUILD
      scad_tidy_ENABLE_CLANG_TIDY
      scad_tidy_ENABLE_CPPCHECK
      scad_tidy_ENABLE_COVERAGE
      scad_tidy_ENABLE_PCH
      scad_tidy_ENABLE_CACHE)
  endif()

  scad_tidy_check_libfuzzer_support(LIBFUZZER_SUPPORTED)
  if(LIBFUZZER_SUPPORTED AND (scad_tidy_ENABLE_SANITIZER_ADDRESS OR scad_tidy_ENABLE_SANITIZER_THREAD OR scad_tidy_ENABLE_SANITIZER_UNDEFINED))
    set(DEFAULT_FUZZER ON)
  else()
    set(DEFAULT_FUZZER OFF)
  endif()

  option(scad_tidy_BUILD_FUZZ_TESTS "Enable fuzz testing executable" ${DEFAULT_FUZZER})

endmacro()

macro(scad_tidy_global_options)
  if(scad_tidy_ENABLE_IPO)
    include(cmake/InterproceduralOptimization.cmake)
    scad_tidy_enable_ipo()
  endif()

  scad_tidy_supports_sanitizers()

  if(scad_tidy_ENABLE_HARDENING AND scad_tidy_ENABLE_GLOBAL_HARDENING)
    include(cmake/Hardening.cmake)
    if(NOT SUPPORTS_UBSAN 
       OR scad_tidy_ENABLE_SANITIZER_UNDEFINED
       OR scad_tidy_ENABLE_SANITIZER_ADDRESS
       OR scad_tidy_ENABLE_SANITIZER_THREAD
       OR scad_tidy_ENABLE_SANITIZER_LEAK)
      set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
    else()
      set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
    endif()
    message("${scad_tidy_ENABLE_HARDENING} ${ENABLE_UBSAN_MINIMAL_RUNTIME} ${scad_tidy_ENABLE_SANITIZER_UNDEFINED}")
    scad_tidy_enable_hardening(scad_tidy_options ON ${ENABLE_UBSAN_MINIMAL_RUNTIME})
  endif()
endmacro()

macro(scad_tidy_local_options)
  if(PROJECT_IS_TOP_LEVEL)
    include(cmake/StandardProjectSettings.cmake)
  endif()

  add_library(scad_tidy_warnings INTERFACE)
  add_library(scad_tidy_options INTERFACE)

  include(cmake/CompilerWarnings.cmake)
  scad_tidy_set_project_warnings(
    scad_tidy_warnings
    ${scad_tidy_WARNINGS_AS_ERRORS}
    ""
    ""
    ""
    "")

  if(scad_tidy_ENABLE_USER_LINKER)
    include(cmake/Linker.cmake)
    configure_linker(scad_tidy_options)
  endif()

  include(cmake/Sanitizers.cmake)
  scad_tidy_enable_sanitizers(
    scad_tidy_options
    ${scad_tidy_ENABLE_SANITIZER_ADDRESS}
    ${scad_tidy_ENABLE_SANITIZER_LEAK}
    ${scad_tidy_ENABLE_SANITIZER_UNDEFINED}
    ${scad_tidy_ENABLE_SANITIZER_THREAD}
    ${scad_tidy_ENABLE_SANITIZER_MEMORY})

  set_target_properties(scad_tidy_options PROPERTIES UNITY_BUILD ${scad_tidy_ENABLE_UNITY_BUILD})

  if(scad_tidy_ENABLE_PCH)
    target_precompile_headers(
      scad_tidy_options
      INTERFACE
      <vector>
      <string>
      <utility>)
  endif()

  if(scad_tidy_ENABLE_CACHE)
    include(cmake/Cache.cmake)
    scad_tidy_enable_cache()
  endif()

  include(cmake/StaticAnalyzers.cmake)
  if(scad_tidy_ENABLE_CLANG_TIDY)
    scad_tidy_enable_clang_tidy(scad_tidy_options ${scad_tidy_WARNINGS_AS_ERRORS})
  endif()

  if(scad_tidy_ENABLE_CPPCHECK)
    scad_tidy_enable_cppcheck(${scad_tidy_WARNINGS_AS_ERRORS} "" # override cppcheck options
    )
  endif()

  if(scad_tidy_ENABLE_COVERAGE)
    include(cmake/Tests.cmake)
    scad_tidy_enable_coverage(scad_tidy_options)
  endif()

  if(scad_tidy_WARNINGS_AS_ERRORS)
    check_cxx_compiler_flag("-Wl,--fatal-warnings" LINKER_FATAL_WARNINGS)
    if(LINKER_FATAL_WARNINGS)
      # This is not working consistently, so disabling for now
      # target_link_options(scad_tidy_options INTERFACE -Wl,--fatal-warnings)
    endif()
  endif()

  if(scad_tidy_ENABLE_HARDENING AND NOT scad_tidy_ENABLE_GLOBAL_HARDENING)
    include(cmake/Hardening.cmake)
    if(NOT SUPPORTS_UBSAN 
       OR scad_tidy_ENABLE_SANITIZER_UNDEFINED
       OR scad_tidy_ENABLE_SANITIZER_ADDRESS
       OR scad_tidy_ENABLE_SANITIZER_THREAD
       OR scad_tidy_ENABLE_SANITIZER_LEAK)
      set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
    else()
      set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
    endif()
    scad_tidy_enable_hardening(scad_tidy_options OFF ${ENABLE_UBSAN_MINIMAL_RUNTIME})
  endif()

endmacro()
