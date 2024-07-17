#ifndef SCAD_TIDY_SCADLINTER_H
#define SCAD_TIDY_SCADLINTER_H

#include <any>
#include <scad_linter/scad_linter_export.h>
#include <ScadLexer.h>
#include <ScadParserVisitor.h>

namespace scad_linter
{

  class SCAD_LINTER_EXPORT ScadLinter : public parser::ScadParserVisitor
  {
   public:
    using TokenType = decltype( scad_tidy::ScadLexer::MODULE );
    std::any visitAssignableExpression(
        parser::ScadParser::AssignableExpressionContext * context ) override;
    std::any visitArrayAccessExpression(
        parser::ScadParser::ArrayAccessExpressionContext * context ) override;
    std::any visitReservedVariable(
        parser::ScadParser::ReservedVariableContext * context ) override;
    std::any visitUseStatement( parser::ScadParser::UseStatementContext * context ) override;
    std::any visitProgram( parser::ScadParser::ProgramContext * context ) override;
    std::any visitOperation( parser::ScadParser::OperationContext * context ) override;
    std::any visitOperand( parser::ScadParser::OperandContext * context ) override;
    std::any visitNegativeInt( parser::ScadParser::NegativeIntContext * context ) override;
    std::any visitPositiveInt( parser::ScadParser::PositiveIntContext * context ) override;
    std::any visitInteger( parser::ScadParser::IntegerContext * context ) override;
    std::any visitLiteralExpression(
        parser::ScadParser::LiteralExpressionContext * context ) override;
    std::any visitLiteral( parser::ScadParser::LiteralContext * context ) override;
    std::any visitBinaryOperator( parser::ScadParser::BinaryOperatorContext * context ) override;
    std::any visitUnaryOperator( parser::ScadParser::UnaryOperatorContext * context ) override;
    std::any visitFunction_declaration(
        parser::ScadParser::Function_declarationContext * context ) override;
    std::any visitFun_params( parser::ScadParser::Fun_paramsContext * context ) override;
    std::any visitFun_param( parser::ScadParser::Fun_paramContext * context ) override;
    std::any visitFun_body( parser::ScadParser::Fun_bodyContext * context ) override;
    std::any visitFunctionCall( parser::ScadParser::FunctionCallContext * context ) override;
    std::any visitStatement( parser::ScadParser::StatementContext * context ) override;
    std::any visitDebugableStatement(
        parser::ScadParser::DebugableStatementContext * context ) override;
    std::any visitSimpleStatement( parser::ScadParser::SimpleStatementContext * context ) override;
    std::any visitVector( parser::ScadParser::VectorContext * context ) override;
    std::any visitCall_argument( parser::ScadParser::Call_argumentContext * context ) override;
    std::any visitCall_arguments( parser::ScadParser::Call_argumentsContext * context ) override;
    std::any visitModuleDeclaration(
        parser::ScadParser::ModuleDeclarationContext * context ) override;
    std::any visitModuleDeclarationHeader(
        parser::ScadParser::ModuleDeclarationHeaderContext * context ) override;
    std::any visitModule_call( parser::ScadParser::Module_callContext * context ) override;
    std::any visitCodeBlock( parser::ScadParser::CodeBlockContext * context ) override;
    std::any visitVariableAssignment(
        parser::ScadParser::VariableAssignmentContext * context ) override;
    std::any visitIfElseStatement( parser::ScadParser::IfElseStatementContext * context ) override;
    std::any visitIfStatement( parser::ScadParser::IfStatementContext * context ) override;
    std::any visitElseIfStatement( parser::ScadParser::ElseIfStatementContext * context ) override;
    std::any visitElseStatement( parser::ScadParser::ElseStatementContext * context ) override;
    std::any visitTernaryOperator( parser::ScadParser::TernaryOperatorContext * context ) override;
    std::any visitBoolComparisonOperator(
        parser::ScadParser::BoolComparisonOperatorContext * context ) override;
    std::any visitBoolBinaryOperator(
        parser::ScadParser::BoolBinaryOperatorContext * context ) override;
    std::any visitBoolUnaryOperator(
        parser::ScadParser::BoolUnaryOperatorContext * context ) override;
    std::any visitPredicate( parser::ScadParser::PredicateContext * context ) override;
    std::any visitPredicates( parser::ScadParser::PredicatesContext * context ) override;
    std::any visitForStatement( parser::ScadParser::ForStatementContext * context ) override;
    std::any visitRangeAssignment( parser::ScadParser::RangeAssignmentContext * context ) override;
    std::any visitRangeAssignmentList(
        parser::ScadParser::RangeAssignmentListContext * context ) override;
    std::any visitRangeList( parser::ScadParser::RangeListContext * context ) override;
    std::any visitRange( parser::ScadParser::RangeContext * context ) override;
  };

}  // namespace scad_linter

#endif  // SCAD_TIDY_SCADLINTER_H
