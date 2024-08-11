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

  constexpr auto commandEnumFromString( const std::string_view command ) -> CommandEnum
  {
    using enum scad_tidy_cli::command::CommandEnum;
    if ( command == "lint" ) {
      return LINT;
    }
    if ( command == "format" ) {
      return FORMAT;
    }
    return UNKNOWN;
  }

  constexpr auto commandEnumToString( const CommandEnum command ) -> std::string_view
  {
    using enum scad_tidy_cli::command::CommandEnum;
    switch ( command ) {
      case LINT:
        return "lint";
      case FORMAT:
        return "format";
      case UNKNOWN:
        return "unknown";
    }
  }


}  // namespace scad_tidy_cli::command
#endif  // SCAD_TIDY_COMMANDENUM_HPP
