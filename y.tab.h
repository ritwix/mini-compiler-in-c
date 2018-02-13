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
    ID = 258,
    NUM = 259,
    STRINGLIT = 260,
    INT = 261,
    SINT = 262,
    LINT = 263,
    UINT = 264,
    CHAR = 265,
    VOID = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    BREAK = 270,
    SCANF = 271,
    PRINTF = 272,
    RETURN = 273,
    MAIN = 274,
    LBRACE = 275,
    RBRACE = 276,
    LPAREN = 277,
    RPAREN = 278,
    SEMICOLON = 279,
    COMMA = 280,
    DOT = 281,
    SQ = 282,
    AND = 283,
    NOT = 284,
    OR = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    ASSIGN = 291,
    ISEQ = 292,
    GT = 293,
    LT = 294,
    GEQ = 295,
    LEQ = 296,
    DAND = 297,
    DOR = 298,
    NEQ = 299
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define STRINGLIT 260
#define INT 261
#define SINT 262
#define LINT 263
#define UINT 264
#define CHAR 265
#define VOID 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define BREAK 270
#define SCANF 271
#define PRINTF 272
#define RETURN 273
#define MAIN 274
#define LBRACE 275
#define RBRACE 276
#define LPAREN 277
#define RPAREN 278
#define SEMICOLON 279
#define COMMA 280
#define DOT 281
#define SQ 282
#define AND 283
#define NOT 284
#define OR 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define MOD 290
#define ASSIGN 291
#define ISEQ 292
#define GT 293
#define LT 294
#define GEQ 295
#define LEQ 296
#define DAND 297
#define DOR 298
#define NEQ 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
