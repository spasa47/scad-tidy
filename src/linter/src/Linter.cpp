#include "visitor/ScadLinter.h"

#include <ANTLRInputStream.h>
#include <CommonTokenStream.h>
#include <iosfwd>
#include <iostream>
#include <scad_common/error/ErrorCode.hpp>
#include <scad_common/linter/LinterRules.hpp>
#include <scad_linter/Linter.hpp>
#include <ScadLexer.h>
#include <ScadParser.h>
#include <set>
#include <spdlog/spdlog.h>
#include <string>
#include <vector>
namespace scad_linter
{
  auto lint( [[maybe_unused]] const std::vector<std::string> &                      files,
             [[maybe_unused]] const std::set<scad_common::linter::AllLinterRules> & rules )
      -> scad_common::error::ErrorCode
  {
    for ( const auto & fileStr : files ) {
      spdlog::info( "Linting file: {}", fileStr );
      std::ifstream file( fileStr );
      if ( !file ) {
        spdlog::error( "Could not open file: {}", fileStr );
        return scad_common::error::ErrorCode::INVALID_FILE;
      }
      antlr4::ANTLRInputStream  inputStream( file );
      scad_tidy::ScadLexer      lexer( &inputStream );
      antlr4::CommonTokenStream tokenStream( &lexer );
      parser::ScadParser        scadParser( &tokenStream );
      scadParser.setBuildParseTree( true );
      parser::ScadParser::ProgramContext * tree = scadParser.program();
      scad_linter::ScadLinter              visitor;
      [[maybe_unused]] auto                tmp = visitor.visitProgram( tree );
    }
    return scad_common::error::ErrorCode::SUCCESS;
  }
}  // namespace scad_linter
