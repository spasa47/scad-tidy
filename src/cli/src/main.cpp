#include "cli/MainCLI.hpp"

#include <scad_utility/pointer_types.hpp>
#include <scad_utility/utility.hpp>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
using scad_utility::ptr;

auto main( [[maybe_unused]] const int                        argc,
           [[maybe_unused]] const ptr<const ptr<const char>> argv ) -> int
{
  spdlog::set_level( spdlog::level::debug );
  spdlog::debug( "App launched" );
  using namespace scad_tidy_cli;
  MainCLI app;

  spdlog::debug( "App constructed, proceeding to run..." );
  return scad_utility::to_underlying( app.run( argc, argv ) );
}
