%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    char * typ;
    extern FILE *fp;
    extern char idname[1000];
    extern int yylineno;
    int yylex(void);
    int dim=0;    
    void yyerror(char*);
    #define SIZE 1000
    int hashCode(char* key);
    void insert_hash(char *,char *,int,int,int, char *);
    void display_hash();
    struct DataItem 
    {
        char* text;             /* The token*/
        char* type;         /* Type of the token*/
        int scope;
        int lineno;         /* Line number in the input file*/
        int arrdim;
        char* retype;
     	
        struct DataItem * next;     /*Pointer to next data item*/
    };
    struct DataItem* hashArray[SIZE]; 
    struct DataItem* item;
    int scopes[1000];
int scopesLength = 1;
int scopeCounter = 1;
int getCurrentScope();
void startNewScope();
void endCurrentScope();
int isScopeValid(int);
int hash_lookup_scope(char * key);
    
%}
%token ID NUM STRINGLIT INT VOID CHAR UMINUS
%token IF ELSE WHILE BREAK SCANF PRINTF RETURN
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA DOT LSQ RSQ QM
%token AND NOT OR 
%token ADD SUB MUL DIV MOD ASSIGN
%token ISEQ GT LT GEQ LEQ DAND DOR NEQ 
%left ADD SUB
%left MUL DIV
%left GT LT GEQ LEQ ISEQ NEQ
%left AND OR
%left DAND DOR
%right UMINUS
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

