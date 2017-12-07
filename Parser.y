%{
  /*--------------------*/
  /*    Bryce Skelton   */
  /*    Checkpoint 4    */
  /*      10/11/17      */
  /*--------------------*/
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "structs.h"
  #define PRINT_TABLE 0

  /* symbol table */
  struct symbol symbol_array[500];
  int address = 0;
  int pos= 0;
  char *new_type;

  /*AST*/
  struct statement * stmt_list;
%}

%union{
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

%token   MAIN
%token   END
%token   DATA
%token   ALGORITHM
%token   EXIT
%token   IF
%token   ELSE
%token   DO
%token   WHILE
%token   COUNTING
%token   UPWARD
%token   DOWNWARD
%token   TO
%token   READ
%token   PRINT
%token <datatype> INTEGER
%token <datatype> REAL
%token   SEMICOLON
%token   COLON
%token   CARRIAGE_RETURN
%token   LPAREN
%token   RPAREN
%token   COMMA
%token <rbracket>  RBRACKET
%token <lbracket>  LBRACKET
%token   LBRACE
%token   RBRACE
%token <name> VARIABLE
%token <ival>  INT
%token   <fval> FLOAT
%token   PLUS
%token   MINUS
%token   MULT
%token   DIV
%token   MOD
%token   LESSTHAN
%token   LESSTHANEQ
%token   GREATERTHAN
%token   GREATERTHANEQ
%token   EQUAL
%token   NOTEQ
%token   AND
%token   OR
%token   NOT
%token   ASSIGN
%token  <p_string> STRING
%token TRASH

// %type <name> algholder
%type <new_statement> algobody
%type <new_statement> algoline
%type <new_expression> statement
%type <new_expression> comparison
%type <new_expression> exp
%type <new_expression> term
%type <new_expression> factor
%type <new_expression> atom
%type <new_print> printlist
%type <new_print> printable

%%
prog : MAIN SEMICOLON datasec algosec END MAIN SEMICOLON

;

datasec : DATA COLON vartable

;

vartable :
| vartable vardec

;

vardec : datatype COLON varlist SEMICOLON

;

varlist : varlist COMMA dataholder
| dataholder

;

datatype: INTEGER
{
  new_type = $1;
}
| REAL
{
  new_type = $1;
}

;

dataholder : VARIABLE
{
  symbol_array[pos].name = $1;
  symbol_array[pos].datatype = new_type;
  symbol_array[pos].address = address;
  symbol_array[pos].kind = "scalar";
  if(PRINT_TABLE == 1){
    printf("name:%s address:%i datatype:%s kind:%s\n",symbol_array[pos].name, symbol_array[pos].address, symbol_array[pos].datatype, symbol_array[pos].kind);
  }
  pos++;
  address++;
}
| VARIABLE LBRACKET INT RBRACKET
{
  symbol_array[pos].name = $1;
  symbol_array[pos].datatype = new_type;
  symbol_array[pos].address = address;
  symbol_array[pos].kind = "array dec";
  if(PRINT_TABLE == 1){
    printf("name:%s address:%i datatype:%s kind:%s\n", symbol_array[pos].name, symbol_array[pos].address, symbol_array[pos].datatype, symbol_array[pos].kind);
  }
  pos++;
  address += $3;
}

;

algosec : ALGORITHM COLON  algobody
{
  stmt_list = $3;
}
;

algobody : algoline algobody
{
  $1->next = $2;
  $$ = $1;
}
| algoline
{
  $$ = $1;
}

;

algoline : VARIABLE ASSIGN statement SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_ASSIGN;
  $$->var = $1;
  $$->expression = $3;
  $$->next = NULL;
}
| VARIABLE LBRACKET statement RBRACKET ASSIGN statement SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_ASSIGN;
  $$->var = $1;
  $$->var_array_expresssion = $3;
  $$->expression = $6;
  $$->next = NULL;
}
| IF statement SEMICOLON algobody END IF SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_IF;
  $$->expression = $2;
  $$->next = NULL;
  $$->body = $4;
}
| IF statement SEMICOLON algobody ELSE SEMICOLON algobody END IF SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_IF_ELSE;
  $$->expression = $2;
  $$->next = NULL;
  $$->body = $4;
  $$->else_body = $7;
}
|  WHILE statement SEMICOLON algobody END WHILE SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_WHILE;
  $$->expression = $2;
  $$->next = NULL;
  $$->body = $4;
}
| PRINT printlist SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_PRINT;
  $$->print = $2;
  $$->next = NULL;
}
| READ VARIABLE SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_READ;
  $$->var = $2;
  $$->next = NULL;
}
| READ VARIABLE LBRACKET statement RBRACKET SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_READ;
  $$->expression = $4;
  $$->var = $2;
  $$->next = NULL;
}
| EXIT SEMICOLON
{
  $$ = malloc(sizeof(struct statement));
  $$->kind = STMT_EXIT;
  $$->next = NULL;
}
printlist : printlist COMMA printable
{
  $1->next = $3;
  $$ = $1;
}
| printable
{
  $$ = $1;
}

