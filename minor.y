%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

int yylex();
void evaluate(Node *p);
void yyerror(char *s);
int lbl;
/*int yydebug=1;*/

%}

%union {
	int i;			/* integer value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
};

%token <i> LITERAL_I
%token <s> LITERAL_S
%token <i> LITERAL_C

%token <s> IDENTIFICADOR

 /* Reserved words */
%token PROGRAM MODULE START END
%token VOID CONST NUMBER ARRAY STRING
%token FUNCTION PUBLIC FORWARD
%token IF THEN ELSE ELIF FI FOR UNTIL STEP DO DONE REPEAT STOP
%token RETURN

%token DECLARATIONS DECLARATION BODY NIL VAR LITERAL

%nonassoc ELSE
%right ATTR '^'
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%' '&' '|' ULOCATION
%nonassoc UMINUS UINPUT UNEG UAND

%type <n> file program module declarations declaration instructs instruct expression
%type <n> literals int_vec literal function qualifier type variable variables
%type <n> elif elifs args body

%%

file : program {;}
	| module {;}
	;

program : PROGRAM declarations START body END {printNode(binNode(PROGRAM, $2, $4), 0, (char**)yyname);}
	| PROGRAM declarations START END {printNode(uniNode(PROGRAM, $2), 0, (char**)yyname);}
	| PROGRAM START body END {printNode(uniNode(PROGRAM, $3), 0, (char**)yyname);}
	;

module : MODULE declarations END {printNode(uniNode(MODULE, $2), 0, (char**)yyname);}
	| MODULE END {printNode(nilNode(NIL), 0, (char**)yyname);}
	;

declarations : declaration {$$ = uniNode(DECLARATION, $1);}
	| declarations ';' declaration {$$ = binNode(DECLARATIONS, $1, $3);}
	;

declaration : function {$$ = uniNode(FUNCTION, $1);}
	| qualifier CONST variable ATTR literals {$$ = binNode(CONST, $3, $5);}
	| qualifier CONST variable ATTR int_vec {$$ = binNode(CONST, $3, $5);}
	| qualifier CONST variable {$$ = uniNode(CONST, $3);}
	| qualifier variable {$$ = uniNode(VAR, $2);}
	| CONST variable ATTR literals {$$ = binNode(CONST, $2, $4);}
	| CONST variable ATTR int_vec {$$ = binNode(CONST, $2, $4);}
	| CONST variable {$$ = uniNode(CONST, $2);}
	| variable ATTR literals {$$ = binNode(ATTR, $1, $3);}
	| variable ATTR int_vec {$$ = binNode(ATTR, $1, $3);}
	| variable {$$ = uniNode(VAR, $1);}
	;

literals : literal {$$ = uniNode(LITERAL, $1);}
	| literals literal {$$ = binNode(LITERAL, $1, $2);}
	;

int_vec : LITERAL_I {$$ = intNode(LITERAL_I, $1);}
	| int_vec ',' LITERAL_I {$$ = binNode(',', $1, intNode(LITERAL_I, $3));}
	;

literal : LITERAL_I {$$ = intNode(LITERAL_I, $1);}
	| LITERAL_C {$$ = intNode(LITERAL_C, $1);}
	| LITERAL_S {$$ = strNode(LITERAL_S, $1);}
	;

function: FUNCTION qualifier type IDENTIFICADOR variables	DONE {$$ = quadNode(FUNCTION, $2, $3, strNode(IDENTIFICADOR, $4), $5);}
	| FUNCTION qualifier type IDENTIFICADOR variables	DO body {$$ = pentNode(FUNCTION, $2, $3, strNode(IDENTIFICADOR, $4), $5, $7);}
	| FUNCTION qualifier type IDENTIFICADOR	DO body {$$ = quadNode(FUNCTION, $2, $3, strNode(IDENTIFICADOR, $4), $6);}
	| FUNCTION qualifier type IDENTIFICADOR	DONE {$$ = triNode(FUNCTION, $2, $3, strNode(IDENTIFICADOR, $4));}
	| FUNCTION qualifier VOID IDENTIFICADOR variables	DO body {$$ = pentNode(FUNCTION, $2, nilNode(VOID), strNode(IDENTIFICADOR, $4), $5, $7);}
	| FUNCTION qualifier VOID IDENTIFICADOR variables	DONE {$$ = quadNode(FUNCTION, $2, nilNode(VOID), strNode(IDENTIFICADOR, $4), $5);}
	| FUNCTION qualifier VOID IDENTIFICADOR	DO body {$$ = quadNode(FUNCTION, $2, nilNode(VOID), strNode(IDENTIFICADOR, $4), $6);}
	| FUNCTION qualifier VOID IDENTIFICADOR	DONE {$$ = triNode(FUNCTION, $2, nilNode(VOID), strNode(IDENTIFICADOR, $4));}
	| FUNCTION type IDENTIFICADOR variables	DO body {$$ = quadNode(FUNCTION, $2, strNode(IDENTIFICADOR, $3), $4, $6);}
	| FUNCTION type IDENTIFICADOR variables	DONE {$$ = triNode(FUNCTION, $2, strNode(IDENTIFICADOR, $3), $4);}
	| FUNCTION type IDENTIFICADOR	DO body {$$ = triNode(FUNCTION, $2, strNode(IDENTIFICADOR, $3), $5);}
	| FUNCTION type IDENTIFICADOR	DONE {$$ = binNode(FUNCTION, $2, strNode(IDENTIFICADOR, $3));}
	| FUNCTION VOID IDENTIFICADOR variables	DO body {$$ = quadNode(FUNCTION, nilNode(VOID), strNode(IDENTIFICADOR, $3), $4, $6);}
	| FUNCTION VOID IDENTIFICADOR variables	DONE {$$ = triNode(FUNCTION, nilNode(VOID), strNode(IDENTIFICADOR, $3), $4);}
	| FUNCTION VOID IDENTIFICADOR	DO body {$$ = triNode(FUNCTION, nilNode(VOID), strNode(IDENTIFICADOR, $3), $5);}
	| FUNCTION VOID IDENTIFICADOR	DONE {$$ = binNode(FUNCTION, nilNode(VOID), strNode(IDENTIFICADOR, $3));}
	;

qualifier : PUBLIC {$$ = uniNode(PUBLIC, nilNode(NIL));}
	| FORWARD {$$ = uniNode(FORWARD, nilNode(NIL));}
	;

variables : variable {$$ = uniNode(VAR, $1);}
	| variables ';' variable {$$ = binNode(';', $1, $3);}
	;

variable : type IDENTIFICADOR '[' LITERAL_I ']' {$$ = triNode('[', $1, strNode(IDENTIFICADOR, $2), intNode(LITERAL_I, $4));}
	| type IDENTIFICADOR {$$ = binNode(IDENTIFICADOR, $1, strNode(IDENTIFICADOR, $2));}
	;

type : NUMBER {$$ = nilNode(NUMBER);}
	| STRING {$$ = nilNode(STRING);}
	| ARRAY {$$ = nilNode(ARRAY);}
	;

body : variables ';' instructs {$$ = binNode(';', $1, $3);}
	| variables ';' {$$ = uniNode(';', $1);}
	| instructs {$$ = uniNode(';', $1);}
	;

instructs : instruct {$$ = uniNode(';', $1);}
	| instructs instruct {$$ = binNode(';', $1, $2);}
	;

instruct : IF expression THEN instructs elifs ELSE instructs FI {$$ = quadNode(IF, $2, $4, $5, $7);}
	| IF expression THEN instructs ELSE instructs FI {$$ = triNode(IF, $2, $4, $6);}
	| IF expression THEN instructs elifs FI {$$ = triNode(IF, $2, $4, $5);}
	| IF expression THEN instructs FI {$$ = binNode(IF, $2, $4);}
	| IF expression THEN elifs FI {$$ = binNode(IF, $2, $4);}
	| IF expression THEN FI {$$ = uniNode(IF, $2);}
	| FOR expression UNTIL expression STEP expression DO instructs DONE {$$ = quadNode(FOR, $2, $4, $6, $8);}
	| expression '!' {$$ = uniNode('!', $1);}
	| expression ';' {$$ = uniNode(';', $1);}
	| literals '!' {$$ = uniNode('!', $1);}
	| REPEAT {$$ = uniNode(REPEAT, nilNode(NIL));}
	| STOP {$$ = uniNode(STOP, nilNode(NIL));}
	| RETURN expression {$$ = uniNode(RETURN, $2);}
	| RETURN {$$ = uniNode(RETURN, nilNode(NIL));}
	| expression '#' expression ';' {$$ = binNode('#', $1, $3);}
	;

elifs : elif {$$ = uniNode(' ', $1);}
	| elifs elif {$$ = binNode(' ', $1, $2);}
	;

elif : ELIF expression THEN instructs {$$ = binNode(ELIF, $2, $4);}
	;

args : expression {$$ = uniNode(',', $1);}
	| args ',' expression {$$ = binNode(',', $1, $3);}
	;

expression	: '?'  {$$ = uniNode(UINPUT, nilNode(NIL));}
	| '~' expression %prec UNEG {$$ = uniNode(UNEG, $2);}
	|	IDENTIFICADOR '(' args ')' {$$ = binNode('(', strNode(IDENTIFICADOR, $1), $3);}
	| IDENTIFICADOR {$$ = strNode(IDENTIFICADOR, $1);}
	|	literal {$$ = uniNode(LITERAL, $1);}
	| '(' expression ')' {$$ = uniNode('(', $2);}
	| expression '[' expression ']' {$$ = binNode('[', $1, $3);}
	| expression '+' expression {$$ = binNode('+', $1, $3);}
	| expression '-' expression {$$ = binNode('-', $1, $3);}
	| '-' expression %prec UMINUS {$$ = uniNode(UMINUS, $2);}
	| expression '*' expression {$$ = binNode('*', $1, $3);}
	| expression '/' expression {$$ = binNode('/', $1, $3);}
	| expression '%' expression {$$ = binNode('%', $1, $3);}
	| expression '^' expression {$$ = binNode('^', $1, $3);}
	| expression '>' expression {$$ = binNode('>', $1, $3);}
	| expression '<' expression {$$ = binNode('<', $1, $3);}
	| expression '=' expression {$$ = binNode('=', $1, $3);}
	| expression '|' expression {$$ = binNode('|', $1, $3);}
	| expression '&' expression {$$ = binNode('&', $1, $3);}
	| '&' expression %prec ULOCATION {$$ = uniNode(ULOCATION, $2);}
	| expression GE expression {$$ = binNode(GE, $1, $3);}
	| expression LE expression {$$ = binNode(LE, $1, $3);}
	| expression NE expression {$$ = binNode(NE, $1, $3);}
	| expression ATTR expression {$$ = binNode(ATTR, $1, $3);}
	;

%%

char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strdup(buf);
}

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
