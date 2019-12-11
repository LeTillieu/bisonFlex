/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

#ifndef YY_YY_PROJET_BISON_HPP_INCLUDED
# define YY_YY_PROJET_BISON_HPP_INCLUDED
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
    NUMBER = 258,
    IDENTIFIER = 259,
    GET = 260,
    GETFUNC = 261,
    SI = 262,
    ALORS = 263,
    SINON = 264,
    FINSI = 265,
    REPEAT = 266,
    JMP = 267,
    JNZ = 268,
    JNZINV = 269,
    OUT = 270,
    SUP = 271,
    INF = 272,
    EQUAL = 273,
    DIFF = 274,
    SUPEQ = 275,
    INFEQ = 276,
    FUNC = 277,
    PARAM = 278,
    ADDPARAM = 279,
    ADDRET = 280,
    EXECFUNC = 281,
    FUNCNAME = 282,
    RESETFUNC = 283,
    FOR = 284,
    GETMAXFOR = 285,
    DEFFUNC = 286,
    FUNCEXP = 287,
    PLOT = 288,
    PRINT = 289,
    LIM = 290,
    PLOTGRAPH = 291,
    PRINTFUNC = 292,
    EXP = 293,
    SIN = 294,
    COS = 295,
    TAN = 296,
    IN = 297,
    OUTPUT = 298,
    RETFUNC = 299,
    ARRAY = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "projet.bison" /* yacc.c:1910  */

  double valeur;
  char nom[50];
  t_adresse adresse;

#line 106 "projet.bison.hpp" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_BISON_HPP_INCLUDED  */
