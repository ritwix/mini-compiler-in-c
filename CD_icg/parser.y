%{
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "codegen.cpp"

	int yylex(void);
	void yyerror(char *);

    extern FILE* yyin;
	extern int linecount;
	extern int commentflag;
	int flagarr = 0;
	int error;
	int type;
	int flag = -1;
	int flagassign = 0;
	extern char* yytext;


%}

%token _GREAT_EQ _LESS_EQ _LOGIC_OR _LOGIC_AND _NOT_EQ _EQUAL _INCR_1 _DECR_1 _CONSTANT _INCR_VAL _DECR_VAL _MULT_VAL _DIV_VAL _MOD_VAL _DO _ELSE _FOR _IF _PRINT _SCAN _WHILE _HEADER _PREPROC _STRING _RETURN

%union
{
	int number;
    char str[10000];
}


%token<str> _IDENTIFIER _MAIN _INT _CHAR _VOID
%type<str> type_specifier

%start global

%left ','
%right '=' _INCR_VAL _DECR_VAL _MULT_VAL _DIV_VAL MOD_VAL
%left _LOGIC_AND _LOGIC_OR
%left '>' '<' _GREAT_EQ _LESS_EQ
%left _EQUAL _NOT_EQ
%left '+' '-'
%left '*' '/' '%'
%left '(' ')' _INCR_1 _DECR_1

%%

global : _PREPROC _HEADER funcdec
       ;

funcdec : funcdec_ mainfunc
	    | funcdec_ mainfunc funcdec_
		| mainfunc funcdec_
        ;

mainfunc :  main '{' body '}'
		 {
			disp(s.top());
			if(!s.empty())
				s.pop();
		 }
		 ;

funcdec_ : functiondec '{' body '}'
		 {
			disp(s.top());
			if(!s.empty())
				s.pop();
		 }
		 | declaration
		 | funcdec_ functiondec '{' body '}'
         {
			disp(s.top());
			if(!s.empty())
			s.pop();
		 }
		 | funcdec_ declaration
		 ;

declaration : type_specifier declist ';'
            ;

type_specifier
 : _INT
 {
 	flag = 3;
 	strcpy($<str>$,"INTEGER_VARIABLE");
 }
 | _CHAR
 {
 	strcpy($<str>$,"CHAR_VARIABLE");
 	flag = 4;
 }
 | _VOID
 {
 	strcpy($<str>$,"VOID_VARIABLE");
 	flag = 5;
 }
 ;

