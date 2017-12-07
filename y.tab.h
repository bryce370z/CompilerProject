/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     END = 259,
     DATA = 260,
     ALGORITHM = 261,
     EXIT = 262,
     IF = 263,
     ELSE = 264,
     DO = 265,
     WHILE = 266,
     COUNTING = 267,
     UPWARD = 268,
     DOWNWARD = 269,
     TO = 270,
     READ = 271,
     PRINT = 272,
     INTEGER = 273,
     REAL = 274,
     SEMICOLON = 275,
     COLON = 276,
     CARRIAGE_RETURN = 277,
     LPAREN = 278,
     RPAREN = 279,
     COMMA = 280,
     RBRACKET = 281,
     LBRACKET = 282,
     LBRACE = 283,
     RBRACE = 284,
     VARIABLE = 285,
     INT = 286,
     FLOAT = 287,
     PLUS = 288,
     MINUS = 289,
     MULT = 290,
     DIV = 291,
     MOD = 292,
     LESSTHAN = 293,
     LESSTHANEQ = 294,
     GREATERTHAN = 295,
     GREATERTHANEQ = 296,
     EQUAL = 297,
     NOTEQ = 298,
     AND = 299,
     OR = 300,
     NOT = 301,
     ASSIGN = 302,
     STRING = 303,
     TRASH = 304
   };
#endif
/* Tokens.  */
#define MAIN 258
#define END 259
#define DATA 260
#define ALGORITHM 261
#define EXIT 262
#define IF 263
#define ELSE 264
#define DO 265
#define WHILE 266
#define COUNTING 267
#define UPWARD 268
#define DOWNWARD 269
#define TO 270
#define READ 271
#define PRINT 272
#define INTEGER 273
#define REAL 274
#define SEMICOLON 275
#define COLON 276
#define CARRIAGE_RETURN 277
#define LPAREN 278
#define RPAREN 279
#define COMMA 280
#define RBRACKET 281
#define LBRACKET 282
#define LBRACE 283
#define RBRACE 284
#define VARIABLE 285
#define INT 286
#define FLOAT 287
#define PLUS 288
#define MINUS 289
#define MULT 290
#define DIV 291
#define MOD 292
#define LESSTHAN 293
#define LESSTHANEQ 294
#define GREATERTHAN 295
#define GREATERTHANEQ 296
#define EQUAL 297
#define NOTEQ 298
#define AND 299
#define OR 300
#define NOT 301
#define ASSIGN 302
#define STRING 303
#define TRASH 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "Parser.y"
{
  // symbol table
  char* name;
  char* datatype;
  char* rbracket;
  char* lbracket;
  int ival;
  float fval;

  //AST
  char* p_string;
  struct statement* new_statement;
  struct expression* new_expression;
  struct print* new_print;

}
/* Line 1529 of yacc.c.  */
#line 164 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

