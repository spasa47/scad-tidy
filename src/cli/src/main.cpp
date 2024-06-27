#include "cli/MainCLI.h"

#include <scad_utility/pointer_types.hpp>
using scad_utility::ptr;

auto main( [[maybe_unused]] const int argc, [[maybe_unused]] const ptr<const ptr<const char>> argv )
    -> int
{
  using namespace scad_tidy_cli;
  MainCLI app;

  return app.run( argc, argv );
}
