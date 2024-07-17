// DELETE THIS CONTENT IF YOU PUT COMBINED GRAMMAR IN Parser TAB
lexer grammar ScadLexer;

@lexer::postinclude {
/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

channels { CommentsChannel }

USE : 'use' ;
AND : 'and' ;
OR : 'or' ;
NOT : 'not' ;
EQ : '=' ;
COMMA : ',' ;
SEMI : ';' ;
LPAREN : '(' ;
RPAREN : ')' ;
LCURLY : '{' ;
RCURLY : '}' ;
PLUS : '+';
MINUS : '-';
TIMES : '*';
DIVISION : '/';
PERCENTSIGN : '%';
LSQUARE : '[';
RSQUARE : ']';
IF : 'if';
ELSE : 'else';
FOR : 'for';
EQUALS : '==';
NOTEQUALS : '!=';
LESSTHAN : '<';
GREATERTHAN : '>';
LESSTHANEQUALS : '<=';
GREATERTHANEQUALS : '>=';
LOGICAND : '&&';
LOGICOR : '||';
LOGICNOT : '!';
COLON : ':';
DOT : '.';


QUESTIONMARK : '?';

//for debuging
HASH : '#';

// keywords
FUNCTION : 'function';
MODULE : 'module';

// predeclared variables
PI : 'PI';
FA : '$fa';
FS : '$fs';
FN : '$fn';

NUMBER : INT ('.' DECIMALPART)?;
DECIMALPART : INT;
INT : DIGIT+ ;
fragment DIGIT: [0-9];
WS: [ \t\n\r\f]+ -> channel(HIDDEN) ;
BOOL: 'true' | 'false';
BlockComment
    : '/*' .*? '*/' -> channel(CommentsChannel)
    ;

LineComment
    : '//' ~[\r\n]* -> channel(CommentsChannel)
    ;

STRINGLITERAL : '"' CHARSEQUENCE '"';


fragment CHARSEQUENCE
    : CHAR+
    ;

fragment CHAR
    : ~["\\\r\n]
    | EscapeSequence
    | '\\\n'   // Added line
    | '\\\r\n' // Added line
    ;

fragment EscapeSequence
    : '\\' ['"?abfnrtv\\]
    ;

ID: [a-zA-Z_][a-zA-Z_0-9]* ;

