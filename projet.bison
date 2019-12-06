%{
  #include <iostream>
  #include <map>
  #include <string>
  #include <vector>  
  #include <algorithm>
  #include <cmath> 
  #include <SFML/OpenGL.hpp>
  #include <SFML/Graphics.hpp>
  using namespace std;
  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }
  sf::RenderWindow window(sf::VideoMode(100, 100), "My window");
  map<string, double> variables;
  map<string, vector<double>> functions;      //ic of start and end of each func
  map<string, vector<string>> funcParameters; //name of parameters of each func
  map<string, vector<string>> funcReturn; //name of return of each func
  vector<map<string, double>> varFunc; //variables to reset after function
  map<int, pair<double, double>> forLoop;
vector<string> funcNames;
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
%token PLOTGRAPH
%token PRINTFUNC
%token <valeur> EXP 
%token <valeur> SIN 
%token <valeur> COS 
%token <valeur> TAN
%token IN 
%token OUTPUT 
%token RETFUNC

%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%
bloc : bloc instruction '\n' 
      |    /* Epsilon */
      ;

instruction : SI                     {}
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
            |FOR '(' IDENTIFIER ',' expression ',' expression ')'   {$1.ic_goto = ic; ins(FOR, $3); ins(GET, $3); ins(GETMAXFOR, to_string($1.ic_goto)); ins(INF, "0"); $1.ic_false = ic; ins(JNZ, "0");}
            '{'                                                     {}
            bloc                                                    {}                  
            '}'                                                     {ins(GET, $3); ins(NUMBER, "1"); ins('+', "0"); ins(IDENTIFIER, $3); ins(JMP, to_string($1.ic_goto+1)); instructions[$1.ic_false].second = to_string(ic);ins(GET, $3); ins(NUMBER, "1"); ins('-', "0"); ins(IDENTIFIER, $3);}

            |   /* Ligne vide*/
            |IDENTIFIER '=' expression        {ins(IDENTIFIER, $1);}
            |FUNC IDENTIFIER '('setParam ')' '{' {ins(FUNCNAME, $2); ins(ADDPARAM, "0"); $1.ic_goto = ic; ins(JMP, "0"); functions[$2] = vector<double>(2,0); functions[$2][0] = ic;}
            bloc                            {}
            '}'                             {instructions[$1.ic_goto].second = to_string(ic);}
            |PLOT                        {$1.ic_goto = ic; ins(GET, "maxX"); ins(GET, plotVarName); ins(SUP, "0"); $1.ic_false = ic; ins(JNZ, "0");}
            expression            {ins(PRINTFUNC, "0"); ins(GET, "step"); ins(GET, plotVarName); ins('+', "0"); ins(IDENTIFIER, plotVarName); ins(JMP, to_string($1.ic_goto)); instructions[$1.ic_false].second = to_string(ic); ins(PLOTGRAPH, "0");}
            |LIM expression expression expression IDENTIFIER {ins(FUNCNAME, $5);ins(LIM, "0"); plotVarName = $5;}
            |IN IDENTIFIER {ins(IN, $2);} 
            |OUTPUT expression {ins(OUTPUT, "0");} 
            |RETFUNC expression              {ins(RESETFUNC, "0");}
            |IDENTIFIER expression           {ins(FUNCNAME, $1);ins(EXECFUNC, "0");}
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
          | expression '^' expression     {ins('^', "0");}
          | expression ',' expression      { }
          | '(' expression ')'            { }    
          | NUMBER                        {ins(NUMBER, to_string($1));}
          | IDENTIFIER                    {ins(GET, $1);}
          | EXP expression                { ins(EXP, "0");} 
          | SIN expression                { ins(SIN, "0");} 
          | COS expression                { ins(COS, "0");} 
          | TAN expression                { ins(TAN, "0");}
          |IDENTIFIER expression           {ins(FUNCNAME, $1);ins(EXECFUNC, "0");}

          

          ;
setParam: setParam ',' setParam      { }
          | IDENTIFIER                    {ins(FUNCNAME, $1);}
          |   /* Ligne vide*/

          
          ;
        
%%

