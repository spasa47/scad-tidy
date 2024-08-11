#include "MainCLI.hpp"

#include "../constant/cli_string_constants.hpp"
#include "command/CommandEnum.hpp"

#include <argparse/argparse.hpp>
#include <exception>
#include <internal_use_only/config.hpp>
#include <scad_common/error/ErrorCode.hpp>
#include <scad_linter/Linter.hpp>
#include <scad_utility/pointer_types.hpp>
#include <spdlog/spdlog.h>
#include <string>
#include <vector>

namespace scad_tidy_cli
{
  using scad_utility::ptr;
  MainCLI::MainCLI()
      : program { constants::APP_NAME.data(),
                  scad_tidy::cmake::project_version.data(),
                  argparse::default_arguments::all },
        lint_command { command::commandEnumToString( command::CommandEnum::LINT ).data() },
        format_command { command::commandEnumToString( command::CommandEnum::FORMAT ).data() }
  {
    using namespace command;
    using enum command::CommandEnum;
    using argparse::ArgumentParser;


    program.add_description( constants::APP_DESCRIPTION.data() );

    lint_command.add_description( "Lint the provided files" );
    lint_command.add_argument( "files" ).remaining();


    format_command.add_description( "Format the provided files" );
    format_command.add_argument( "files" ).remaining();


    program.add_subparser( lint_command );
    program.add_subparser( format_command );
  }
  auto MainCLI::run( [[maybe_unused]] const int                        argc,
                     [[maybe_unused]] const ptr<const ptr<const char>> argv ) noexcept
      -> scad_common::error::ErrorCode
  {
    using namespace command;
    using enum command::CommandEnum;
    using enum scad_common::error::ErrorCode;
    using argparse::ArgumentParser;
    using spdlog::error;

    try {
      program.parse_args( argc, argv );
    } catch ( const std::exception & err ) {
      error( "Error parsing arguments: {}", err.what() );
      return INVALID_COMMAND_ARGUMENTS;
    }
    if ( program.is_subcommand_used( lint_command ) ) {
      return scad_linter::lint( lint_command.get<std::vector<std::string>>( "files" ), {} );
    } else if ( program.is_subcommand_used( format_command ) ) {
      return SUCCESS;
    } else {
      error( "Unknown command" );
      return INVALID_COMMAND;
    }
    return scad_common::error::ErrorCode::SUCCESS;
  }
}  // namespace scad_tidy_cli
