//
// Created by janm on 26.6.24.
//

#ifndef SCAD_TIDY_VERSIONCOMMAND_HPP
#define SCAD_TIDY_VERSIONCOMMAND_HPP
#include "CommandResult.hpp"

namespace scad_tidy_cli::command
{

  class VersionCommand
  {
    CommandResult operator()() const;
  };

}  // namespace scad_tidy_cli::command


#endif  // SCAD_TIDY_VERSIONCOMMAND_HPP
