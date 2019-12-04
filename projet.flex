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

[0-9]+(\.[0-9]*)?([Ee][0-9]+)?	{ yylval.valeur = atof(yytext); return NUMBER; }

"Tant que"|"tant que"|"TANT QUE"    { return REPEAT; }
"Pour"|"pour"|"POUR"                {return FOR;}
"fonction"|"Fonction"|"FONCTION"    {return FUNC;}
"tracer"|"Tracer"|"TRACER"          {return PLOT;}
"AFFICHER"|"Afficher"|"afficher"    {return PRINT;}
"borne"|"BORNE"|"Borne"             {return LIM;}

"=="                                {return EQUAL;}
"!="                                {return DIFF;}
">="                                {return SUPEQ;}
"<="                                {return INFEQ;}

si|SI|Si 			{return SI;}
Sinon|sinon|SINON	{return SINON;}

\(([ \n\t\r]*[0-9A-Za-z_]*[ \n\t\r]*\,?)*\)    {strcpy(yylval.nom,yytext); return PARAM; }
[A-Za-z_][0-9A-Za-z_]*          { strcpy(yylval.nom,yytext); return IDENTIFIER; }

\r\n  							{  return '\n'; }	
\r								{  return '\n'; }
\n								{  return '\n'; }

[ \t]							{ }

.								{  return yytext[0]; }

%%