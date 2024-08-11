#ifndef SCAD_TIDY_MAINCLI_HPP
#define SCAD_TIDY_MAINCLI_HPP


#include <algorithm>
#include <argparse/argparse.hpp>
#include <list>
#include <scad_common/error/ErrorCode.hpp>
#include <scad_utility/pointer_types.hpp>
#include <scad_utility/utility.hpp>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <string_view>
namespace scad_tidy_cli
{

  using scad_utility::ptr;
  /**
   * @brief The main CLI class for the application.
   *
   * This class is responsible for parsing the command line arguments and
   * executing the appropriate command.
   *
   * @note This class is a concrete class.
   * @note This class is a final class.
   * @note This class is not thread-safe.
   * @note This class is not copyable.
   * @note This class is not movable.
   * @note This class is not polymorphic.
   * @note This class is not templated.
   */
  class MainCLI
  {
    /**
     * The options for the CLI.
     *
     * @note This member is private.
     * @note This member is not static.
     * @note This member is not const.
     * @note This member is not thread-safe.
     */
    argparse::ArgumentParser program;

    argparse::ArgumentParser lint_command;

    argparse::ArgumentParser format_command;


   public:
    /**
     * Main constructor for @c MainCLI
     *
     * @note This constructor is public.
     * @note This constructor is explicit.
     */
    explicit MainCLI();

    auto run( const int                        argc,
              const ptr<const ptr<const char>> argv ) noexcept -> scad_common::error::ErrorCode;
  };

}  // namespace scad_tidy_cli

#endif  // SCAD_TIDY_MAINCLI_HPP
