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
    VOID = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    BREAK = 266,
    SCANF = 267,
    PRINTF = 268,
    RETURN = 269,
    LBRACE = 270,
    RBRACE = 271,
    LPAREN = 272,
    RPAREN = 273,
    SEMICOLON = 274,
    COMMA = 275,
    DOT = 276,
    LSQ = 277,
    RSQ = 278,
    QM = 279,
    AND = 280,
    NOT = 281,
    OR = 282,
    ADD = 283,
    SUB = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    ASSIGN = 288,
    ISEQ = 289,
    GT = 290,
    LT = 291,
    GEQ = 292,
    LEQ = 293,
    DAND = 294,
    DOR = 295,
    NEQ = 296
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define STRINGLIT 260
#define INT 261
#define VOID 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define BREAK 266
#define SCANF 267
#define PRINTF 268
#define RETURN 269
#define LBRACE 270
#define RBRACE 271
#define LPAREN 272
#define RPAREN 273
#define SEMICOLON 274
#define COMMA 275
#define DOT 276
#define LSQ 277
#define RSQ 278
#define QM 279
#define AND 280
#define NOT 281
#define OR 282
#define ADD 283
#define SUB 284
#define MUL 285
#define DIV 286
#define MOD 287
#define ASSIGN 288
#define ISEQ 289
#define GT 290
#define LT 291
#define GEQ 292
#define LEQ 293
#define DAND 294
#define DOR 295
#define NEQ 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
