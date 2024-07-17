//
// Created by janm on 4.7.24.
//

#ifndef SCAD_TIDY_COMMANDENUM_HPP
#define SCAD_TIDY_COMMANDENUM_HPP
#include <cstdint>
#include <string_view>
namespace scad_tidy_cli::command
{
  enum class CommandEnum : std::uint8_t { LINT, FORMAT, UNKNOWN };

  constexpr auto commandEnumFromString(const std::string_view command) -> CommandEnum {
    if (command == "lint") {
      return CommandEnum::LINT;
    }
    if (command == "format") {
      return CommandEnum::FORMAT;
    }
    return CommandEnum::UNKNOWN;
  }

  constexpr auto commandEnumToString(const CommandEnum command) -> std::string_view {
    switch (command) {
      case CommandEnum::LINT:
        return "lint";
      case CommandEnum::FORMAT:
        return "format";
      case CommandEnum::UNKNOWN:
        return "unknown";
    }
  }



} // namespace scad_tidy_cli::command
#endif  // SCAD_TIDY_COMMANDENUM_HPP
