%{
#include <stdio.h>

extern FILE *yyin;

int yylex();
void yyerror(const char *s);
%}

%union {
	char* stype;
	int itype;
	float ftype;
}

%token COMMENT
%token <itype> INTEGER 
%token <ftype> FLOAT
%token <stype> STRING
%token WHATEVER

%%
all_statements: statement all_statements | /* empty */;

statement:
	  comment
	| number
	| string
	| block
	| something
	;
	
comment:
	  statement COMMENT			{printf("Comment!\n");}
	;
	
number:
	  statement INTEGER			{printf("Integer: %d\n", $2);}
	| statement FLOAT			{printf("Float: %f\n", $2);}
	| /* empty */
	;
	
string:
	  statement STRING			{printf("String: %s\n", $2);}
	;
	
block:
	  statement '{'				{printf("Block begin\n");}
	| statement '}'				{printf("Block end\n");}
	;
	
something:
	  statement WHATEVER		{printf("What??\n");}
	;
%%

//Our parsing function
void parse(const char *path) {
	yyin = fopen(path, "r");
	yyparse();
}

//Handle syntax errors
void yyerror(const char *s) {
	printf("Syntax error: %s\n", s);
}

int yywrap() { return 1; }