;

printable : statement
{
  $$ = malloc(sizeof(struct print));
  $$->kind = P_EXPR_KIND;
  $$->p_expr = $1;
}
| CARRIAGE_RETURN
{
  $$ = malloc(sizeof(struct print));
  $$->kind = P_NEWLINE_KIND;
  $$->newline = 1;
}
| STRING
{
  $$ = malloc(sizeof(struct print));
  $$->kind = P_STR_KIND;
  $$->p_string = $1;
}
;

statement : statement AND comparison
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = AND_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| statement OR comparison
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = OR_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| NOT comparison
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = NOT_OP;
  $$->right_op = $2;
}
| comparison
{
  $$ = $1;
}

;

comparison : comparison LESSTHAN exp
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = LESSTHAN_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| comparison LESSTHANEQ exp
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = LESSTHANEQ_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| comparison GREATERTHAN exp
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = GREATERTHAN_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| comparison GREATERTHANEQ exp
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = GREATERTHANEQ_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| comparison EQUAL exp
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = EQUAL_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| comparison NOTEQ exp
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = NOTEQ_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| exp
{
   $$ = $1;
}

;

exp : exp PLUS term
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = ADD_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}

;
| exp MINUS term
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = MINUS_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| term
{
  $$ = $1;
}

;
term : term MULT factor
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = MULT_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| term DIV factor
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = DIV_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| term MOD factor
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = MOD_OP;
  $$->left_op = $1;
  $$->right_op = $3;
}
| factor
{
  $$ = $1;
}

;
factor : LPAREN statement RPAREN
{
  $$ = $2;
}
| MINUS factor
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = EXPR_KIND;
  $$->op_kind = U_MINUS_OP;
  $$->right_op = $2;
  // printf("%i\n", $$->op_kind);
}
| atom
{
  $$ = $1;
}

;

atom : INT
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = NUM_KIND;
  $$->value = $1;
  $$->datatype = DT_INTEGER;
}
| FLOAT
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = NUM_KIND;
  $$->value = $1;
  $$->datatype = DT_FLOAT;
}
| VARIABLE
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = VAR_KIND;
  $$->var_name = $1;
  for(int i = 0; i < 500; i++){
    if(symbol_array[i].name != NULL){
      if(strcmp($1, symbol_array[i].name) == 0){
        if(strcmp(symbol_array[i].datatype, "real") == 0){
          $$->datatype = DT_FLOAT;
        }
        else{
          $$->datatype = DT_INTEGER;
        }
      }
    }
  }
}
| VARIABLE LBRACKET statement RBRACKET
{
  $$ = malloc(sizeof(struct expression));
  $$->kind = ARRAY_KIND;
  $$->var_name = $1;
  $$->right_op = $3;
  for(int i = 0; i < 500; i++){
    if(symbol_array[i].name != NULL){
      if(strcmp($1, symbol_array[i].name) == 0){
        if(strcmp(symbol_array[i].datatype, "real") == 0){
          $$->datatype = DT_FLOAT;
        }
        else{
          $$->datatype = DT_INTEGER;
        }
      }
    }
  }
}
;

%%

int yyerror()
{
   printf("Called yyerror()\n");
   return 0;
}
