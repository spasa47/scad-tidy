//
// Created by janm on 25.6.24.
//

#ifndef SCAD_TIDY_CLI_FLAGS_CONSTANTS_HPP
#define SCAD_TIDY_CLI_FLAGS_CONSTANTS_HPP

#include <string_view>
namespace scad_tidy_cli::constants {
using namespace std::string_view_literals;
constexpr static inline auto VERSION_FLAG = "-v,--version"sv;
}// namespace scad_tidy_cli::constants
#endif// SCAD_TIDY_CLI_FLAGS_CONSTANTS_HPP
