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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    INC = 262,
    DEC = 263,
    LT = 264,
    GT = 265,
    LTE = 266,
    GTE = 267,
    EQ = 268,
    NEQ = 269,
    ASSIGN = 270,
    VOID = 271,
    INT = 272,
    DOUBLE = 273,
    FLOAT = 274,
    CHAR = 275,
    LONG = 276,
    UNSIGNED = 277,
    COMMA = 278,
    LPAREN = 279,
    RPAREN = 280,
    LBRACE = 281,
    RBRACE = 282,
    ENDL = 283,
    FOR = 284,
    RET = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    NUM = 289,
    ID = 290
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define INC 262
#define DEC 263
#define LT 264
#define GT 265
#define LTE 266
#define GTE 267
#define EQ 268
#define NEQ 269
#define ASSIGN 270
#define VOID 271
#define INT 272
#define DOUBLE 273
#define FLOAT 274
#define CHAR 275
#define LONG 276
#define UNSIGNED 277
#define COMMA 278
#define LPAREN 279
#define RPAREN 280
#define LBRACE 281
#define RBRACE 282
#define ENDL 283
#define FOR 284
#define RET 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define NUM 289
#define ID 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
