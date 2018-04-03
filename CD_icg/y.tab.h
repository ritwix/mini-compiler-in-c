/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _GREAT_EQ = 258,
    _LESS_EQ = 259,
    _LOGIC_OR = 260,
    _LOGIC_AND = 261,
    _NOT_EQ = 262,
    _EQUAL = 263,
    _INCR_1 = 264,
    _DECR_1 = 265,
    _CONSTANT = 266,
    _INCR_VAL = 267,
    _DECR_VAL = 268,
    _MULT_VAL = 269,
    _DIV_VAL = 270,
    _MOD_VAL = 271,
    _DO = 272,
    _ELSE = 273,
    _FOR = 274,
    _IF = 275,
    _PRINT = 276,
    _SCAN = 277,
    _WHILE = 278,
    _HEADER = 279,
    _PREPROC = 280,
    _STRING = 281,
    _RETURN = 282,
    _IDENTIFIER = 283,
    _MAIN = 284,
    _INT = 285,
    _CHAR = 286,
    _VOID = 287,
    MOD_VAL = 288
  };
#endif
/* Tokens.  */
#define _GREAT_EQ 258
#define _LESS_EQ 259
#define _LOGIC_OR 260
#define _LOGIC_AND 261
#define _NOT_EQ 262
#define _EQUAL 263
#define _INCR_1 264
#define _DECR_1 265
#define _CONSTANT 266
#define _INCR_VAL 267
#define _DECR_VAL 268
#define _MULT_VAL 269
#define _DIV_VAL 270
#define _MOD_VAL 271
#define _DO 272
#define _ELSE 273
#define _FOR 274
#define _IF 275
#define _PRINT 276
#define _SCAN 277
#define _WHILE 278
#define _HEADER 279
#define _PREPROC 280
#define _STRING 281
#define _RETURN 282
#define _IDENTIFIER 283
#define _MAIN 284
#define _INT 285
#define _CHAR 286
#define _VOID 287
#define MOD_VAL 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:1909  */

	int number;
    char str[10000];

#line 125 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
