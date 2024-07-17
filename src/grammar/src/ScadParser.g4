parser grammar ScadParser;

@parser::postinclude {
/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}


options {
    tokenVocab=ScadLexer;
}

program
    : statement* EOF
    ;

operation :  operand (binaryOperator operand)*
        ;
operand : unaryOperator?  ( ID
        | integer
        | functionCall
        | LPAREN operation RPAREN
        | arrayAccessExpression)
        ;
negativeInt : MINUS NUMBER
            | PLUS negativeInt
            | MINUS positiveInt;
positiveInt : NUMBER
            | PI
            | PLUS positiveInt
            | MINUS negativeInt;

integer : positiveInt | negativeInt;

literalExpression : literal
                  | operation
                  | functionCall
                  ;

literal : integer
        | unaryOperator* ID
        | STRINGLITERAL
        | BOOL
        | vector
        ;

assignableExpression : literalExpression
                     | ternaryOperator
                     | arrayAccessExpression
                     ;

arrayAccessExpression : ID (LSQUARE (integer | ID) RSQUARE)+;

binaryOperator : PLUS
               | MINUS
               | TIMES
               | DIVISION
               | PERCENTSIGN
               | EQUALS
               | NOTEQUALS
               ;
unaryOperator : PLUS
              | MINUS
              ;

function_declaration : FUNCTION ID LPAREN fun_params RPAREN EQ fun_body SEMI;

fun_params :
            | (fun_param COMMA)* fun_param COMMA?
            ;

fun_param : ID
          | ID EQ assignableExpression
          ;

fun_body : operation;

functionCall : ID LPAREN call_arguments RPAREN;

statement : debugableStatement
          |  simpleStatement
          ;

debugableStatement : (HASH | PERCENTSIGN | TIMES) simpleStatement;

simpleStatement : function_declaration
          | module_call
          | moduleDeclaration
          | variableAssignment
          | ifElseStatement
          | forStatement
          | useStatement
          ;

useStatement : USE LESSTHAN ID (DOT ID)? GREATERTHAN;

vector : LSQUARE ((assignableExpression COMMA)* assignableExpression)? RSQUARE;

call_argument : literalExpression
              | ID EQ assignableExpression
              | reservedVariable EQ assignableExpression
              | assignableExpression
              ;


reservedVariable : FA
                 | FS
                 | FN
                 ;

call_arguments :
                | (call_argument COMMA)* call_argument
                ;


moduleDeclaration : moduleDeclarationHeader codeBlock;
moduleDeclarationHeader : MODULE ID LPAREN fun_params RPAREN;

module_call : ID LPAREN call_arguments RPAREN (SEMI | codeBlock | module_call);

codeBlock : LCURLY statement* RCURLY;

variableAssignment : ID EQ assignableExpression SEMI;

ifElseStatement : ifStatement elseIfStatement* elseStatement?;

ifStatement : IF LPAREN predicates RPAREN codeBlock;

elseIfStatement : ELSE IF LPAREN predicates RPAREN codeBlock;

elseStatement : ELSE codeBlock;

ternaryOperator : predicates QUESTIONMARK (operation|ternaryOperator) COLON (operation|ternaryOperator)
                | LPAREN ternaryOperator RPAREN;

boolComparisonOperator : EQUALS
             | NOTEQUALS
             | GREATERTHAN
             | LESSTHAN
             | GREATERTHANEQUALS
             | LESSTHANEQUALS
             ;
boolBinaryOperator : LOGICAND
                   | LOGICOR
                   ;

boolUnaryOperator : LOGICNOT;

predicate : BOOL
          | ID
          | literalExpression boolComparisonOperator literalExpression
          | boolUnaryOperator predicate
          | LPAREN predicate RPAREN
          ;
predicates : (predicate boolBinaryOperator)* predicate;
forStatement : FOR LPAREN rangeAssignmentList RPAREN codeBlock;

rangeAssignment : ID EQ range;

rangeAssignmentList : ((rangeAssignment COMMA)* rangeAssignment)?;

rangeList : ((range COMMA)* range)?;
range : LSQUARE assignableExpression COLON assignableExpression RSQUARE;
