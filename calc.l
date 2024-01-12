%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(char *);
%}

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"("             { return '('; }
")"             { return ')'; }
"|"             { return '|'; }
"="             { return '='; }
"\*\*"          { return POW; }
"sqrt"          { return SQRT; }
"mod"           { return MOD; }
"<<"            { return LSHIFT; }
">>"            { return RSHIFT; }
\n               /* Ignorar el salto de línea, no devuelve ningún token */

%%


