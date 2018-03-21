%{
	#include <string.h>
	#include <stdlib.h>
	char idname[1000];
%}
alpha [a-zA-Z_]
digit [-]?[0-9]
charlit [a-zA-Z0-9]
%%
[ \t]		;					/*Removes spaces and tabs */
[ \n]   { yylineno = yylineno + 1;}
int 	{ return INT;}
char 	{return CHAR;}
void    {return VOID;}
while	{  return WHILE;}
if		{  return IF;}
else	{ return ELSE;}
printf  { return PRINTF;}
scanf 	{ return SCANF;}
break	{ return BREAK;}
^"#include ".+ ;
return	{ return RETURN;}
{digit}+   {yylval=atoi(yytext); return NUM;}
\'{charlit}\'			{	 return CHLIT;}  
{alpha}({alpha}|{digit})* { strcpy(idname,yytext); return ID;}



"{"     { 	return LBRACE;}
"}"		{    return RBRACE;}
"["     {    return LSQ;}
"]"		{    return RSQ;}
";"		{    return SEMICOLON;}
"("		{    return LPAREN;}
")"		{    return RPAREN;}
"&&"	{     return DAND;}
"||"	{     return DOR;}
"&"		{    return AND;}
"|"		{    return OR;}
"!"		{    return NOT;}
","		{    return COMMA;}
"."		{    return DOT;}
"'"		{    return QM;}

	/*Operators*/
"+"		{ return ADD;}
"-"		{ return SUB;}
"*"		{ return MUL;}
"%"		{ return MOD;}
"/"		{     return DIV;}
"=="	{     return ISEQ;}
"!="	{     return NEQ;}
"="		{     return ASSIGN;}
">="	{     return GEQ;}
"<="	{     return LEQ;}
">"		{     return GT;}
"<"		{     return LT;}

\"(\\.|[^\\"])*\"	{return STRINGLIT;}

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