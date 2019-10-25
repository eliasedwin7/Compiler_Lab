%{
	#include<stdio.h>
	#include<math.h>
	


%}

%token number

%left '+''-'
%left '*''/''%'
%right '^'
%left '('')'


%%

ArethematicExpression:E {printf("\Result: %d\n",$$);
			 return 0;
			};
E:E'+'E {$$=$1+$3;}
  |E'^'E {$$=pow($1,$3);}
  |'-'E {$$=-$2;}
  |E'-'E {$$=$1-$3;}
  |E'*'E {$$=$1*$3;}
  |E'/'E {if($3!=0){$$=$1/$3;}else{ printf("\n Divsion by Zero\n"); return 0;}}
  |E'%'E {$$=$1%$3;}
  |'('E')'{$$=$2;}
  |number{$$=$1;}
 ;

%%

int main(void)
{
printf("\n Enter expression: ");
yyparse();

}
void yyerror(){
printf("\nNot vaild Expression...");

}
