%{
  #include <iostream>
  #include <map>
  #include <string>
  #include <vector>  
  #include <algorithm>
  #include"matplotlibcpp.h"
  using namespace std;
  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  map<string, double> variables;
  map<string, vector<double>> functions;      //ic of start and end of each func
  map<string, vector<string>> funcParameters; //name of parameters of each func
  map<string, vector<string>> funcReturn; //name of return of each func
  vector<map<string, double>> varFunc; //variables to reset after function
  map<int, pair<double, double>> forLoop;
  vector<double> funcPlotX;
  vector<double> funcPlotY;
  double minX, maxX, step;
  string plotVarName;
  vector<int> toGoAfterFunc;
  vector<pair<int,string>> instructions;
  int ic = 0;   // compteur instruction 

  void ins(int c, string d) { instructions.push_back(make_pair(c, d)); ic++;};
  bool is_number(const std::string& s)
  {
      std::string::const_iterator it = s.begin();
      while (it != s.end() && (std::isdigit(*it) || *it == '.'|| *it == ',') ) ++it;
      return !s.empty() && it == s.end();
  }

  // structure pour stocker les adresses pour les sauts condistionnels et autres...
  typedef struct adr {
    int ic_goto; 
    int ic_false;
    int lastVarId;
  } t_adresse; 

%}

%union
{
  double valeur;
  char nom[50];
  t_adresse adresse;
}

%token <valeur> NUMBER
%token <nom> IDENTIFIER
%token GET
%token GETFUNC
%type <valeur> expression
%token <adresse> SI 
%token ALORS
%token SINON
%token FINSI
%token <adresse> REPEAT
%token JMP 
%token JNZ
%token JNZINV
%token OUT
%token SUP
%token INF
%token EQUAL
%token DIFF;
%token SUPEQ
%token INFEQ
%token <adresse> '{'
%token <adresse> FUNC
%token <nom> PARAM
%token ADDPARAM
%token ADDRET
%token EXECFUNC
%token FUNCNAME
%token RESETFUNC
%token <adresse> FOR
%token GETMAXFOR
%token DEFFUNC
%token <nom> FUNCEXP
%token <adresse> PLOT
%token PRINT
%token LIM

%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%
bloc : bloc instruction '\n' 
      |    /* Epsilon */
      ;

instruction : PRINT expression          {ins(OUT, "");}
              |SI                     {}
              '(' condition ')'       {$1.ic_false = ic; ins(JNZ, "0"); }
              '{'                     {}
              bloc                    {}
              '}'                     {}
              SINON                   {$1.ic_goto = ic; ins(JMP, "0");instructions[$1.ic_false].second = to_string(ic);}
              '{'                     {}
              bloc                    {}
              '}'                     {instructions[$1.ic_goto].second = to_string(ic);}            
            | REPEAT                  {$1.ic_goto = ic;}
              '(' condition ')'       {$1.ic_false = ic; ins(JNZ, "0");}
              '{'                     {}
              bloc                    {}
              '}'                     {instructions[$1.ic_false].second = to_string(ic+1); ins(JMP, to_string($1.ic_goto));}

            | '{'                     {$1.ic_goto = ic;}
              bloc                    {}
              '}'                     {}
              REPEAT                  {}
              '(' condition ')'       {ins(JNZINV,to_string($1.ic_goto));}
            |FOR '(' IDENTIFIER ':' expression ':' expression ')'   {$1.ic_goto = ic; ins(FOR, $3); ins(GET, $3); ins(GETMAXFOR, to_string($1.ic_goto)); ins(INF, "0"); $1.ic_false = ic; ins(JNZ, "0");}
            '{'                                                     {}
            bloc                                                    {}                  
            '}'                                                     {ins(GET, $3); ins(NUMBER, "1"); ins('+', "0"); ins(IDENTIFIER, $3); ins(JMP, to_string($1.ic_goto+1)); instructions[$1.ic_false].second = to_string(ic);ins(GET, $3); ins(NUMBER, "1"); ins('-', "0"); ins(IDENTIFIER, $3);}

            |   /* Ligne vide*/
            |IDENTIFIER '=' expression        {ins(IDENTIFIER, $1);}
            |FUNC IDENTIFIER PARAM ':'PARAM'{' {ins(FUNCNAME, $2); ins(ADDPARAM, $5); ins(FUNCNAME, $2); ins(ADDRET, $3); $1.ic_goto = ic; ins(JMP, "0"); functions[$2] = vector<double>(2,0); functions[$2][0] = ic;}
            bloc                            {}
            '}'                             {ins(FUNCNAME, $2);ins(RESETFUNC, "0");functions[$2][1] = ic; ins(JMP, "0");instructions[$1.ic_goto].second = to_string(ic);}
            |IDENTIFIER PARAM             {ins(FUNCNAME, $1);ins(EXECFUNC, $2);}
            |PLOT                        {ins(NUMBER, to_string(maxX)); ins(GET, plotVarName); ins(INF, "0"); $1.ic_false = ic; ins(JNZ, "0");}
            '(' expression ')'           {}
            |LIM expression expression expression IDENTIFIER {ins(FUNCNAME, $5);ins(LIM, "0");}
            ;

