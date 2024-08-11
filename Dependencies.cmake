include(cmake/CPM.cmake)

# Done as a function so that updates to variables like
# CMAKE_CXX_FLAGS don't propagate out to other
# targets
function(scad_tidy_setup_dependencies)

  # For each dependency, see if it's
  # already been provided to us by a parent project
  set(CPM_SOURCE_CACHE CPMCache)

  if(NOT TARGET fmtlib::fmtlib)
    cpmaddpackage(
      NAME
      fmt
      GIT_TAG
      10.2.1
      GITHUB_REPOSITORY
      fmtlib/fmt
      GIT_PROGRESS
      ON)
  endif()

  if(NOT TARGET spdlog::spdlog)
    cpmaddpackage(
      NAME
      spdlog
      VERSION
      1.14.1
      GITHUB_REPOSITORY
      "gabime/spdlog"
      GIT_PROGRESS
      ON
      OPTIONS
      "SPDLOG_FMT_EXTERNAL ON")
  endif()

  if(NOT TARGET Catch2::Catch2WithMain)
    cpmaddpackage(
      NAME
      Catch2
      VERSION
      3.3.2
      GITHUB_REPOSITORY
      catchorg/Catch2
      GIT_PROGRESS
      ON)
  endif()

  if(NOT TARGET rangrang)
    cpmaddpackage(
      NAME
      rang
      GITHUB_REPOSITORY
      agauniyal/rang
      GIT_TAG
      v3.1.0)
    if(rang_ADDED)
      add_library(rang INTERFACE IMPORTED)
      target_include_directories(rang INTERFACE "${rang_SOURCE_DIR}/include")
    endif()
  endif()

  if(NOT TARGET progresscpp)
    cpmaddpackage(
      NAME
      progresscpp
      GITHUB_REPOSITORY
      prakhar1989/progress-cpp
      GIT_TAG
      7bfba0d22d19c41323aa35541618b6ebec9d737c)
  endif()

  if(NOT TARGET tabulate::tabulate)
    cpmaddpackage(
      NAME
      tabulate
      GITHUB_REPOSITORY
      p-ranav/tabulate
      VERSION
      1.4)
  endif()

  if(NOT TARGET argparse::argparse)
    cpmaddpackage(
      NAME
      argparse
      GITHUB_REPOSITORY
      p-ranav/argparse
      VERSION
      3.0)
  endif()

  if(NOT TARGET cxxopts::cxxopts)
    cpmaddpackage(
      NAME
      cxxopts
      GITHUB_REPOSITORY
      jarro2783/cxxopts
      VERSION
      3.2.0
      GIT_PROGRESS
      ON)

  endif()

  if(NOT TARGET nlohmann_json::nlohmann_json)
    cpmaddpackage(
      NAME
      nlohmann_json
      VERSION
      3.11.2
      GITHUB_REPOSITORY
      nlohmann/json
      GIT_PROGRESS
      ON
      OPTIONS
      "JSON_ImplicitConversions OFF")
  endif()

  if(NOT TARGET antlr4::antlr4_static)

    cpmaddpackage(
      NAME
      antlr4
      GITHUB_REPOSITORY
      antlr/antlr4
      GIT_TAG
      ${ANTLR_TAG}
      SOURCE_SUBDIR
      runtime/Cpp)
    include(${antlr4_SOURCE_DIR}/runtime/Cpp/cmake/FindANTLR.cmake) # populates ANTLR_TARGET
    set(antlr4_SOURCE_DIR
        "${antlr4_SOURCE_DIR}"
        PARENT_SCOPE)
  endif()

  if(NOT TARGET Microsoft.GSL::GSL)
    cpmaddpackage(
      NAME
      GSL
      GIT_REPOSITORY
      "https://github.com/microsoft/GSL"
      GIT_TAG
      "v4.0.0"
      GIT_PROGRESS
      ON
      GIT_SHALLOW
      ON)

  endif()

  if(NOT TARGET tools::tools)
    cpmaddpackage(
      NAME
      tools
      GIT_TAG
      "update_build_system"
      GITHUB_REPOSITORY
      lefticus/tools
      GIT_PROGRESS
      ON)
  endif()

  if(NOT TARGET Format.cmake::format)
    cpmaddpackage(
      NAME
      Format.cmake
      GITHUB_REPOSITORY
      TheLartians/Format.cmake
      VERSION
      1.8.1
      OPTIONS
      "CMAKE_FORMAT_EXCLUDE CPMCache/*/*")
  endif()

  if(NOT TARGET CPMLicences.cmake::write-licenses)
    cpmaddpackage(
      NAME
      CPMLicenses.cmake
      GITHUB_REPOSITORY
      TheLartians/CPMLicenses.cmake
      VERSION
      0.0.7)

    cpm_licenses_create_disclaimer_target(write-licenses "${CMAKE_CURRENT_BINARY_DIR}/third_party.txt"
                                          "${CPM_PACKAGES}")

  endif()

endfunction()
