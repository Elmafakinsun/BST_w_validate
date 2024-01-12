%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "y.tab.h"
int yylex(void);
extern FILE *yyin;
void yyerror(char *);
%}

%start Statements
%token NUMBER
%token POW
%token SQRT
%token MOD
%token LSHIFT RSHIFT
%left '+' '-'
%left '*' '/'
%right POW
%left MOD
%left LSHIFT RSHIFT

%%

Expr : Expr '+' Expr
     {
         $$ = $1 + $3;
     }
     | Expr '-' Expr
     {
         $$ = $1 - $3;
     }
     | Expr '*' Expr
     {
         $$ = $1 * $3;
     }
     | Expr '/' Expr
     {
         if ($3 != 0) {
             $$ = $1 / $3;
         } else {
             fprintf(stderr, "Error: División por cero\n");
             exit(1);
         }
     }
     | Expr POW Expr
     {
         int result = 1;
         for (int i = 0; i < $3; i++) {
             result *= $1;
         }
         $$ = result;
     }
     | SQRT Expr
     {
         $$ = sqrt($2);
     }
     | Expr MOD Expr
     {
         $$ = $1 % $3;
     }
     | Expr LSHIFT Expr
     {
         $$ = $1 << $3;
     }
     | Expr RSHIFT Expr
     {
         $$ = $1 >> $3;
     }
     | '|' Expr '|'
     {
         $$ = fabs($1);
     }
     | '(' Expr ')'
     {
         $$ = $2;
     }
     | NUMBER
     {
         $$ = $1;
     }
     ;

Statement : Expr
          {
              printf("%d \n", $1);
          }
          ;

Statements :
           | Statements Statement '='
           ;

%%

int main ()
{
	 FILE *file = fopen("ope.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
	char buffer[1024];  
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
		yy_scan_string(buffer);
		printf("%s", buffer);
		yyparse();
    }
	printf("%s", "\n");


}

void yyerror(char *s)
{
   // fprintf(stderr, "%s\n", s);
}

int yywrap()
{
    return 1;
}