condition: expression '>' expression      {ins(SUP, "0");}
            | expression '<' expression   {ins(INF, "0");}
            | expression EQUAL expression   {ins(EQUAL, "0");}
            | expression DIFF expression   {ins(DIFF, "0");}
            | expression SUPEQ expression   {ins(SUPEQ, "0");}
            | expression INFEQ expression   {ins(INFEQ, "0");}
            ;
expression: expression '+' expression     { ins('+', "0");}
          | expression '-' expression     { ins('-', "0");}
          | expression '*' expression     { ins('*', "0");}
          | expression '/' expression     { ins('/', "0");}
          | expression ',' expression      { }
          | '(' expression ')'            { }  
          | NUMBER                        { ins(NUMBER, to_string($1));}
          | IDENTIFIER                    {ins(GET, $1);}          
          ;
%%

// Pour imprimer le code généré de manière plus lisible 
string nom(int instruction){
  switch (instruction){
  case '-'     : return "-";
  case '+'     : return "+";
  case '/'     : return "/";
  case '*'     : return "*";
  case NUMBER  : return "NUM";
  case OUT     : return "OUT";
  case JNZ     : return "JNZ";   // Jump if not zero
  case JNZINV     : return "JNZINV";   // Jump if zero

  case JMP     : return "JMP";   // Unconditional Jump
  case IDENTIFIER  : return "VAR";
  case SUP :     return "SUP";
  case INF :     return "INF";
  case SUPEQ :     return "SUPEQ";
  case INFEQ :     return "INFEQ";
  case EQUAL :     return "EQUAL";
  case DIFF :     return "DIFF";
  case FUNC :    return "FUNC";
  case GET:     return "GET";

  case PARAM:   return "PARAM";
  case GETFUNC:  return "GETFUNC";
  case ADDPARAM:   return "ADDPARAM";
  case ADDRET:   return "ADDRET";
  case FUNCNAME:  return "FUNCNAME";
  case RESETFUNC: return "RESETFUNC";
  case EXECFUNC : return  "EXECFUNC";
  case FOR:       return  "FOR";
  case LIM:        return   "LIM";
  default  : return to_string (instruction);
   }
}

void print_program(){
  cout << "==== CODE GENERE ====" << endl;
  int i = 0;
  for (auto ins : instructions )
    cout << i++ << "\t\t\t" << nom(ins.first) << "\t\t"  << ins.second << endl;
  cout << "=====================" << endl;  
  

}

string depiler(vector<string> &pile) {
  string t = pile[pile.size()-1];
  pile.pop_back();
  return t;
}

double depilerDouble(vector<string> &pile){
  string t = pile[pile.size()-1];
  pile.pop_back();
  return (double)atof(t.c_str());
}

