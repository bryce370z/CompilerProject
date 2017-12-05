#include "y.tab.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void codegen();
void exprgen(struct expression *);
int find_symbol_address(struct symbol *symbol_p, char *s);
void allocate_stack_space(struct symbol *symbol_p);
// void gen_expr_child_datatypes(struct expression *p);
int gen_expr_datatype(struct expression *p);
char* find_symbol_dt(struct symbol *symbol_p, char *s);
void convert_datatypes(struct expression *p, int convert_index);
void assign_datatypes(struct expression *p);

char* instructions[20480];
int instruction_index = 0;

int main(){
  if(yyparse()) {
    printf("not accepted\n");
  }
  else {
    codegen();
    for(int i = 0; i < instruction_index; i++){
      printf("%s\n", instructions[i]);
    }
  }
  return 0;
}

void add_code(char* s){
  instructions[instruction_index] = s;
  instruction_index++;
  // printf("%s %i\n",s,instruction_index);
}

void add_code_int(char *s, int n){
  char buffer[100];
  sprintf(buffer, "%i", n);
  char* new_str = malloc(sizeof(char) * 100);
  strcpy(new_str , s);
  strcat(new_str, " ");
  instructions[instruction_index] = strcat(new_str, buffer);
  instruction_index++;
  // printf("%s %i\n",s,instruction_index);
}

void add_code_float(char *s, float f){
  char buffer[100];
  char* new_str = malloc(sizeof(char) * 100);
  sprintf(buffer, "%f", f);
  strcpy(new_str, s);
  strcat(new_str, " ");
  instructions[instruction_index] = strcat(new_str, buffer);
  instruction_index++;
  // printf("%s %i\n",s,instruction_index);
}
void codegen(){
  allocate_stack_space(symbol_array);
  struct statement *p;
  p = stmt_list;
  while(p != NULL){
    int kind = p->kind;
    if(kind == STMT_ASSIGN){
      int var_address = find_symbol_address(symbol_array, p->var);
      if(var_address != -1){
        add_code_int("LAA", var_address);
        if(p->var_array_expresssion != NULL){
          exprgen(p->var_array_expresssion);
          add_code("ADI");
        }
        exprgen(p->expression);
        add_code("STO");
      }
      else{
        printf("ERROR: Invalid variable assignment.\n");
        exit(0);
      }
    }
    p = p->next;
  }
  return;
}

void exprgen(struct expression *p)
{
  if(p->kind == NUM_KIND){
    if(p->datatype == DT_INTEGER){
      add_code_int("LLI", p->value);
    }
    else{
      add_code_float("LLF", p->value);
    }
  }
  else if(p->kind == VAR_KIND){
    int var_address = find_symbol_address(symbol_array, p->var_name);
    if(var_address != -1){
      add_code_int("LAA", var_address);
      add_code("LOD");
    }
    else{
      printf("Variable is undeclared.\n");
      exit(0);
    }
  }
  else if(p->kind == ARRAY_KIND){
    int var_address = find_symbol_address(symbol_array, p->var_name);
    if(var_address != -1){
      add_code_int("LAA", var_address);
      exprgen(p->right_op);
      add_code("LOD");
    }
  }
   else {
      int convert_index = 0;
      switch (p->op_kind) {
         case ADD_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("ADI");
          }
          else{
            add_code("ADF");
          }
          break;
        case MINUS_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("SBI");
          }
          else{
            add_code("SBF");
          }
          break;
        case DIV_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("DVI");
          }
          else{
            add_code("DVF");
          }
          break;
        case MULT_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("MLI");
          }
          else{
            add_code("MLF");
          }
          break;
        case U_MINUS_OP:
          exprgen(p->right_op);
          p->datatype = p->right_op->datatype;
          if(p->datatype == DT_INTEGER){
            add_code("NGI");
          }
          else{
            add_code("NGF");
          }
          break;
        case EQUAL_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("EQI");
          }
          else{
            add_code("EQF");
          }
          break;
        case NOTEQ_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("NEI");
          }
          else{
            add_code("NEF");
          }
          break;
        case GREATERTHAN_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("GTI");
          }
          else{
            add_code("GTF");
          }
          break;
        case GREATERTHANEQ_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("GEI");
          }
          else{
            add_code("GEF");
          }
          break;
        case LESSTHAN_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("LTI");
          }
          else{
            add_code("LTF");
          }
          break;
        case LESSTHANEQ_OP:
          exprgen(p->left_op);
          convert_index = instruction_index;
          add_code("NOP");
          exprgen(p->right_op);
          convert_datatypes(p, convert_index);
          if(p->datatype == DT_INTEGER){
            add_code("LEI");
          }
          else{
            add_code("LEF");
          }
          break;
        case AND_OP:
          p->datatype = DT_INTEGER;
          exprgen(p->left_op);
          if(p->left_op->datatype == DT_INTEGER){
            add_code_int("LLI", 0);
            add_code("NEI");
          }
          else{
            add_code_int("LLF", 0);
            add_code("NEF");
          }
          exprgen(p->right_op);
          if(p->right_op->datatype == DT_INTEGER){
            add_code_int("LLI", 0);
            add_code("NEI");
          }
          else{
            add_code_int("LLF", 0);
            add_code("NEF");
          }
          add_code("MLI");
          break;
        case OR_OP:
          p->datatype = DT_INTEGER;
          exprgen(p->left_op);
          if(p->left_op->datatype == DT_INTEGER){
            add_code_int("LLI", 0);
            add_code("NEI");
          }
          else{
            add_code_int("LLF", 0);
            add_code("NEF");
          }
          exprgen(p->right_op);
          if(p->right_op->datatype == DT_INTEGER){
            add_code_int("LLI", 0);
            add_code("NEI");
          }
          else{
            add_code_int("LLF", 0);
            add_code("NEF");
          }
          add_code("ADI");
          break;
        case NOT_OP:
          exprgen(p->right_op);
          if(p->right_op->datatype == DT_INTEGER){
            add_code_int("LLI", 0);
            add_code("MLI");
          }
          else{
            add_code_int("LLF", 0);
            add_code("MLF");
          }
          break;
      }
   }
   return;
}

void allocate_stack_space(struct symbol *symbol_p){
  int increment_stack = 0;
  for(int i = 0; i < 500; i++){
    if(symbol_p[i].name != NULL){
      increment_stack++;
    }
    else{
      add_code_int("ISP", increment_stack);
      return;
    }
  }
}

void convert_datatypes(struct expression *p, int convert_index){
  if(p->left_op->datatype != p->right_op->datatype){
    if(p->left_op->datatype == DT_INTEGER){
      instructions[convert_index] = "ITF";
      p->datatype = DT_FLOAT;
    }
    else{
      add_code("ITF");
      p->datatype = DT_FLOAT;
    }
  }
  else{
    p->datatype = p->left_op->datatype;
  }
}

int find_symbol_address(struct symbol *symbol_p, char *s){
  for(int i = 0; i < 500; i++){
    char *current_name = symbol_p[i].name;
    if(current_name != NULL && strcmp(current_name, s) == 0){
      // printf("MATCH\n");
      return symbol_p[i].address;
    }
  }
  return -1;

}
