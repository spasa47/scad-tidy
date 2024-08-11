#include <ANTLRInputStream.h>
#include <array>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <CommonTokenStream.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iosfwd>
#include <ostream>
#include <ranges>
#include <ScadLexer.h>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>


namespace test_data
{
  using namespace scad_tidy;

  struct TestData {
    std::string              source;
    std::vector<std::size_t> expectedOutput;

    constexpr explicit TestData( std::string p_source, std::initializer_list<std::size_t> args )
        : source( std::move( p_source ) ), expectedOutput( args )
    {
    }
    constexpr explicit TestData( std::string p_source, decltype( expectedOutput ) args )
        : source( std::move( p_source ) ), expectedOutput( std::move( args ) )
    {
    }
    friend std::ostream & operator<<( std::ostream & os, const TestData & data )
    {
      os << "source: " << data.source
         << "\nexpectedOutput: " << fmt::format( "{}", fmt::join( data.expectedOutput, ", " ) );
      return os;
    }
  };


  template<typename T>
  concept TestDataConcept = std::is_same_v<T, TestData>;

  template<typename T>
  concept StringOrTestData = std::is_same_v<T, std::string> || std::is_same_v<T, TestData>;

  template<typename T>
  concept VectorOrTestData
      = std::is_same_v<T, std::vector<std::size_t>> || std::is_same_v<T, TestData>;

  template<StringOrTestData T1, StringOrTestData T2>
  auto concat_source( const T1 & lhs, const T2 & rhs ) -> std::string
  {
    auto get_source = []<typename T>( const T & data ) -> const std::string & {
      if constexpr ( TestDataConcept<T> ) {
        return data.source;
      } else {
        return data;
      }
    };
    const auto & lhs_source = get_source( lhs );
    const auto & rhs_source = get_source( rhs );

    return lhs_source + rhs_source;
  }

  template<StringOrTestData T1, StringOrTestData T2, StringOrTestData... Args>
  auto concat_source( const T1 & lhs, const T2 & rhs, const Args &... args ) -> std::string
  {
    return concat_source( concat_source( lhs, rhs ), args... );
  }

  template<VectorOrTestData T1, VectorOrTestData T2>
  auto concat_expected( const T1 & lhs, const T2 & rhs ) -> std::vector<std::size_t>
  {
    std::vector<std::size_t> result;
    auto get_expected = []<typename T>( const T & data ) -> const std::vector<std::size_t> & {
      if constexpr ( TestDataConcept<T> ) {
        return data.expectedOutput;
      } else {
        return data;
      }
    };
    const auto & lhs_expected = get_expected( lhs );
    const auto & rhs_expected = get_expected( rhs );
    result.reserve( lhs_expected.size() - 1 + rhs_expected.size() );
    std::ranges::copy( lhs_expected | std::views::take( lhs_expected.size() - 1 ),
                       std::back_inserter( result ) );
    std::ranges::copy( rhs_expected, std::back_inserter( result ) );

    return result;
  }

  template<VectorOrTestData T1, VectorOrTestData T2, VectorOrTestData... Args>
  auto concat_expected( const T1 & lhs,
                        const T2 & rhs,
                        const Args &... args ) -> std::vector<std::size_t>
  {
    return concat_expected( concat_expected( lhs, rhs ), args... );
  }

  auto combine_test_data( const auto &... args )
  {
    return TestData { concat_source( args... ), concat_expected( args... ) };
  }

  const auto test_data_001 = TestData( "function foo() = 1;",
                                       { ScadLexer::FUNCTION,
                                         ScadLexer::WS,
                                         ScadLexer::ID,
                                         ScadLexer::LPAREN,
                                         ScadLexer::RPAREN,
                                         ScadLexer::WS,
                                         ScadLexer::EQ,
                                         ScadLexer::WS,
                                         ScadLexer::NUMBER,
                                         ScadLexer::SEMI,
                                         ScadLexer::EOF } );
  const auto test_data_002 = TestData( "function bar() = 42 ;",
                                       { ScadLexer::FUNCTION,
                                         ScadLexer::WS,
                                         ScadLexer::ID,
                                         ScadLexer::LPAREN,
                                         ScadLexer::RPAREN,
                                         ScadLexer::WS,
                                         ScadLexer::EQ,
                                         ScadLexer::WS,
                                         ScadLexer::NUMBER,
                                         ScadLexer::WS,
                                         ScadLexer::SEMI,
                                         ScadLexer::EOF } );

