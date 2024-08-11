#include "ScadLinter.h"

#include <any>
#include <scad_utility/pointer_types.hpp>
#include <ScadParser.h>
namespace scad_linter
{
  using parser::ScadParser;
  using scad_utility::ptr;
  auto ScadLinter::visitProgram( [[maybe_unused]] ptr<ScadParser::ProgramContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitOperation( [[maybe_unused]] ptr<ScadParser::OperationContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitOperand( [[maybe_unused]] ptr<ScadParser::OperandContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitNegativeInt( [[maybe_unused]] ptr<ScadParser::NegativeIntContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitPositiveInt( [[maybe_unused]] ptr<ScadParser::PositiveIntContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitInteger( [[maybe_unused]] ptr<ScadParser::IntegerContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitLiteralExpression(
      [[maybe_unused]] ptr<ScadParser::LiteralExpressionContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitLiteral( [[maybe_unused]] ptr<ScadParser::LiteralContext> context )
      -> std::any
  {
    return {};
  }

  auto ScadLinter::visitBinaryOperator(
      [[maybe_unused]] ptr<ScadParser::BinaryOperatorContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitUnaryOperator(
      [[maybe_unused]] ptr<ScadParser::UnaryOperatorContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitFunction_declaration(
      [[maybe_unused]] ptr<ScadParser::Function_declarationContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitFun_params( [[maybe_unused]] ptr<ScadParser::Fun_paramsContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitFun_param( [[maybe_unused]] ptr<ScadParser::Fun_paramContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitFun_body( [[maybe_unused]] ptr<ScadParser::Fun_bodyContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitFunctionCall(
      [[maybe_unused]] ptr<ScadParser::FunctionCallContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitStatement( [[maybe_unused]] ptr<ScadParser::StatementContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitDebugableStatement(
      [[maybe_unused]] ptr<ScadParser::DebugableStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitSimpleStatement(
      [[maybe_unused]] ptr<ScadParser::SimpleStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitVector( [[maybe_unused]] ptr<ScadParser::VectorContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitCall_argument(
      [[maybe_unused]] ptr<ScadParser::Call_argumentContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitCall_arguments(
      [[maybe_unused]] ptr<ScadParser::Call_argumentsContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitModuleDeclaration(
      [[maybe_unused]] ptr<ScadParser::ModuleDeclarationContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitModuleDeclarationHeader(
      [[maybe_unused]] ptr<ScadParser::ModuleDeclarationHeaderContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitModule_call( [[maybe_unused]] ptr<ScadParser::Module_callContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitCodeBlock( [[maybe_unused]] ptr<ScadParser::CodeBlockContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitVariableAssignment(
      [[maybe_unused]] ptr<ScadParser::VariableAssignmentContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitIfElseStatement(
      [[maybe_unused]] ptr<ScadParser::IfElseStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitIfStatement( [[maybe_unused]] ptr<ScadParser::IfStatementContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitElseIfStatement(
      [[maybe_unused]] ptr<ScadParser::ElseIfStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitElseStatement(
      [[maybe_unused]] ptr<ScadParser::ElseStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitTernaryOperator(
      [[maybe_unused]] ptr<ScadParser::TernaryOperatorContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitBoolComparisonOperator(
      [[maybe_unused]] ptr<ScadParser::BoolComparisonOperatorContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitBoolBinaryOperator(
      [[maybe_unused]] ptr<ScadParser::BoolBinaryOperatorContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitBoolUnaryOperator(
      [[maybe_unused]] ptr<ScadParser::BoolUnaryOperatorContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitPredicate( [[maybe_unused]] ptr<ScadParser::PredicateContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitPredicates( [[maybe_unused]] ptr<ScadParser::PredicatesContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitForStatement(
      [[maybe_unused]] ptr<ScadParser::ForStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitRangeAssignment(
      [[maybe_unused]] ptr<ScadParser::RangeAssignmentContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitRangeAssignmentList(
      [[maybe_unused]] ptr<ScadParser::RangeAssignmentListContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitRangeList( [[maybe_unused]] ptr<ScadParser::RangeListContext> context )
      -> std::any
  {
    return {};
  }
  auto ScadLinter::visitRange( [[maybe_unused]] ptr<ScadParser::RangeContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitUseStatement(
      [[maybe_unused]] ptr<ScadParser::UseStatementContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitAssignableExpression(
      [[maybe_unused]] ptr<ScadParser::AssignableExpressionContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitReservedVariable(
      [[maybe_unused]] ptr<ScadParser::ReservedVariableContext> context ) -> std::any
  {
    return {};
  }
  auto ScadLinter::visitArrayAccessExpression(
      [[maybe_unused]] ptr<ScadParser::ArrayAccessExpressionContext> context ) -> std::any
  {
    return {};
  }

}  // namespace scad_linter