//
// Created by janm on 25.6.24.
//

//#include <scad_linter/Scad_Linter.h>
//#include <scad_lint/ScadLinter.h>
#include <scad_linter/ScadLinter.h>
#include <ScadParser.h>
#include <any>

namespace scad_linter {
    std::any ScadLinter::visitProgram([[maybe_unused]] parser::ScadParser::ProgramContext *context) {
        return {};
    }
    std::any ScadLinter::visitOperation([[maybe_unused]] parser::ScadParser::OperationContext *context) {
        return {};
    }
    std::any ScadLinter::visitOperand([[maybe_unused]]parser::ScadParser::OperandContext *context) {
        return {};
    }
    std::any ScadLinter::visitNegativeInt([[maybe_unused]] parser::ScadParser::NegativeIntContext *context) {
        return {};
    }
    std::any ScadLinter::visitPositiveInt([[maybe_unused]] parser::ScadParser::PositiveIntContext *context) {
        return {};
    }
    std::any ScadLinter::visitInteger([[maybe_unused]] parser::ScadParser::IntegerContext *context) {
        return {};
    }
    std::any ScadLinter::visitLiteralExpression([[maybe_unused]] parser::ScadParser::LiteralExpressionContext *context) {
        return {};
    }
    std::any ScadLinter::visitLiteral([[maybe_unused]] parser::ScadParser::LiteralContext *context) {
        return {};
    }
    std::any ScadLinter::visitAssignmentOperator([[maybe_unused]] parser::ScadParser::AssignmentOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitBinaryOperator([[maybe_unused]]parser::ScadParser::BinaryOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitUnaryOperator([[maybe_unused]]parser::ScadParser::UnaryOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitFunction_declaration([[maybe_unused]]parser::ScadParser::Function_declarationContext *context) {
        return {};
    }
    std::any ScadLinter::visitFun_params([[maybe_unused]]parser::ScadParser::Fun_paramsContext *context) {
        return {};
    }
    std::any ScadLinter::visitFun_param([[maybe_unused]]parser::ScadParser::Fun_paramContext *context) {
        return {};
    }
    std::any ScadLinter::visitFun_body([[maybe_unused]]parser::ScadParser::Fun_bodyContext *context) {
        return {};
    }
    std::any ScadLinter::visitFunctionCall([[maybe_unused]]parser::ScadParser::FunctionCallContext *context) {
        return {};
    }
    std::any ScadLinter::visitStatement([[maybe_unused]]parser::ScadParser::StatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitDebugableStatement([[maybe_unused]]parser::ScadParser::DebugableStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitSimpleStatement([[maybe_unused]]parser::ScadParser::SimpleStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitVector([[maybe_unused]]parser::ScadParser::VectorContext *context) {
        return {};
    }
    std::any ScadLinter::visitCall_argument([[maybe_unused]]parser::ScadParser::Call_argumentContext *context) {
        return {};
    }
    std::any ScadLinter::visitCall_arguments([[maybe_unused]]parser::ScadParser::Call_argumentsContext *context) {
        return {};
    }
    std::any ScadLinter::visitModuleDeclaration([[maybe_unused]]parser::ScadParser::ModuleDeclarationContext *context) {
        return {};
    }
    std::any ScadLinter::visitModuleDeclarationHeader([[maybe_unused]]parser::ScadParser::ModuleDeclarationHeaderContext *context) {
        return {};
    }
    std::any ScadLinter::visitModule_call([[maybe_unused]]parser::ScadParser::Module_callContext *context) {
        return {};
    }
    std::any ScadLinter::visitCodeBlock([[maybe_unused]]parser::ScadParser::CodeBlockContext *context) {
        return {};
    }
    std::any ScadLinter::visitVariableAssignment([[maybe_unused]]parser::ScadParser::VariableAssignmentContext *context) {
        return {};
    }
    std::any ScadLinter::visitIfElseStatement([[maybe_unused]]parser::ScadParser::IfElseStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitIfStatement([[maybe_unused]]parser::ScadParser::IfStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitElseIfStatement([[maybe_unused]]parser::ScadParser::ElseIfStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitElseStatement([[maybe_unused]]parser::ScadParser::ElseStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitTernaryOperator([[maybe_unused]]parser::ScadParser::TernaryOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitBoolComparisonOperator([[maybe_unused]]parser::ScadParser::BoolComparisonOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitBoolBinaryOperator([[maybe_unused]]parser::ScadParser::BoolBinaryOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitBoolUnaryOperator([[maybe_unused]]parser::ScadParser::BoolUnaryOperatorContext *context) {
        return {};
    }
    std::any ScadLinter::visitPredicate([[maybe_unused]]parser::ScadParser::PredicateContext *context) {
        return {};
    }
    std::any ScadLinter::visitPredicates([[maybe_unused]]parser::ScadParser::PredicatesContext *context) {
        return {};
    }
    std::any ScadLinter::visitForStatement([[maybe_unused]]parser::ScadParser::ForStatementContext *context) {
        return {};
    }
    std::any ScadLinter::visitRangeAssignment([[maybe_unused]]parser::ScadParser::RangeAssignmentContext *context) {
        return {};
    }
    std::any ScadLinter::visitRangeAssignmentList([[maybe_unused]]parser::ScadParser::RangeAssignmentListContext *context) {
        return {};
    }
    std::any ScadLinter::visitRangeList([[maybe_unused]]parser::ScadParser::RangeListContext *context) {
        return {};
    }
    std::any ScadLinter::visitRange([[maybe_unused]]parser::ScadParser::RangeContext *context) {
        return {};
    }
}// namespace scad_linter