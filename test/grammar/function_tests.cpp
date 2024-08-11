#include <ANTLRInputStream.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <CommonTokenStream.h>
#include <iosfwd>
#include <ScadLexer.h>
#include <ScadParser.h>

TEST_CASE( "Function declarations are processed", "[function][grammar]" )
{
  INFO( "Test case start" );
  const auto * const declarations = GENERATE(
      "function foo() = 1;", "function bar() = 2;", "function baz() = 3;" );
  std::stringstream         stream( declarations );
  antlr4::ANTLRInputStream  inputStream( stream );
  scad_tidy::ScadLexer      lexer( &inputStream );
  antlr4::CommonTokenStream tokenStream( &lexer );
  parser::ScadParser        scadParser( &tokenStream );
  scadParser.setBuildParseTree( true );
  [[maybe_unused]] const parser::ScadParser::ProgramContext * tree = scadParser.program();

  INFO("Test case end");
  REQUIRE( scadParser.getNumberOfSyntaxErrors() == 0);
}
