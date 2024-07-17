#ifndef SCAD_TIDY_ERRORCODE_HPP
#define SCAD_TIDY_ERRORCODE_HPP
#include <cstdint>
#include <scad_common/scad_common_export.h>

namespace SCAD_COMMON_EXPORT scad_common::error
{
  enum class ErrorCode : std::uint8_t {
    SUCCESS [[maybe_unused]],
    INVALID_OPTION [[maybe_unused]],
    INVALID_COMMAND [[maybe_unused]],
    INVALID_COMMAND_ARGUMENTS [[maybe_unused]],
    EMPTY_ARGS [[maybe_unused]],
    INVALID_FILE [[maybe_unused]]
  };
}
#endif  // SCAD_TIDY_ERRORCODE_HPP
