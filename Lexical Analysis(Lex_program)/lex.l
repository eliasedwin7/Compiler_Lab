digit [0-9]*
letter[A-Za-z]
%%
"do"|"while"|"void"|"main"|"int"|"float"|"if"|"auto"|"else if"|"else" {printf("\n\t%s is a keyword",yytext);}
#.* {printf("\n\t%s is a Preprocessor Directive",yytext);}
("_")*{letter}({digit}|{letter}|("_"))* {printf("\n\t%s is an Identifier",yytext);}
{digit}* {printf("\n\t%s is a Digit",yytext);}
"+"|"-"|"*"|"/"|"%" {printf("\n\t%s is an Arethematic operator",yytext);}
">"|"<"|"=="|"!="|">="|"<=" {printf("\n\t%s is a Relational Operators",yytext);}
"="|"+="|"-="|"/="|"*=" {printf("\n\t%sis an Assignment Operator",yytext);}
\,|\.|\;|\:|\{|\}|\(|\)|\[|\]|\"|\' {printf("\n\t%s is a Seperator",yytext);}
%%

int main()
{
FILE *fp;
fp=fopen("input.c","r");

if(!fp)
{printf("\nFile not opned");
exit(0);
}
yyin=fp;
yylex();
printf("\n scanning compeleted\n\n");
return 0;
}