declist : declist ',' pointer _IDENTIFIER optional '=' expression
		{
			table = s.top();
			token = $4;
			if(flagarr == 0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = $<str>5;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
			operands.push($<str>4);
			printTACasgn();
		}
		| declist ',' pointer _IDENTIFIER optional '=' funccall_statement
		{
			table = s.top();
			token = $4;
			if(flagarr == 0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = $<str>5;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
		}

  		| declist ',' pointer _IDENTIFIER optional
  		{
			table = s.top();
  			token = $4;
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = $<str>5;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
  		}
		| pointer _IDENTIFIER optional
		{
			table = s.top();
			token = $2;
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = $<str>3;
				int i;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
			operands.push($<str>2);
			disp(table);
		}
		| pointer _IDENTIFIER optional '=' expression
		{
			table = s.top();
			token = $2;
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = $<str>3;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
			operands.push($<str>2);
			printTACasgn();
		}
		| pointer _IDENTIFIER optional '=' funccall_statement
		{
			table = s.top();
			token = $2;
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = $<str>3;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
		}
		;

pointer
 : '*'
 |
 ;

optional
 : '[' ']'
 {
 	flagarr = 1;
 }
 | '[' _CONSTANT ']'
 {
 	flagarr = 1;
 }
 | '[' _CONSTANT ']' '[' _CONSTANT ']'
 {
 	flagarr = 2;
	int num = $<number>5;
	int i;
	char tempS[100];
	int k = 0;
	if(num == 0)
	{
		tempS[k++] = '0';
	}
	while(num!=0)
	{
		int r = num % 10;
		tempS[k++] = '0' + r;
		num /= 10;
	}
	tempS[k] = '\0';
	char tempC;
	for(i = 0; i < (k / 2); i++)
	{
		tempC = tempS[i];
		tempS[i] = tempS[k - i - 1];
		tempS[k - i - 1] = tempC;
	}
	strcpy($<str>$, tempS);
 }
 |
 {
 	flagarr = 0;
 }
 ;

optional_call
 : '[' ']'
 | '[' _IDENTIFIER ']'
 {
 	strcpy($<str>$,$<str>2);
	flagarr = 1;
 }
 | '[' _IDENTIFIER ']' '[' _IDENTIFIER ']'
 {
 	flagarr = 2;
	strcpy($<str>$, $<str>2);
	strcat($<str>$, ",");
	strcat($<str>$, $<str>5);
 }
 |
 {
 	flagarr = 0;
 }
 ;

main  : type_specifier _MAIN '(' ')'
	  {
		 table.clear();
     	 s.push(table);
    	 counter++;
		 token = $2;
		 insertToken(2,table);
		 ret = helper[$1];
		 makeFunction(token);
		 labelFuncCall(token);
	  }
      ;

functiondec : type_specifier pointer _IDENTIFIER '(' type_specifier pointer _IDENTIFIER optional ','  type_specifier pointer _IDENTIFIER  optional ')'
			{

				table.clear();
				s.push(table);
			    counter++;
				token = $3;
				makeFunction(token);
				error = insertToken(flag,table);
				if(error)
				{
					printf("REDECLARED_VARIABLE");
					exit(error);
				}
				token = $7;
				if(flagarr ==0)
				{
					error = insertToken(flag,table);
				}
				else
				{
				error = insertToken(flagarr+5,table);
				}
				if(error)
				{
					printf("REDECLARED_VARIABLE");
					exit(error);
				}
				token = $12;
				if(flagarr ==0)
				{
					error = insertToken(flag,table);
				}
				else
				{
				error = insertToken(flagarr+5,table);
				}
				if(error)
				{
					printf("REDECLARED_VARIABLE");
					exit(error);
				}
				ret = helper[$1];
				error = insertFunc($<str>1,$<str>3,$<str>5,$<str>10);
				if(error == -1)
				{
					printf("REDECLARED_FUNCTION");
					exit(error);
				}
			}
            ;

body : declaration | statement | funccall_statement ';'
     | body declaration
	 | body statement
	 | body funccall_statement ';'
     ;

expression : expression '+' expression
			{
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("+");
			}
		   | expression '-' expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("-");
			}
		   | expression '*' expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("*");
			}
		   | expression '/' expression
		   {
				if($<number>1!=$<number>3 || $<number>$ != $<number>1)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("/");
			}
		   | expression '%' expression
		   {
				if($<number>1!=$<number>3 || $<number>$ != $<number>1)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("%");
			}
		   | '(' expression ')'
		   | expression '>' expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC(">");
			}
		   | expression '<' expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("<");
			}
		   | expression _GREAT_EQ expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC(">=");
			}
		   | expression _LESS_EQ expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("<=");
			}
		   | expression _NOT_EQ expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("!=");
			}
		   | expression _EQUAL expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("==");
			}
		   | expression _LOGIC_AND expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("&&");
			}
		   | expression _LOGIC_OR expression
		   {
				if($<number>1!=$<number>3)
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				$<number>$ = $<number>1;
				printTAC("||");
			}
		   | expression ',' expression
		   | _IDENTIFIER optional_call {flagassign = flagarr;} '=' expression
		   {

				token = $1;
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE\n");
					exit(error);
				}
				type = lookupType($1);
		   		if(type!=$<number>5)
				{
					printf("Type Mismatch Error\n");
					exit(2);
				}
				operands.push($<str>1);
				if(flagassign == 1)
				{
					printf("$$$$$$$$$$$$$$$$$%s",$<str>2);
					operands.push($<str>2);
					printTAC("+");
				}
				if(flagassign == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, $<str>2);
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}
				printTACasgn();
           }
		   | _IDENTIFIER optional_call _INCR_1
		   {
		   		$<number>$ = lookupType($1);
				token = $1;
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE");
					exit(error);
				}
				operands.push($<str>1);
				if(flagarr == 1)
				{
					operands.push($<str>2);
					printTAC("+");

				}
				if(flagarr == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, $<str>2);
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}
				printTACun('+');
		   }
		   | _IDENTIFIER optional_call _DECR_1
		   {
		   		$<number>$ = lookupType($1);
				token = $1;
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE");
					exit(error);
				}
				operands.push($<str>1);
				if(flagarr == 1)
				{
					operands.push($<str>2);
					printTAC("+");
				}
				if(flagarr == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, $<str>2);
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}
				printTACun('-');
		   }
		   | _IDENTIFIER optional_call
		   {
		   		$<number>$ = lookupType($1);
				token = $1;
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE");
					exit(error);
				}
				operands.push($<str>1);

				if(flagarr == 1)
				{
					operands.push($<str>2);
					printTAC("+");
				}
				if(flagarr == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, $<str>2);
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}

		   }
		   | _CONSTANT
		   {
	   			$<number>$ = 3;
				//strcpy(, yytext);
				operands.push(yytext);
		   }
		   | _STRING
		   {
		   		$<number>$ = 4;
				operands.push(yytext);
		   }
		   ;

