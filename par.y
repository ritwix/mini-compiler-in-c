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
void getidtype(char *);
int gdim=0;  
char * typ, * op1,* op2; 
int flg=0; 
%}
%token ID NUM CHLIT STRINGLIT INT VOID CHAR UMINUS
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
expr: identifier	{flg=0;}  
| NUM {flg=1;}
| CHLIT	{flg=2;}
| identifier ASSIGN {getidtype(idname) ;  if(strcmp(typ,"int")!=0) {printf("LHS of assignment should be int in line %d",yylineno); return -1;} } expr 
| arrid expr RSQ	
| arrid expr RSQ ASSIGN expr 
| arrid expr RSQ ASSIGN funcall
| expr ADD{
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr	{
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr SUB {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr MUL {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr DIV {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr GEQ {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr LEQ {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr GT {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr LT {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr ISEQ {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| expr NEQ {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
} expr {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
| LPAREN expr RPAREN
| SUB expr 		%prec UMINUS
{
	if(flg!=1){
		printf("Invalid operand in line %d",yylineno);
		return -1;
	}
}
;
identifier: ID
{	
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
				else gdim=temp->arrdim;
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
   int i=0;
   for (i = scopesLength-1; i>=0; i--)
        if (scopes[i] == scope)
            return 1;
   return 0;
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
void getidtype(char * key){
	
		if(hash_lookup_scope(key)==1){
			int hashIndex=hashCode(key);
			struct DataItem * temp = hashArray[hashIndex];
			while(temp!=NULL){
				if(strcmp(temp->text,key)==0){
					int sc=temp->scope;
					if(isScopeValid(sc)==1){
						
						typ=(char *)malloc(sizeof(char)*strlen(temp->type));
						strcpy(typ,temp->type);
						
					}
				}
				temp=temp->next;
			}
		}
		


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

