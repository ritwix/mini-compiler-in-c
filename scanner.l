/* Authors: Ritwick Mishra, Abhilash Sanap	Date: 18-01-18*/
%{
	#include <stdio.h>
	#include <string.h>
#define SIZE 1000
void insert_hash(char *,char *,int);
void display_hash();
struct DataItem 
{
  	char* text;     		/* The token*/
  	char* type;			/* Type of the token*/
  	int lineno;			/* Line number in the input file*/
  	struct DataItem * next;		/*Pointer to next data item*/
  	int attr;			/*Attribute value of a token */
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* item;
int v=0; 				/* variable maintained to assign unique attribute value*/
%}
alpha [a-zA-Z_]
digit [0-9]

%%
[ \t]		;					/*Removes spaces and tabs */
[ \n]   { yylineno = yylineno + 1;}
int 	{ECHO; insert_hash("int","Datatype",yylineno);}
char 	{ECHO; insert_hash("char","Datatype",yylineno);}
void 	{ECHO; insert_hash("void","Datatype",yylineno);}
while	{ECHO; insert_hash("while","Keyword",yylineno);}
if		{ECHO; insert_hash("if","Keyword",yylineno);}
else	{ECHO; insert_hash("else","Keyword",yylineno);}
printf  {ECHO; insert_hash("printf","Function",yylineno);}
scanf 	{ECHO; insert_hash(yytext,"Function",yylineno);}
^"#include ".+ ;
return	{ECHO; insert_hash(yytext,"Keyword",yylineno);}
{digit}+   {ECHO; insert_hash(yytext,"Integer",yylineno);} 
{alpha}({alpha}|{digit})* {ECHO; insert_hash(yytext,"Identifier",yylineno);}



"{"     {ECHO; insert_hash("{","Sp. Char",yylineno);}
"}"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"["		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"]"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
";"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"("		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
")"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"&"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"|"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"!"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
","		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"."		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"%c"	{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"%d"	{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}
"'"		{ECHO; insert_hash(yytext,"Sp. Char",yylineno);}

	/*Operators*/
"+"		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"-"		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"*"		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"%"		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"="		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"=="	{ECHO; insert_hash(yytext,"Operator",yylineno);}
">="	{ECHO; insert_hash(yytext,"Operator",yylineno);}
"<="	{ECHO; insert_hash(yytext,"Operator",yylineno);}
">"		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"<"		{ECHO; insert_hash(yytext,"Operator",yylineno);}
"&&"	{ECHO; insert_hash(yytext,"Operator",yylineno);}
"||"	{ECHO; insert_hash(yytext,"Operator",yylineno);}
"\""	{ECHO; insert_hash(yytext,"Operator",yylineno);}
\\		{ECHO; insert_hash(yytext,"Operator",yylineno);}
	/*Comments*/
\/\/.*	;
\/\*(.*\n)*.*\*\/	;
.			{printf("\nIllegal token: %s at line no : %d\nExiting...\n\n",yytext,yylineno);
			return -1;
			}

%%


int hashCode(char* key) 			/* Returns unique index for a token */
{
   unsigned int i,hash=7;
   for(i=0;i<strlen(key);++i)
   {
       hash=hash*31+key[i];
   }
   return hash % SIZE;
}
void insert_hash(char* text,char* type,int lineno) 
{
	int len,len2;
  	len= strlen(text);
   	len2= strlen(type);

   int hashIndex = hashCode(text);
   if(hashArray[hashIndex] != NULL) 
   {	
		
		struct DataItem * head = hashArray[hashIndex];
		int temp = head->attr;
		struct DataItem * new;
		new = (struct DataItem *)malloc(sizeof(struct DataItem)); 	  
	   new-> type = (char *)malloc(len2*sizeof(char));
	   strcpy(new->type,type);
	   new->lineno= lineno;
	   new-> text = (char *)malloc(len*sizeof(char));
	   strcpy(new->text,text);
	   new->attr = temp;
    	
	   while(head->next!=NULL){
	   	head=head->next;

	   }
	   head->next =new;

	   

	      
   }

   else{
   
   hashArray[hashIndex] = (struct DataItem*)malloc(sizeof(struct DataItem));
   hashArray[hashIndex]-> type = (char *)malloc(len2*sizeof(char));
   strcpy(hashArray[hashIndex]->type,type);
   hashArray[hashIndex]-> lineno= lineno;
   hashArray[hashIndex]-> text = (char *)malloc(len*sizeof(char));
   strcpy(hashArray[hashIndex]->text,text);
   hashArray[hashIndex]->next = NULL;
   hashArray[hashIndex]->attr = v++;
}
}
void display_hash() 
{
   int i = 0;
  printf("Lexeme\t\tType\t\tLineno\t\tAttribute value\n"); 
   for(i = 0; i<SIZE; i++) 
   {
      if(hashArray[i] != NULL){
        struct DataItem * head = hashArray[i];
        printf("%s\t\t%s\t\t%d\t\t%d\n",head->text,head->type,head->lineno,head->attr);
        while(head->next!=NULL){
        	head=head->next;
        	printf("%s\t\t%s\t\t%d\t\t%d\n",head->text,head->type,head->lineno,head->attr);
        }
        
      }
  
  
      
   }
  
   printf("\n");
}



int main(int argc, char * argv){
	yyin = fopen(argv,"r");
	printf("Stream of tokens:\n\n");
	yylex();
	printf("\n\n\t\tSYMBOL TABLE\n");
	display_hash();
	return 0;
}
int yywrap(){
	return 1;
}