void run_program(){
  vector<string> pile; 
  double x,y;
  string var;
  variables.clear();
  ic = 0;
  cout << "===== EXECUTION =====" << endl;
  while ( ic < instructions.size() ){
    auto ins = instructions[ic];
    switch(ins.first){
      case '+':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y+x));
        ic++;
      }     
      break;
    
      case '*':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y*x));
        ic++;
      }     
      break;

      case '-':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y-x));
        ic++;
      }
      break;


      case '/':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y/x));
        ic++;
      }
      break;

      case NUMBER :{
        pile.push_back(ins.second);
        ic++;
      }  
      break;
    
      case JMP :{
        ic = (double)atof(ins.second.c_str());
      }
      break;
    
      case JNZ :{
        x = depilerDouble(pile);
        ic = ( x ? ic+1 : (double)atof(ins.second.c_str()));
      }
      break;

      case JNZINV:{
        x = depilerDouble(pile);
        ic = ( x ? (double)atof(ins.second.c_str()) : ic+1);
      }  
      break;

      case OUT:{
        if(!pile.empty()){
          var = depiler(pile);
          if(is_number(instructions[ic-1].second)){
          cout << "Résultat : " << var << endl;
          }else if(variables.find(instructions[ic-1].second) != variables.end()){
            cout << instructions[ic-1].second << ": " << var << endl;
          }
        }
        ic++;
      }
      break;

      case IDENTIFIER :{
        x = depilerDouble(pile);
        variables[ins.second] = x;
        ic++;
      }      
      break;

      case GET:{
        if(variables.find(ins.second) != variables.end()){
          pile.push_back(to_string(variables[ins.second]));
        }
        ic++;
      }
      break;

      case GETFUNC:
        var = ins.second;
        instructions[functions[var][1]].second = to_string(ic+1);
        ic = functions[var][0];
      break;
      
     case SUP:{
      x = depilerDouble(pile);
      y = depilerDouble(pile);
      if(y>x){
          pile.push_back("1");
      }else{
        pile.push_back("0");
      }
       ic++;
     }  
      break;

      case INF:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        cout << y << " " << x << endl;
        if(y<x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case SUPEQ:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y>=x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case INFEQ:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y<=x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case EQUAL:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y==x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case DIFF:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y!=x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case FOR:{
        double maxVal = depilerDouble(pile);
        double minVal = depilerDouble(pile);
        pair<double, double> tmp;
        tmp.first = minVal;
        tmp.second = maxVal;
        forLoop[ic] = tmp;
        variables[ins.second] = minVal;
        ic++;
      }
      break;

      case GETMAXFOR: {
        x = forLoop[stoi(ins.second)].second;
        pile.push_back(to_string(x));
        ic++;
      }
      break;


      case RESETFUNC: {
        string funcName = depiler(pile);
        vector<pair<string, double>> returnedVar;
        pair<string, double> tmpPair;
        for(auto c: funcReturn[funcName]){
            tmpPair.first = c;
            tmpPair.second = variables[c];
            returnedVar.push_back(tmpPair);
        }

        variables = varFunc[varFunc.size()-1];
        
        for(auto c: returnedVar){
            variables[c.first] = c.second;
        }
        ic = toGoAfterFunc[toGoAfterFunc.size()-1];
        toGoAfterFunc.pop_back();
      }
      break;

      case FUNCNAME:{
        pile.push_back(ins.second);
        ic++;
      }
      break;

      case ADDPARAM:{
        string funcName = depiler(pile);
        string param = ins.second.substr(1,ins.second.length()-2);
        string curParam;
        int curCommaPos = param.find(",");
        while(curCommaPos != string::npos){
          curParam = param.substr(0,curCommaPos);
          if(!is_number(string(1,curParam.at(0)))){
            funcParameters[funcName].push_back(curParam);
          }
          param = param.substr(curCommaPos+1,param.length());
          curCommaPos = param.find(",");
        }
        if(!is_number(string(1,param.at(0)))){
            funcParameters[funcName].push_back(param);
        }
        ic++;
      }  
      break;
      
      case ADDRET:{
        string funcName = depiler(pile);
        string param = ins.second.substr(1,ins.second.length()-2);
        string curParam;
        int curCommaPos = param.find(",");
        while(curCommaPos != string::npos){
          funcReturn[funcName].push_back(param.substr(0,curCommaPos));
          param = param.substr(curCommaPos+1,param.length());
          curCommaPos = param.find(",");
        }
        funcReturn[funcName].push_back(param);
        ic++;
      }  
      break;

      case EXECFUNC:{
        string funcName = depiler(pile);
        string param = ins.second.substr(1,ins.second.length()-2);
        string curParam;

        int curCommaPos = param.find(",");

        vector<double> parameters;

        while(curCommaPos != string::npos){
          curParam = param.substr(0,curCommaPos);
          if(is_number(curParam)){
            parameters.push_back(atof(curParam.c_str()));
          }else if(variables.find(curParam) != variables.end()){
            parameters.push_back(variables[curParam]);
          }
          param = param.substr(curCommaPos+1, param.length());
          curCommaPos = param.find(",");
        }

        if(is_number(param)){
           parameters.push_back(atof(param.c_str()));
        }else if(variables.find(param) != variables.end()){
            parameters.push_back(variables[param]);
        }
        if(parameters.size() == funcParameters[funcName].size()){
          varFunc.push_back(variables);
          for(int i =0; i < parameters.size(); i++){
            variables[funcParameters[funcName][i]] = parameters[i];
          }
          toGoAfterFunc.push_back(ic+1);
          ic=functions[funcName][0];
        }else{
          ic++;
        }
      }     
      break;

      case FUNCEXP:{
        pile.push_back(ins.second);
        ic++;
      }
      break;

      case LIM:{
        plotVarName = depiler(pile);
        step = depilerDouble(pile);
        maxX = depilerDouble(pile);
        minX = depilerDouble(pile);
        variables[plotVarName] = minX;
        ic++;
      }
      break;

      default:{
        cout << "No instruction" << endl;
        ic++;
      }    
    }

    
  }
  cout << "=====================" << endl; 

   auto i = 0;
    cout << "==== VARIABLES ====" << endl;
    for (auto ins : variables )
      cout << i++ << '\t' << ins.first << "\t" << ins.second << endl;
  cout << "=====================" << endl; 

    cout << "==== FONCTION ====" << endl;
    for (auto ins : functions )
      cout << ins.first << '\t' << ins.second[0] << '\t' << ins.second[1]  << endl;
  cout << "=====================" << endl; 
}

int main(int argc, char **argv) {
  
  if ( argc > 1 ){
    yyin = fopen( argv[1], "r" );
  }
  else{
    yyin = stdin;
    cout << stdin << endl;
  }
  yyparse();
  print_program();

  run_program();

}