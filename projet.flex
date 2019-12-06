%option noyywrap
%{
#include <string>
#include <iostream>
using namespace std;
// structure pour stocker les adresses pour les sauts condistionnels et autres...
typedef struct adr {
    int ic_goto; 
    int ic_false;
} t_adresse;

#include "projet.bison.hpp" 

using namespace std;

%}
%%

[0-9]+(\.[0-9]*)?	{ yylval.valeur = atof(yytext); return NUMBER; }

"Tant que"|"tant que"|"TANT QUE"    { return REPEAT; }
"Pour"|"pour"|"POUR"                {return FOR;}
"fonction"|"Fonction"|"FONCTION"    {return FUNC;}
"tracer"|"Tracer"|"TRACER"          {return PLOT;}
"borne"|"BORNE"|"Borne"             {return LIM;}
"entree"|"ENTREE"|"Entree"          {return IN;} 
"sorti"|"Sorti"|"SORTI"       {return OUTPUT;} 
"e"|"EXP"|"Exp"|"exp"         {return EXP;}
"cos"|"COS"|"Cos"              {return COS;}
"sin"|"SIN"|"Sin"              {return SIN;}
"tan"|"TAN"|"Tan"              {return TAN;}
"retourne"|"Retourne"|"RETOURNE"  {return RETFUNC;}

"=="                                {return EQUAL;}
"!="                                {return DIFF;}
">="                                {return SUPEQ;}
"<="                                {return INFEQ;}

"si"|"SI"|"Si" 			{return SI;}
"Sinon"|"sinon"|"SINON"	{return SINON;}

[A-Za-z_][0-9A-Za-z_]*          { strcpy(yylval.nom,yytext); return IDENTIFIER; }

\r\n  							{  return '\n'; }	
\r								{  return '\n'; }
\n								{  return '\n'; }

[ \t]							{ }

.								{  return yytext[0]; }

%%