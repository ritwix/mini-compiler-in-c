%{
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;
    extern int yylineno;
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
%left GT LT GEQ LEQ ISEQ
%left AND OR
%left DAND DOR
%right ASSIGN
%left ELSE
%start program

%%
program:     declist main funcdef           /* declist stands for global variable declaration and/or function declaration before main */
        ;                                   /* funcdef stands for function definitions present after main() function */
declist:    declist functiondecl
        |   declist declaration
        |   %empty
        ;
functiondecl: INT ID LPAREN argdecls1  RPAREN SEMICOLON             
            | VOID ID LPAREN argdecls1 RPAREN SEMICOLON
            | CHAR ID LPAREN argdecls1 RPAREN SEMICOLON
            ;
argdecls1: argdecls1 COMMA dt          /* Arguments should be of form (int,int) instead of (int a, int b) in function declaration */
|           dt
|           %empty

funcdef:    funcdef function
|           %empty             
;

main:   INT MAIN LPAREN argdecls RPAREN compstmt
    |   VOID MAIN LPAREN argdecls RPAREN compstmt
    ;
function:        INT ID LPAREN argdecls RPAREN compstmt
        |        VOID ID LPAREN argdecls RPAREN compstmt
        |        CHAR ID LPAREN argdecls RPAREN compstmt
;

declaration:     declstmt SEMICOLON
|                expr SEMICOLON
|                funcall SEMICOLON
|                error SEMICOLON
|                error RBRACE 
|                error RPAREN
;

declstmt:        INT decllist
|                CHAR decllist
;

decllist:        decllist COMMA ID declassign  /* handles int a,b,c; case by left recursion of decllist */
|                ID declassign
;

declassign:            ASSIGN expr
|                %empty
;
compstmt:        LBRACE stmtlist  RBRACE    
|                %empty
;

stmtlist:        stmtlist stmt
|                %empty
;

/*Dangling if-else problem*/

stmt:            matched_stmt
|                unmatched_stmt
;
matched_stmt:   IF LPAREN expr  RPAREN matched_stmt ELSE matched_stmt
|               compstmt                        
|               whilestmt
|               returnstmt
|               declaration
|               print
|               scan
|               SEMICOLON
;                         
unmatched_stmt:  IF LPAREN expr RPAREN stmt
|               IF LPAREN expr RPAREN matched_stmt ELSE unmatched_stmt
;

whilestmt:        WHILE '(' expr ')' stmt
;

returnstmt:      RETURN SEMICOLON 
|                RETURN expr SEMICOLON
;

funcall:       ID LPAREN mult RPAREN            
;

mult:           const COMMA mult
|               const
|               %empty
;

const:            NUM | ID;

print      :        PRINTF LPAREN STRINGLIT RPAREN SEMICOLON
|                   PRINTF LPAREN STRINGLIT numlist RPAREN SEMICOLON
;

scan      :         SCANF LPAREN STRINGLIT snumlist RPAREN SEMICOLON
;

argdecls:        argdecls COMMA dt ID argassign 
|                dt ID argassign
|                %empty
;

dt:             INT 
|               CHAR 
;

argassign:        '=' NUM
|                %empty
;


snumlist:        COMMA AND ID snumlist  
|                COMMA AND ID
;

numlist:        COMMA ID numlist
|               COMMA ID
;

expr :           LPAREN expr RPAREN
|                expr ADD expr
|                expr SUB expr
|                expr MUL expr
|                expr DIV expr
|                expr MOD expr
|                NOT expr
|                expr ISEQ expr
|                expr NEQ expr
|                expr GEQ expr
|                expr LEQ expr
|                expr LT expr
|                expr GT expr               
|                ID ASSIGN expr
|                ID ASSIGN funcall
|                '-' expr               /* Negative numbers */
|                ID
|                NUM
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
