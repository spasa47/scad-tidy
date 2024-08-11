#ifndef SCAD_TIDY_LINTERRULES_HPP
#define SCAD_TIDY_LINTERRULES_HPP

#include <cstdint>
#include <scad_common/scad_common_export.h>
#include <scad_utility/combine_enum.hpp>

namespace SCAD_COMMON_EXPORT scad_common::linter
{
  /**
   * @brief Enum class for linter rules about unused code
   *
   * @details This enum class contains all the rules that the linter can check for.
   * @version 1.0
   * @since 1.0
   * @date 2024-07-04
   * @note This enum class is used to specify the rules that the linter should check for.
   * @see Linter
   * @bug No known bugs
   */
  enum class UnusedRule : std::uint8_t {
    /**
     * @brief No unused variables
     *
     * @details This rule checks that there are no unused variables in the code.
     * @version 1.0
     * @since 1.0
     * @date 2024-07-04
     * @note This rule is used to ensure that all variables are used.
     * @see Linter
     * @bug No known bugs
     */
    NO_UNUSED_VARIABLES [[maybe_unused]],
    NO_UNUSED_FUNCTIONS [[maybe_unused]],
    NO_UNUSED_INCLUDES [[maybe_unused]],
    NO_UNUSED_USINGS [[maybe_unused]],
    NO_UNUSED_MODULES [[maybe_unused]],
  };

  /**
   * @brief Enum class for linter rules about floating point numbers
   *
   * @details This enum class contains all the rules that the linter can check for.
   * @version 1.0
   * @since 1.0
   * @date 2024-07-13
   * @note This enum class is used to specify the rules that the linter should check for.
   * @see Linter
   * @bug No known bugs
   */
  enum class FloatRule : std::uint8_t {
    /**
     * @brief No possible loss of precision
     *
     * @details This rule warns if a constant that can not be precisely represented as a floating
     * point number is used.
     * @version 1.0
     * @since 1.0
     * @date 2024-07-13
     * @note This rule is used to ensure that there are no possible loss of precision when using
     * floating point numbers.
     * @see Linter
     * @bug No known bugs
     */
    POSSIBLE_LOSS_OF_PRECISION [[maybe_unused]],
  };

  enum class NamingRule : std::uint8_t {
    CAMEL_CASE_MODULES [[maybe_unused]],
    CAMEL_CASE_FUNCTIONS [[maybe_unused]],
    CAMEL_CASE_VARIABLES [[maybe_unused]],
    SNAKE_CASE_MODULES [[maybe_unused]],
    SNAKE_CASE_FUNCTIONS [[maybe_unused]],
    SNAKE_CASE_VARIABLES [[maybe_unused]],
    UPPER_CASE_MODULES [[maybe_unused]],
    UPPER_CASE_FUNCTIONS [[maybe_unused]],
    UPPER_CASE_VARIABLES [[maybe_unused]],
  };

  enum class MiscRule : std::uint8_t {
    NO_MAGIC_NUMBERS [[maybe_unused]],
  };

  using AllLinterRules = scad_utility::CombineEnum<UnusedRule, FloatRule, NamingRule, MiscRule>;
}  // namespace scad_common::linter
#endif  // SCAD_TIDY_LINTERRULES_HPP
