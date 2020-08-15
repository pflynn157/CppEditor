%{
#include <stdio.h>
#include <string>

#include "parser.yy.hpp"
%}

%%
#.*							{return COMMENT;}
\"(\\.|[^"\\])*\" 			{yylval.stype = strdup(yytext); return STRING;}
[-]?[0-9]+					{yylval.itype = std::stoi(yytext); return INTEGER;}
[-]?([0-9]*[.])?[0-9]+		{yylval.ftype = std::stof(yytext); return FLOAT;}
("{"|"<:")					{return '{';}
("}"|":>")					{return '}';}
.							{return WHATEVER;}
%%

int yywrap() { return 1; }