expression_statement : ';'
					 | expression ';'
					 ;

funccall_statement : _IDENTIFIER '(' expression ',' expression ')'
					{

						error = funcType($<str>1,$<number>3,$<number>5);
						if(error == -1)
						{
							printf("Function call arguments type error\n");
							exit(1);
						}
						labelFuncCall($<str>1);
					}
				   ;

return_statement :  _RETURN ';'
					{
						printf("^^^^^^^^^^^^^^^^^^^^%d",ret);
						if(ret != 5)
						{
							printf("return type mismatch error\n");
							exit(1);
						}
						operands.push("");
						printRet();
					}
					| _RETURN expression ';'
					{

						if(ret != $<number>2 )
						{
							printf("return type mismatch error\n");
							exit(1);
						}
						printRet();
					}
                 ;

io_statement : _PRINT '(' _STRING ',' identifier_list ')' ';'
			 | _SCAN '(' _STRING ',' identifieraddr_list ')' ';'
			 ;

identifier_list : identifier_list ',' _IDENTIFIER optional_call
				| _IDENTIFIER optional_call
				;

identifieraddr_list : identifieraddr_list ',' '&' _IDENTIFIER optional_call
					| '&' _IDENTIFIER optional_call
					| identifieraddr_list ','  _IDENTIFIER optional_call
					| _IDENTIFIER optional_call
					;

statement : expression_statement
		  | if_statement '{' body '}'
		  {
			disp(s.top());
			if(!s.empty())
				s.pop();
			printLabel();
		  }
		  | if_statement '{' body '}' {printGotoLabel();} else_statement '{' body '}'
		  {
			disp(s.top());
			if(!s.empty())
				s.pop();
			printLabel();
		  }
		  | loop_statement '{' body '}'
          {
			disp(s.top());
			if(!s.empty())
				s.pop();

		  }
 		  | do_statement '{' body '}' _WHILE '(' expression ')' ';'
          {
			disp(s.top());
			if(!s.empty())
				s.pop();
			printTADoWhile();
		  }
		  | return_statement
		  | io_statement
		  ;

loop_statement : _FOR '(' expression_statement expression_statement ')'
			   {
					table.clear();
					s.push(table); counter++;
			   }
			   | _FOR '(' expression_statement expression_statement expression ')'
			   {
				    table.clear();
				    s.push(table); counter++;

			   }
			   | _WHILE '(' expression ')'
			   {
				    table.clear();
				    s.push(table); counter++;
			   }
			   ;

do_statement : _DO
			 {
				table.clear();
				s.push(table); counter++;
				makeLabel();
			 }
			 ;

if_statement : _IF '(' expression ')'
			 {
			 	printTAIfNot();
				table.clear();
				s.push(table); counter++;
			 }
			 ;

else_statement : _ELSE
			   {
					disp(s.top());
					if(!s.empty())
						s.pop();
			   		table.clear();
					s.push(table); counter++;
			   }
	    	   ;

%%


int main(int argc, char *argv[])
{
	FILE* SRC;
	printf("\nSYNTACTICAL ANALYSIS\n");
	printf("----------------\n\n");
	if (argc == 2 && (SRC = fopen(argv[1],"r")))
        	yyin = SRC;
	else if(SRC == NULL)
	{
		printf("File not found\n");
		exit(0);
	}
	helper["FUNCTION"] = 1;
	helper["MAIN_FUNCTION"] = 2;
	helper["INTEGER_VARIABLE"] = 3;
	helper["CHAR_VARIABLE"] = 4;
	helper["VOID_VARIABLE"] = 5;
	insertFunc("INTEGER_VARIABLE", "strcmp", "CHAR_VARIABLE", "CHAR_VARIABLE");
	insertFunc("INTEGER_VARIABLE", "strcpy", "CHAR_VARIABLE", "CHAR_VARIABLE");
	table.clear();
	s.push(table);
	ofstream ofs;
	ofs.open("icg.txt",std::ofstream::out | std::ofstream::trunc);
	if(!yyparse())
		printf("\nPARSING PASSED!\n");
	else
		printf("\nPARSING FAILED!\n");
	fclose(SRC);
	ofs.close();
	if(commentflag)
	{
		printf("\nERROR 2 : Comment not closed\n");
		exit(2);
	}

	return 0;
}

void yyerror(char *msg)
{
	printf("\nSYNTAX ERROR at line %d\n",linecount);
}
