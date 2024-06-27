//
// Created by janm on 25.6.24.
//

#ifndef SCAD_TIDY_MAINCLI_H
#define SCAD_TIDY_MAINCLI_H

#include "command/CommandConcept.hpp"

#include <cxxopts.hpp>
#include <scad_utility/pointer_types.hpp>
#include <scad_utility/utility.hpp>

namespace scad_tidy_cli
{

  using scad_utility::ptr;
  class MainCLI
  {
    cxxopts::Options options;
    template<typename T>
      requires command::is_scad_tidy_command<T>
    constexpr auto add_option( const T & input ) -> void
    {
      options.add_option( input );
    }

   public:
    /**
     * Main constructor for @c MainCLI
     */
    explicit MainCLI();

    auto run( const int argc, const ptr<const ptr<const char>> argv ) -> int;

    template<typename T, typename... TArgs>
    constexpr auto add_options( const T & first_option, const TArgs &... args ) -> void
    {
      add_option( first_option );
      add_options( args... );
    }
  };

}  // namespace scad_tidy_cli

#endif  // SCAD_TIDY_MAINCLI_H
