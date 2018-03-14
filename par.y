%{
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *fp;
   
    int yylex(void);    
    void yyerror(char*);
    #define SIZE 1000
    void insert_hash(char *,char *,int);
    void display_hash();
    struct DataItem 
    {
        char* text;             /* The token*/
        char* type;         /* Type of the token*/
        int lineno;         /* Line number in the input file*/
        struct DataItem * next;     /*Pointer to next data item*/
        int attr;           /*Attribute value of a token */
    };
    struct DataItem* hashArray[SIZE]; 
    struct DataItem* item;
    int v=0;                /* variable maintained to assign unique attribute value*/
%}
%token ID NUM STRINGLIT INT SINT LINT UINT CHAR VOID
%token IF ELSE WHILE BREAK SCANF PRINTF RETURN MAIN
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA DOT SQ
%token AND NOT OR 
%token ADD SUB MUL DIV MOD ASSIGN
%token ISEQ GT LT GEQ LEQ DAND DOR NEQ
%left ADD SUB
%left MUL DIV
%left GT LT GEQ LEQ ISEQ NEQ
%left AND OR
%left DAND DOR
%right ASSIGN
%left ELSE
%start program
%%
program: declist funclist
| funclist
;
declist: declist declstmt 
| declstmt
;
declstmt: INT ID assign COMMA ID assign SEMICOLON
| INT ID assign SEMICOLON
;
assign: ASSIGN expr
| 
;
funclist: funclist funcdecl
| funcdecl
;
funcdecl: INT ID LPAREN arglist RPAREN compstmt
|	VOID ID LPAREN arglist RPAREN compstmt
;
arglist: INT ID COMMA INT ID
| INT ID
| 
;

compstmt: LBRACE stmtlist RBRACE
;
stmtlist: stmtlist stmt
| stmt
;
stmt: declaration
| funcall
| whilestmt
| ifstmt
| returnstmt
| printstmt
| scanstmt
| SEMICOLON
;
declaration: INT ID assign COMMA ID assign SEMICOLON
| INT ID assign
| error SEMICOLON
;
funcall: ID LPAREN expr COMMA expr RPAREN SEMICOLON
| ID LPAREN expr RPAREN SEMICOLON
| ID LPAREN RPAREN SEMICOLON
;
whilestmt: WHILE LPAREN expr RPAREN compstmt
| WHILE LPAREN expr RPAREN stmt
;
ifstmt: IF LPAREN expr RPAREN compstmt
| IF LPAREN expr RPAREN compstmt ELSE compstmt
| IF LPAREN expr RPAREN stmt
;
returnstmt: RETURN expr SEMICOLON
| RETURN SEMICOLON
;
printstmt: PRINTF LPAREN STRINGLIT RPAREN SEMICOLON
| PRINTF LPAREN STRINGLIT COMMA ID RPAREN SEMICOLON
| PRINTF LPAREN STRINGLIT COMMA ID COMMA ID RPAREN SEMICOLON
;
scanstmt: SCANF LPAREN STRINGLIT RPAREN SEMICOLON
| SCANF LPAREN STRINGLIT COMMA AND ID RPAREN SEMICOLON
| SCANF LPAREN STRINGLIT COMMA AND ID COMMA AND ID RPAREN SEMICOLON
;
expr: ID
| NUM
| ID ASSIGN expr
| ID ASSIGN funcall
| expr ADD expr
| expr SUB expr
| expr MUL expr
| expr DIV expr
| expr GEQ expr
| expr LEQ expr
| expr GT expr
| expr LT expr
| expr ISEQ expr
| expr NEQ expr
| LPAREN expr RPAREN
;







%%
#include"lex.yy.c"
#include<ctype.h>
int count=0;
int hashCode(char* key)             /* Returns unique index for a token */
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
     struct DataItem * node = head;
       if(!strcmp(head->text,text))
        new->attr = temp;
     else{
        while(node!=NULL && strcmp(text,node->text)!=0){
          node=node->next;
        }
        if(node==NULL)
          new->attr=v++;
        else{
          new->attr=node->attr;
        }
     }
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
int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
   
   if(!yyparse())
        printf("\nParsing complete!\n");
    else
        printf("\nParsing failed!\n");
    printf("\n SYMBOL TABLE\n");
    display_hash();
    fclose(yyin);
    return 0;
}
         
void yyerror(char *s) {
    printf("Line %d : %s before '%s'\n", yylineno, s, yytext);
}

