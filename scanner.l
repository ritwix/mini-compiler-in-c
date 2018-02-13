/* Authors: Ritwick Mishra, Abhilash Sanap	Date: 18-01-18*/
%{
	#include <stdio.h>
	#include <string.h>

%}
alpha [a-zA-Z_]
digit [0-9]

%%
[ \t]		;					/*Removes spaces and tabs */
[ \n]   { yylineno = yylineno + 1;}
int 	{ insert_hash("int","Datatype",yylineno); yylval=atoi(yytext);return INT;}
"unsigned int" 	{ insert_hash(yytext,"Datatype",yylineno); yylval=atoi(yytext);return UINT;}
"short int"  	{ insert_hash(yytext,"Datatype",yylineno); yylval=atoi(yytext);return SINT;}
"long int"		{ insert_hash(yytext,"Datatype",yylineno); yylval=atoi(yytext);return LINT;} 
char 	{ insert_hash("char","Datatype",yylineno); return CHAR;}
void 	{ insert_hash("void","Datatype",yylineno); return VOID;}
while	{ insert_hash("while","Keyword",yylineno); return WHILE;}
if		{ insert_hash("if","Keyword",yylineno); return IF;}
else	{ insert_hash("else","Keyword",yylineno); return ELSE;}
main 	{ insert_hash(yytext,"Keyword",yylineno); return MAIN;}
printf  { insert_hash("printf","Function",yylineno); return PRINTF;}
scanf 	{ insert_hash(yytext,"Function",yylineno); return SCANF;}
break	{ insert_hash(yytext,"Function",yylineno); return BREAK;}
^"#include ".+ ;
return	{ insert_hash(yytext,"Keyword",yylineno); return RETURN;}
{digit}+   { insert_hash(yytext,"Integer",yylineno); return NUM;} 
{alpha}({alpha}|{digit})* { insert_hash(yytext,"Identifier",yylineno); return ID;}



"{"     { insert_hash("{","Sp. Char",yylineno); return LBRACE;}
"}"		{ insert_hash(yytext,"Sp. Char",yylineno); return RBRACE;}

";"		{ insert_hash(yytext,"Sp. Char",yylineno); return SEMICOLON;}
"("		{ insert_hash(yytext,"Sp. Char",yylineno); return LPAREN;}
")"		{ insert_hash(yytext,"Sp. Char",yylineno); return RPAREN;}
"&&"	{ insert_hash(yytext,"Operator",yylineno); return DAND;}
"||"	{ insert_hash(yytext,"Operator",yylineno); return DOR;}
"&"		{ insert_hash(yytext,"Sp. Char",yylineno); return AND;}
"|"		{ insert_hash(yytext,"Sp. Char",yylineno); return OR;}
"!"		{ insert_hash(yytext,"Sp. Char",yylineno); return NOT;}
","		{ insert_hash(yytext,"Sp. Char",yylineno); return COMMA;}
"."		{ insert_hash(yytext,"Sp. Char",yylineno); return DOT;}

"'"		{ insert_hash(yytext,"Sp. Char",yylineno); return SQ;}

	/*Operators*/
"+"		{ insert_hash(yytext,"Operator",yylineno); return ADD;}
"-"		{ insert_hash(yytext,"Operator",yylineno); return SUB;}
"*"		{ insert_hash(yytext,"Operator",yylineno); return MUL;}
"%"		{ insert_hash(yytext,"Operator",yylineno); return MOD;}
"/"		{ insert_hash(yytext,"Operator",yylineno); return DIV;}
"=="	{ insert_hash(yytext,"Operator",yylineno); return ISEQ;}
"!="	{ insert_hash(yytext,"Operator",yylineno); return NEQ;}
"="		{ insert_hash(yytext,"Operator",yylineno); return ASSIGN;}
">="	{ insert_hash(yytext,"Operator",yylineno); return GEQ;}
"<="	{ insert_hash(yytext,"Operator",yylineno); return LEQ;}
">"		{ insert_hash(yytext,"Operator",yylineno); return GT;}
"<"		{ insert_hash(yytext,"Operator",yylineno); return LT;}

\"(\\.|[^\\"])*\"	{ insert_hash(yytext,"String Literal",yylineno); return STRINGLIT;}

	/*Comments*/
\/\/.*	;
\/\*(.*\n)*.*\*\/	;
.			{printf("\nIllegal token: %s at line no : %d\nExiting...\n\n",yytext,yylineno);
			return -1;
			}

%%
int yywrap(){
	return 1;
}
