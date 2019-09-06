
%{

#include<stdio.h>
#include<stdlib.h>

%}

%token num id op

%%
start : id '=' s ';'
s : id x| num x| '-' num x| '(' s ')' x;

x : op s| '-' s|;

%%

int yyerror(){
printf("\nInvalid!!!!!\n");
exit(0);
}

int main(){
printf("\nEnter expression:\n");
yyparse();
printf("\nValid\n");
}

