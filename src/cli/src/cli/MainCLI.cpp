//
// Created by janm on 25.6.24.
//

#include "MainCLI.h"

#include "../constant/cli_string_constants.hpp"

#include <cxxopts.hpp>
#include <iostream>
#include <scad_utility/pointer_types.hpp>
#include <string>

namespace scad_tidy_cli
{
  using scad_utility::ptr;
  MainCLI::MainCLI() : options( constants::APP_NAME.data(), constants::APP_DESCRIPTION.data() )
  {
    options.add_options()( "version",
                           "Shows the application version",
                           cxxopts::value<bool>()->default_value( "false" ) )( "h,help",
                                                                               "Print usage" );
  }
  auto MainCLI::run( [[maybe_unused]] const int                        argc,
                     [[maybe_unused]] const ptr<const ptr<const char>> argv ) -> int
  {
    auto result = options.parse( argc, argv );
    if ( result.count( "help" ) != 0U ) {
      std::cout << options.help() << '\n';
      return ( 0 );
    }

    return 0;
  }
}  // namespace scad_tidy_cli