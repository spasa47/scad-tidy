#ifndef SCAD_TIDY_SCADLINTER_H
#define SCAD_TIDY_SCADLINTER_H

#include <any>
#include <scad_linter/scad_linter_export.h>
#include <scad_utility/pointer_types.hpp>
#include <ScadLexer.h>
#include <ScadParserVisitor.h>

namespace scad_linter
{

  using parser::ScadParser;
  using scad_utility::ptr;

  class SCAD_LINTER_EXPORT ScadLinter : public parser::ScadParserVisitor
  {
   public:
    using TokenType = decltype( scad_tidy::ScadLexer::MODULE );
    auto visitAssignableExpression( ptr<ScadParser::AssignableExpressionContext> context )
        -> std::any override;
    auto visitArrayAccessExpression( ptr<ScadParser::ArrayAccessExpressionContext> context )
        -> std::any override;
    auto visitReservedVariable( ptr<ScadParser::ReservedVariableContext> context )
        -> std::any override;
    auto visitUseStatement( ptr<ScadParser::UseStatementContext> context ) -> std::any override;
    auto visitProgram( ptr<ScadParser::ProgramContext> context ) -> std::any override;
    auto visitOperation( ptr<ScadParser::OperationContext> context ) -> std::any override;
    auto visitOperand( ptr<ScadParser::OperandContext> context ) -> std::any override;
    auto visitNegativeInt( ptr<ScadParser::NegativeIntContext> context ) -> std::any override;
    auto visitPositiveInt( ptr<ScadParser::PositiveIntContext> context ) -> std::any override;
    auto visitInteger( ptr<ScadParser::IntegerContext> context ) -> std::any override;
    auto visitLiteralExpression( ptr<ScadParser::LiteralExpressionContext> context )
        -> std::any override;
    auto visitLiteral( ptr<ScadParser::LiteralContext> context ) -> std::any override;
    auto visitBinaryOperator( ptr<ScadParser::BinaryOperatorContext> context ) -> std::any override;
    auto visitUnaryOperator( ptr<ScadParser::UnaryOperatorContext> context ) -> std::any override;
    auto visitFunction_declaration( ptr<ScadParser::Function_declarationContext> context )
        -> std::any override;
    auto visitFun_params( ptr<ScadParser::Fun_paramsContext> context ) -> std::any override;
    auto visitFun_param( ptr<ScadParser::Fun_paramContext> context ) -> std::any override;
    auto visitFun_body( ptr<ScadParser::Fun_bodyContext> context ) -> std::any override;
    auto visitFunctionCall( ptr<ScadParser::FunctionCallContext> context ) -> std::any override;
    auto visitStatement( ptr<ScadParser::StatementContext> context ) -> std::any override;
    auto visitDebugableStatement( ptr<ScadParser::DebugableStatementContext> context )
        -> std::any override;
    auto visitSimpleStatement( ptr<ScadParser::SimpleStatementContext> context )
        -> std::any override;
    auto visitVector( ptr<ScadParser::VectorContext> context ) -> std::any override;
    auto visitCall_argument( ptr<ScadParser::Call_argumentContext> context ) -> std::any override;
    auto visitCall_arguments( ptr<ScadParser::Call_argumentsContext> context ) -> std::any override;
    auto visitModuleDeclaration( ptr<ScadParser::ModuleDeclarationContext> context )
        -> std::any override;
    auto visitModuleDeclarationHeader( ptr<ScadParser::ModuleDeclarationHeaderContext> context )
        -> std::any override;
    auto visitModule_call( ptr<ScadParser::Module_callContext> context ) -> std::any override;
    auto visitCodeBlock( ptr<ScadParser::CodeBlockContext> context ) -> std::any override;
    auto visitVariableAssignment( ptr<ScadParser::VariableAssignmentContext> context )
        -> std::any override;
    auto visitIfElseStatement( ptr<ScadParser::IfElseStatementContext> context )
        -> std::any override;
    auto visitIfStatement( ptr<ScadParser::IfStatementContext> context ) -> std::any override;
    auto visitElseIfStatement( ptr<ScadParser::ElseIfStatementContext> context )
        -> std::any override;
    auto visitElseStatement( ptr<ScadParser::ElseStatementContext> context ) -> std::any override;
    auto visitTernaryOperator( ptr<ScadParser::TernaryOperatorContext> context )
        -> std::any override;
    auto visitBoolComparisonOperator( ptr<ScadParser::BoolComparisonOperatorContext> context )
        -> std::any override;
    auto visitBoolBinaryOperator( ptr<ScadParser::BoolBinaryOperatorContext> context )
        -> std::any override;
    auto visitBoolUnaryOperator( ptr<ScadParser::BoolUnaryOperatorContext> context )
        -> std::any override;
    auto visitPredicate( ptr<ScadParser::PredicateContext> context ) -> std::any override;
    auto visitPredicates( ptr<ScadParser::PredicatesContext> context ) -> std::any override;
    auto visitForStatement( ptr<ScadParser::ForStatementContext> context ) -> std::any override;
    auto visitRangeAssignment( ptr<ScadParser::RangeAssignmentContext> context )
        -> std::any override;
    auto visitRangeAssignmentList( ptr<ScadParser::RangeAssignmentListContext> context )
        -> std::any override;
    auto visitRangeList( ptr<ScadParser::RangeListContext> context ) -> std::any override;
    auto visitRange( ptr<ScadParser::RangeContext> context ) -> std::any override;
  };

}  // namespace scad_linter

#endif  // SCAD_TIDY_SCADLINTER_H
