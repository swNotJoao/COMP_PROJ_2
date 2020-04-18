%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"

char *dupstr(const char *s);
extern void yyerror(const char *msg);
int has_program = 0;
int trash = 1;

%}

%x ACTUAL_PROGRAM TRASH

%%
  if(trash){
    BEGIN TRASH;
  }
  else{
    BEGIN ACTUAL_PROGRAM;
  }

<ACTUAL_PROGRAM>{
\$\$.*			;
\$([^\$]|\$\$)*\$	;

"program" {if(has_program == 0){has_program = 1; return PROGRAM;} return IDENTIFICADOR;};
"module" return MODULE;
"start" return START;
"end" {trash = 1; return END;}
"void" return VOID;
"const" return CONST;
"number" return NUMBER;
"array" return ARRAY;
"string" return STRING;
"function" return FUNCTION;
"public" return PUBLIC;
"forward" return FORWARD;
"if" return IF;
"then" return THEN;
"else" return ELSE;
"elif" return ELIF;
"fi" return FI;
"for" return FOR;
"until" return UNTIL;
"step" return STEP;
"do" return DO;
"done" return DONE;
"repeat" return REPEAT;
"stop" return STOP;
"return" return RETURN;
":=" return ATTR;
">=" return GE;
"<=" return LE;
"~=" return NE;

[A-Za-z][A-Za-z0-9_]*	{yytext[yyleng-1] = 0; yylval.s = dupstr(yytext+1); return IDENTIFICADOR;}
\"(\\[A-Za-z0-9\\\"][A-Za-z0-9]?|[^"\\])*\"		{yytext[yyleng-1] = 0; yylval.s = dupstr(yytext+1); return LITERAL_S;}
\'(\\[A-Za-z0-9\\\'][A-Za-z0-9]?|[^'\\])\'		{yytext[yyleng-1] = 0; yylval.s = dupstr(yytext+1); return LITERAL_C;}
[1-9][0-9]*			{yylval.i = strtol(yytext, 0, 10); return LITERAL_I;}
0b[01]+ {yylval.i =  strtol(yytext, NULL, 2); return LITERAL_I;}
0x[0-9a-fA-F]+ {yylval.i =  strtol(yytext, NULL, 16); return LITERAL_I;}
0[0-7]+ {yylval.i =  strtol(yytext, NULL, 8); return LITERAL_I;}
0 {yylval.i = 0; return LITERAL_I;}
[-()<>=+*/%^;{}.,!?|&~\[\]#]	return *yytext;

[ \t\n\r]+		;

.			yyerror("Unknown Character");
}

<TRASH>{
"program"[ \n\r\t] {trash = 0; has_program = 1; if(has_program == 1){} return PROGRAM;};
"module"[ \n\r\t] {trash = 0; if(has_program == 1){} return MODULE;};

.|\n ;
}

%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
