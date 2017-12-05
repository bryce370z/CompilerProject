#include "y.tab.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void codegen();
void exprgen(struct expression *);
void allocate_stack_space(struct symbol *symbol_p);
void get_symbol(struct symbol* left_operand, struct symbol* symbol_p, char *s);
void convert_datatypes(struct expression *p, int convert_index);

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
      p->left_operand = malloc(sizeof(struct symbol));
      get_symbol(p->left_operand, symbol_array, p->var);
      if(p->left_operand->name != NULL){
        int var_address = p->left_operand->address;
        add_code_int("LAA", var_address);
        if(p->var_array_expresssion != NULL){
          exprgen(p->var_array_expresssion);
          if(p->var_array_expresssion->datatype == DT_FLOAT){
            add_code("FTI");
          }
          add_code("ADI");
        }
        exprgen(p->expression);
        if(p->left_operand->dt_num != p->expression->datatype){
          if(p->left_operand->dt_num == DT_INTEGER){
            add_code("FTI");
          }
          else{
            add_code("ITF");
          }
        }
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
  int convert_index = 0;
  if(p->kind == NUM_KIND){
    if(p->datatype == DT_INTEGER){
      add_code_int("LLI", p->value);
    }
    else{
      add_code_float("LLF", p->value);
    }
  }
  else if(p->kind == VAR_KIND){
    p->var = malloc(sizeof(struct symbol));
    get_symbol(p->var, symbol_array, p->var_name);
    if(p->var->name != NULL){
      int var_address = p->var->address;
      add_code_int("LAA", var_address);
      add_code("LOD");
    }
    else{
      printf("Variable is undeclared.\n");
      exit(0);
    }
  }
  else if(p->kind == ARRAY_KIND){
    get_symbol(p->var, symbol_array, p->var_name);
    if(p->var->name != NULL){
      int var_address = p->var->address;
      add_code_int("LAA", var_address);
      exprgen(p->right_op);
      add_code("LOD");
    }
  }
   else {
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
          add_code("LLI 0");
          add_code("NEI");
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
      increment_stack = symbol_p[i].address;
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

void get_symbol(struct symbol* left_operand, struct symbol* symbol_p, char *s){
  for(int i = 0; i < 500; i++){
    char* current_name = symbol_p[i].name;
    if(current_name != NULL && strcmp(current_name, s) == 0){
      left_operand->name = current_name;
      left_operand->datatype = symbol_p[i].datatype;
      left_operand->address = symbol_p[i].address;
      if(strcmp(left_operand->datatype, "integer") == 0){
        left_operand->dt_num = DT_INTEGER;
      }
      else{
        left_operand->dt_num = DT_FLOAT;
      }
      return;
    }
  }

}
