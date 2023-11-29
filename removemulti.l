%{
#include <stdio.h>
%}

%option noyywrap

%%
\/\*(.|\n)*?\*\/ 
\n   { printf("%s",yytext);}
%%


int main() {
    yylex();
	printf("\n");	
    return 0;
}

 
