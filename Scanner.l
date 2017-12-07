%{
  /*--------------------*/
  /*    Bryce Skelton   */
  /*    Checkpoint 2    */
  /*      09/22/17      */
  /*--------------------*/
  #define  DEBUG 0
  #include "y.tab.h"
  #include <stdio.h>
%}

%%

(M|m)(A|a)(I|i)(N|n) { if (DEBUG) printf("MAIN ");
                       return(MAIN);
                     }

(E|e)(N|n)(D|d) { if (DEBUG) printf("END ");
                  return(END);
                }

(D|d)(A|a)(T|t)(A|a) { if (DEBUG) printf("DATA ");
                       return(DATA);
                     }

(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(H|h)(M|m) { if (DEBUG) printf("ALGORITHM ");
                                                return(ALGORITHM);
                                              }

(E|e)(X|x)(I|i)(T|t) { if (DEBUG) printf("EXIT ");
                       return(EXIT);
                     }

(I|i)(F|f) { if (DEBUG) printf("IF ");
             return(IF);
           }

(E|e)(L|l)(S|s)(E|e) { if (DEBUG)printf("ELSE ");
                       return(ELSE);
                     }

(D|d)(O|o) { if (DEBUG) printf("DO ");
             return(DO);
           }

(W|w)(H|h)(I|i)(L|l)(E|e) { if (DEBUG) printf("WHILE ");
                            return(WHILE);
                          }

(C|c)(O|o)(U|u)(N|n)(T|t)(I|i)(N|n)(G|g) { if (DEBUG) printf("COUNTING ");
                                           return(COUNTING);
                                         }

(U|u)(P|p)(W|w)(A|a)(R|r)(D|d) { if (DEBUG) printf("UPWARD ");
                                 return(UPWARD);
                               }

(D|d)(O|o)(W|w)(N|n)(W|w)(A|a)(R|r)(D|d) { if (DEBUG) printf("DOWNWARD ");
                                           return(DOWNWARD);
                                         }

(T|t)(O|o) { if (DEBUG) printf("TO ");
             return(TO);
           }

(R|r)(E|e)(A|a)(D|d) { if (DEBUG) printf("READ ");
                       return(READ);
                     }

(P|p)(R|r)(I|i)(N|n)(T|t) { if (DEBUG) printf("PRINT ");
                            return(PRINT);
                          }

(I|i)(N|n)(T|t)(E|e)(G|g)(E|e)(R|r) { if (DEBUG) printf("INTEGER ");
                                      yylval.datatype = strdup(yytext);
                                      return(INTEGER);
                                    }

(R|r)(E|e)(A|a)(L|l) { if (DEBUG) printf("REAL ");
                       yylval.datatype = strdup(yytext);
                       return(REAL);
                     }

";" { if (DEBUG) printf("SEMICOLON ");
      return(SEMICOLON);
    }

":" { if (DEBUG) printf("COLON ");
      return(COLON);
    }

"!" { if (DEBUG) printf("CARRIAGE_RETURN ");
      return(CARRIAGE_RETURN);
    }

"(" { if (DEBUG) printf("LPAREN ");
      return(LPAREN);
    }

")" { if (DEBUG) printf("RPAREN ");
      return(RPAREN);
    }

"," { if (DEBUG) printf("COMMA ");
      return(COMMA);
    }

"[" { if (DEBUG) printf("LBRACKET ");
      yylval.lbracket = strdup(yytext);
      return(LBRACKET);
    }

"]" { if (DEBUG) printf("RBRACKET ");
      yylval.rbracket = strdup(yytext);
      return(RBRACKET);
    }

"{" { if (DEBUG) printf("LBRACE ");
      return(LBRACE);
    }

"}" { if (DEBUG) printf("RBRACE ");
      return(RBRACE);
    }

\n {}

[ \n\t\r]+ {/* Ignore Whitespace */}

([a-z]|[A-Z])+([a-z]|[A-Z]|[0-9])* { if (DEBUG) printf("VARIABLE %s ", yytext);
                                     yylval.name = strdup(yytext);
                                     return(VARIABLE);
                                    }

[0-9]+ { if (DEBUG) printf("INT %s ", yytext);
         yylval.ival = atoi(strdup(yytext));
         return(INT);
       }

([0-9]+\.[0-9]+|[0-9]+\.[0-9]+E(-|\+)?[0-9]+|[0-9]E(-|\+)?[0-9]+) { if (DEBUG) printf("FLOAT %s ", yytext);
                                                                           yylval.fval = atof(strdup(yytext));
                                                                           return(FLOAT);
                                                                         }

"+" { if (DEBUG) printf("PLUS ");
      return(PLUS);
    }

"-" { if (DEBUG) printf("MINUS ");
      return(MINUS);
    }

"*" { if (DEBUG) printf("MULT ");
      return(MULT);
    }

"/" { if (DEBUG) printf("DIV ");
      return(DIV);
    }

"%" { if (DEBUG) printf("MOD ");
      return(MOD);
    }

"<" { if (DEBUG) printf("LESSTHAN ");
      return(LESSTHAN);
    }

"<=" { if (DEBUG) printf("LESSTHANEQ ");
       return(LESSTHANEQ);
     }

">" { if (DEBUG) printf("GREATERTHAN ");
      return(GREATERTHAN);
    }

">=" { if (DEBUG) printf("GREATERTHANEQ ");
       return(GREATERTHANEQ);
     }

"=" { if (DEBUG) printf("EQUAL ");
      return(EQUAL);
    }

"<>" { if (DEBUG) printf("NOTEQ ");
       return(NOTEQ);
     }

"&" { if (DEBUG) printf("AND ");
      return(AND);
    }

"|" { if (DEBUG) printf("OR ");
      return(OR);
    }

"~" { if (DEBUG) printf("NOT ");
      return(NOT);
    }

":=" { if (DEBUG) printf("ASSIGN ");
       return(ASSIGN);
     }

\"(.|"")*\" { if (DEBUG) printf("STRING %s ", yytext);
              yylval.p_string = strdup(yytext);
              return(STRING);
            }

#.* {}

. {printf("TRASH %s ", yytext);
    return(TRASH);
  }
%%