  const auto test_data_003 = TestData( "function baz( ) = 42 ;",
                                       { ScadLexer::FUNCTION,
                                         ScadLexer::WS,
                                         ScadLexer::ID,
                                         ScadLexer::LPAREN,
                                         ScadLexer::WS,
                                         ScadLexer::RPAREN,
                                         ScadLexer::WS,
                                         ScadLexer::EQ,
                                         ScadLexer::WS,
                                         ScadLexer::NUMBER,
                                         ScadLexer::WS,
                                         ScadLexer::SEMI,
                                         ScadLexer::EOF } );

  const auto test_data_004 = TestData( "function qux( a ) = 42 + a ;",
                                       { ScadLexer::FUNCTION,
                                         ScadLexer::WS,
                                         ScadLexer::ID,
                                         ScadLexer::LPAREN,
                                         ScadLexer::WS,
                                         ScadLexer::ID,
                                         ScadLexer::WS,
                                         ScadLexer::RPAREN,
                                         ScadLexer::WS,
                                         ScadLexer::EQ,
                                         ScadLexer::WS,
                                         ScadLexer::NUMBER,
                                         ScadLexer::WS,
                                         ScadLexer::PLUS,
                                         ScadLexer::WS,
                                         ScadLexer::ID,
                                         ScadLexer::WS,
                                         ScadLexer::SEMI,
                                         ScadLexer::EOF } );
  const auto test_data_005 = TestData(
      "function quux( a, b ) = 42 + a + b ;",
      { ScadLexer::FUNCTION, ScadLexer::WS,    ScadLexer::ID, ScadLexer::LPAREN, ScadLexer::WS,
        ScadLexer::ID,       ScadLexer::COMMA, ScadLexer::WS, ScadLexer::ID,     ScadLexer::WS,
        ScadLexer::RPAREN,   ScadLexer::WS,    ScadLexer::EQ, ScadLexer::WS,     ScadLexer::NUMBER,
        ScadLexer::WS,       ScadLexer::PLUS,  ScadLexer::WS, ScadLexer::ID,     ScadLexer::WS,
        ScadLexer::PLUS,     ScadLexer::WS,    ScadLexer::ID, ScadLexer::WS,     ScadLexer::SEMI,
        ScadLexer::EOF } );


  const auto test_data_006 = combine_test_data( test_data_001, test_data_002 );

  const auto test_data_007 = combine_test_data( test_data_001, test_data_002, test_data_003 );


  const auto test_data_008
      = combine_test_data( test_data_006, test_data_007, test_data_004, test_data_005 );


}  // namespace test_data


TEST_CASE( "Function declarations are lexed", "[function][lexer]" )
{
  auto testData = GENERATE( test_data::test_data_001,
                            test_data::test_data_002,
                            test_data::test_data_003,
                            test_data::test_data_004,
                            test_data::test_data_005,
                            test_data::test_data_006,
                            test_data::test_data_007,
                            test_data::test_data_008 );

  std::stringstream stream( testData.source.data() );

  antlr4::ANTLRInputStream  inputStream( stream );
  scad_tidy::ScadLexer      lexer( &inputStream );
  antlr4::CommonTokenStream tokenStream( &lexer );
  tokenStream.fill();

  const auto tokens = tokenStream.getTokens();

  INFO( "Checking " << testData );
  REQUIRE( tokens.size() == testData.expectedOutput.size() );

  for ( std::size_t i = 0; i < tokens.size(); ++i ) {
    INFO( "Checking " << tokens[ i ]->toString() );
    REQUIRE( tokens[ i ]->getType() == testData.expectedOutput[ i ] );
  }
}
