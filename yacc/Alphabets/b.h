
%{

	#include<stdio.h>
	#include<stdlib.h>

%}

%token digit letter

%%
	S :A;
	A:letter B|letter;
	B:letter B|digit B|letter|digit;

%%



int main(){
	printf("\nEnter expression:\n");
	yyparse();
	printf("\nValid\n");
}

int yyerror(){
	printf("\nInvalid!!!!!\n");
	exit(0);
}

