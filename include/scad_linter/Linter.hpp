#ifndef SCAD_TIDY_LINTER_HPP
#define SCAD_TIDY_LINTER_HPP


#include <scad_common/error/ErrorCode.hpp>
#include <scad_common/linter/LinterRules.hpp>
#include <scad_linter/scad_linter_export.h>
#include <set>
#include <string>
#include <vector>

/**
 * @brief The scad_linter namespace contains the linter functionality.
 *
 * The linter is a tool that analyzes source code to flag programming errors, bugs, stylistic
 * errors, and suspicious constructs. The linter is used to ensure that the code is compliant with
 * the coding standards.
 */
namespace SCAD_LINTER_EXPORT scad_linter
{

  /**
   * Lint the files with the given rules.
   * @param files The files to lint.
   * @param rules The rules to use.
   * @return The error/success code.
   * @note This function is thread-safe.
   * @note This function is reentrant.
   */
  auto lint( const std::vector<std::string> &                      files,
             const std::set<scad_common::linter::AllLinterRules> & rules )
      -> scad_common::error::ErrorCode;

}  // namespace SCAD_LINTER_EXPORT scad_linter
#endif  // SCAD_TIDY_LINTER_HPP