declstmt: INT intid assign COMMA intid  assign SEMICOLON  
|INT intid  assign SEMICOLON
|CHAR cid assign COMMA cid  assign SEMICOLON  
|CHAR cid  assign SEMICOLON
| declarray
;
intid: ID 
{
	
	insert_hash(idname,"int",getCurrentScope(),yylineno,0,"NA");	

}
;
cid: ID 
{
	insert_hash(idname,"char",getCurrentScope(),yylineno,0,"NA");

}
;
assign: ASSIGN expr
| 
;
funclist: funclist funcdecl
| funcdecl
;
funcdecl: INT ifid INT intid COMMA INT intid RPAREN compstmt
| INT ifid INT intid RPAREN compstmt
| INT ifid RPAREN compstmt
| VOID vfid INT intid COMMA INT intid RPAREN compstmt
| VOID vfid LPAREN INT intid RPAREN compstmt
| VOID vfid LPAREN RPAREN compstmt
;
ifid: ID LPAREN
{
	insert_hash(idname,"function",getCurrentScope(),yylineno,0,"int");
}
;
vfid: ID LPAREN
{
	insert_hash(idname,"function",getCurrentScope(),yylineno,0,"void");
}
;
compstmt: block_start stmtlist block_end
;
block_start: LBRACE 
{
	startNewScope();
	//printf("%d\n",getCurrentScope());
}
block_end: RBRACE
{
	endCurrentScope();
	
}
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
| expr
| SEMICOLON
;
declaration: INT intid assign COMMA intid  assign SEMICOLON  
|INT intid  assign SEMICOLON
|CHAR cid assign COMMA cid  assign SEMICOLON  
|CHAR cid  assign SEMICOLON
| declarray
;
funcall: fc expr COMMA expr RPAREN SEMICOLON
| fc expr RPAREN SEMICOLON
| fc RPAREN SEMICOLON
;
fc: ID LPAREN
{
	int hashIndex = hashCode(idname);
	int flag=0;
	if(hashArray[hashIndex]!=NULL){
	struct DataItem * temp = hashArray[hashIndex];

	while(temp!=NULL){
		if(strcmp(temp->text,idname)==0 && strcmp(temp->type,"function")==0){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	}
	if(flag==0){
		printf("Undefined function: '%s' in line %d\n",idname,yylineno);
	}
	
}
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
expr: identifier 
| NUM
| identifier ASSIGN expr
| identifier ASSIGN funcall
| arrid expr RSQ
| arrid expr RSQ ASSIGN expr
| arrid expr RSQ ASSIGN funcall
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
| SUB expr 		%prec UMINUS
;
identifier: ID
{	
		printf("heelo\n");
		if(hash_lookup_scope(idname)==0){
			printf("Undeclared Variable: '%s' in line %d\n",idname,yylineno);
			return -1;
		}
}
;
arrid: ID LSQ
{	

	if(hash_lookup_scope(idname)==0){
		printf("Undeclared Variable: '%s' in line %d\n",idname,yylineno);
		return -1;
	}
	int hashIndex = hashCode(idname);
	int f=0;
	struct DataItem * temp = hashArray[hashIndex];

	while(temp!=NULL){
		if(strcmp(temp->text,idname)==0){
			int sc=temp->scope;
			if(isScopeValid(sc)==1){
				if(strcmp(temp->type,"array")!=0){
					f=1;
				}
			}
				
		}
		temp=temp->next;
	}
	if(f==1){
		printf("Single variable id or function has subscript\n");
		return -1;
	}
	
return 0;

}
;
declarray:  INT ID LSQ NUM RSQ SEMICOLON 
{
	dim = $4;
	if(dim<1){
		printf("Array size less than 1\n");
		return -1;
	}
	insert_hash(idname,"array",getCurrentScope(),yylineno,dim,"NA");
}
;







%%
#include"lex.yy.c"
#include<ctype.h>
int count=0;
int getCurrentScope () 
{
    return scopes[scopesLength - 1];
}

void startNewScope () 
{
   scopes[scopesLength++] = scopeCounter++;
}

void endCurrentScope () 
{
    scopesLength--;
}

int isScopeValid (int scope)
{
   for (int i = scopesLength-1; i>=0; i--)
        if (scopes[i] == scope)
            return 1;
   return 0;
}

int hashCode(char* key)             /* Returns unique index for a token */
{
   unsigned int i,hash=7;
   for(i=0;i<strlen(key);++i)
   {
       hash=hash*31+key[i];
   }
   return hash % SIZE;
}
void insert_hash(char* text,char* type,int scope, int lineno,int dim, char* retype) 
{
    int len,len2,len3;
    len= strlen(text);
    len2= strlen(type);
    len3 = strlen(retype);
    
   int hashIndex = hashCode(text);
   if(hashArray[hashIndex]!=NULL){
   		struct DataItem * temp = hashArray[hashIndex];
   		while(temp!=NULL){
		if(strcmp(temp->text,text)==0){
			int sc=temp->scope;
			if(sc==scope)
				{printf("Multiple declarations: '%s' in line %d\nVariable already declared in line %d\n\n",text,lineno,temp->lineno);
				return;
				}
		}
		temp=temp->next;
	}

   }
   		struct DataItem * new;
        new = (struct DataItem *)malloc(sizeof(struct DataItem));     
        new-> type = (char *)malloc(len2*sizeof(char));
        strcpy(new->type,type);
        new->lineno= lineno;
        new-> text = (char *)malloc(len*sizeof(char));
        strcpy(new->text,text);
        new->retype = (char*)malloc(len3*sizeof(char));
        strcpy(new->retype,retype);
        new->arrdim=dim;
        new->scope=scope;
       
        

        new->next= NULL;


   if(hashArray[hashIndex] != NULL) 
   {    //chaining

        struct DataItem * head = hashArray[hashIndex];
        new->next=head;
        hashArray[hashIndex]=new;
       
   }
   else{

   
   hashArray[hashIndex] = new;
}
}
void display_hash() 
{
   int i = 0;
  printf("Lexeme\t\tType\t\tScope\t\tLineno\t\tArrdim\t\tReturntype\n"); 
   for(i = 0; i<SIZE; i++) 
   {
      if(hashArray[i] != NULL){
        struct DataItem * head = hashArray[i];
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%s\n",head->text,head->type,head->scope,head->lineno,head->arrdim,head->retype);
        while(head->next!=NULL){
            head=head->next;
              printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%s\n",head->text,head->type,head->scope,head->lineno,head->arrdim,head->retype);
        }      
      }
   }
  
   printf("\n");
}
int hash_lookup_scope(char * key)
{
int hashIndex = hashCode(key);
if(hashArray[hashIndex]!=NULL){
	struct DataItem * temp = hashArray[hashIndex];

	while(temp!=NULL){
		if(strcmp(temp->text,key)==0){
			int sc=temp->scope;
			if(isScopeValid(sc)==1)
				return 1;
		}
		temp=temp->next;
	}
	}
return 0;
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

