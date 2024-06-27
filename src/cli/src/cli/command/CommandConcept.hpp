//
// Created by janm on 26.6.24.
//

#ifndef SCAD_TIDY_COMMANDCONCEPT_HPP
#define SCAD_TIDY_COMMANDCONCEPT_HPP
#include "CommandResult.hpp"

#include <utility>
namespace scad_tidy_cli::command
{
  template<typename T>
  concept callable = requires( T t ) {
    {
      t()
    } -> std::convertible_to<CommandResult>;
  };


  template<typename T>
  concept is_scad_tidy_command = callable<T>;
}  // namespace scad_tidy_cli::command
#endif  // SCAD_TIDY_COMMANDCONCEPT_HPP
