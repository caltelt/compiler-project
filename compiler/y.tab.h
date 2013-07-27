/* A Bison parser, made by GNU Bison 2.6.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Ident = 258,
     IntLit = 259,
     FloatLit = 260,
     Int = 261,
     Float = 262,
     PRINT = 263,
     PRINTLN = 264,
     PRINTSPACE = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     EQ = 269,
     NEQ = 270,
     LT = 271,
     LTE = 272,
     GT = 273,
     GTE = 274,
     Bool = 275,
     BoolLit = 276,
     BoolAnd = 277,
     BoolOr = 278,
     Def = 279,
     Return = 280,
     Void = 281,
     Not = 282,
     Read = 283
   };
#endif
/* Tokens.  */
#define Ident 258
#define IntLit 259
#define FloatLit 260
#define Int 261
#define Float 262
#define PRINT 263
#define PRINTLN 264
#define PRINTSPACE 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define EQ 269
#define NEQ 270
#define LT 271
#define LTE 272
#define GT 273
#define GTE 274
#define Bool 275
#define BoolLit 276
#define BoolAnd 277
#define BoolOr 278
#define Def 279
#define Return 280
#define Void 281
#define Not 282
#define Read 283



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2042 of yacc.c  */
#line 22 "parser.y"

  int val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;


/* Line 2042 of yacc.c  */
#line 121 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