// Pour imprimer le code généré de manière plus lisible 
string nom(int instruction){
  switch (instruction){
  case '-'     : return "-";
  case '+'     : return "+";
  case '/'     : return "/";
  case '*'     : return "*";
  case '^'      :return "^";
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
  case EXP     : return "EXP"; 
  case SIN     : return "SIN"; 
  case COS     : return "COS"; 
  case TAN     : return "TAN";
  case IN:        return "IN"; 
  case OUTPUT:    return "OUTPUT"; 
  case  PRINTFUNC:  return "PRINTFUNC";
  case PLOTGRAPH:   return  "PLOTGRAPH";
  case  RETFUNC:    return  "RETFUNC";
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
  double x,y,z; 
  string var;
  plotVarName = "";
  funcPlotX.clear();
  funcPlotY.clear();
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

      case '^': {
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(pow(y,x)));
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

      case IN:{ 
        cout << ins.second <<": ";
        cin>>x; 
        variables[ins.second] = x;
        pile.push_back(to_string(x)); 
        ic++; 
      } 
      break; 
 
      case OUTPUT:{ 
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

      case EXP : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(exp(x))); 
        ic++; 
      }
      break; 
 
      case SIN : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(sin(x*M_PI/180))); 
        ic++; 
      }   
      break; 
 
      case COS : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(cos(x))); 
        ic++; 
      }  
      break; 
 
      case TAN : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(sin(x)/cos(x))); 
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
        string funcName = funcNames[funcNames.size() - 1];
        var = depiler(pile);
      
        if(is_number(var)){
            pile.push_back(var);
        }else if(variables.find(var) != variables.end()){
          cout << var << endl;
          pile.push_back(to_string(variables[var]));
        }
        variables = varFunc[varFunc.size()-1];
        varFunc.pop_back();
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
        while(!pile.empty()){
          funcParameters[funcName].push_back(depiler(pile));
        }
        functions[funcName][1] = funcParameters[funcName].size();
        ic++;
      }  
      break;
    

      case EXECFUNC:{
        string funcName = depiler(pile);
        if(pile.size() >= functions[funcName][1]){
          vector<double> parameters;
          for(auto i =0; i < functions[funcName][1]; i++){
            var = depiler(pile);
            if(is_number(var)){
            parameters.push_back(stof(var));
            }else if(variables.find(var) != variables.end()){
              parameters.push_back(variables[var]);
            }

            if(parameters.size() == funcParameters[funcName].size()){
              varFunc.push_back(variables);
              for(auto i = 0; i < parameters.size(); i++){
                variables[funcParameters[funcName][i]] = parameters[i];
              }
              toGoAfterFunc.push_back(ic+1);
              ic = functions[funcName][0];
              funcNames.push_back(funcName);
              
            }else{
              ic++;
            }
          }
        }else{
          ic++;
        }
      }   
      break;

      case LIM:{
        plotVarName = depiler(pile);
        step = depilerDouble(pile);

        maxX = depilerDouble(pile);
        variables["maxX"] = maxX;

        minX = depilerDouble(pile);
        variables[plotVarName] = minX;

        variables["step"] = (maxX-minX)/step;

        ic++;
      }
      break;

      case PLOTGRAPH:{
        sf::VertexArray vertexPoints(sf::LinesStrip, funcPlotX.size());
        for(int i = 0; i < funcPlotX.size(); i++){
          vertexPoints[i].position = sf::Vector2f(funcPlotX[i], funcPlotY[i]);
        }
        variables["maxX"] = maxX;
        variables[plotVarName] = minX;
        window.draw(vertexPoints);
        variables["step"] = (maxX-minX)/step;
        funcPlotX.clear();
        funcPlotY.clear();
        ic++;
      }
      break;

      case PRINTFUNC:{
        funcPlotX.push_back(variables[plotVarName]+window.getSize().x/2);
        x = depilerDouble(pile);
        funcPlotY.push_back(-x+window.getSize().y/2);
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
  sf::VertexArray vertexPoints(sf::LinesStrip, 2);
          vertexPoints[0].position = sf::Vector2f(0, window.getSize().y/2);
          vertexPoints[1].position = sf::Vector2f(window.getSize().x, window.getSize().y/2);
  window.draw(vertexPoints);

          vertexPoints[0].position = sf::Vector2f(window.getSize().x/2, 0);
          vertexPoints[1].position = sf::Vector2f(window.getSize().x/2, window.getSize().y);
  window.draw(vertexPoints);
  window.display();
  //  while (window.isOpen())
  //   {
  //       // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
  //       sf::Event event;
  //       while (window.pollEvent(event))
  //       {
  //           // fermeture de la fenêtre lorsque l'utilisateur le souhaite
  //           if (event.type == sf::Event::Closed)
  //               window.close();
            
  //       }

        
  //   }

}