//
// Created by janm on 25.6.24.
//

#ifndef SCAD_TIDY_CLI_STRING_CONSTANTS_HPP
#define SCAD_TIDY_CLI_STRING_CONSTANTS_HPP
#include <string_view>


namespace scad_tidy_cli::constants {
using namespace std::string_view_literals;
constexpr static inline auto APP_DESCRIPTION = "A linter/formatter for OpenScad files."sv;
constexpr static inline auto APP_NAME = "scad-tidy"sv;

}// namespace scad_tidy_cli::constants

#endif// SCAD_TIDY_CLI_STRING_CONSTANTS_HPP
