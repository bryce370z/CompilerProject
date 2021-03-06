
/* used for symbol table */
struct symbol {
    char* name;
    char* datatype;
    int dt_num;
    int address;
    char* kind;
    /* int size; */
};


#define STMT_ASSIGN 0
#define STMT_IF 1
#define STMT_IF_ELSE 2
#define STMT_WHILE 3
#define STMT_PRINT 4
#define STMT_READ 5
#define STMT_EXIT 6
#define STMT_COUNTING 7
struct statement{
  int kind; // kind of statment {while, if, assignment, etc...}
  char *var; // variable name for assignemnt statment
  int var_address; // variable address for assignment statements
  struct symbol* left_operand;
  struct symbol* right_operand;
  struct print* print;
  struct expression* var_array_expresssion;
  struct expression* expression;
  struct statement* body;
  struct statement* else_body;
  struct statement* next;
};

#define NUM_KIND 0
#define EXPR_KIND 1
#define VAR_KIND 2
#define ARRAY_KIND 3

#define ADD_OP 0
#define MINUS_OP 1
#define DIV_OP 2
#define MULT_OP 3
#define U_MINUS_OP 4
#define MOD_OP 5

#define EQUAL_OP 6
#define NOTEQ_OP 7
#define GREATERTHAN_OP 8
#define GREATERTHANEQ_OP 9
#define LESSTHAN_OP 10
#define LESSTHANEQ_OP 11

#define AND_OP 12
#define OR_OP 13
#define NOT_OP 14

#define DT_INTEGER 1
#define DT_FLOAT 2

struct expression{
  int kind; // operation {+, -, /, etc...} or number {5, 5.46, etc...}
  int op_kind; // operation {+, -, /, etc...}
  float value; // number {1,2,3,6.78, etc}
  char *var_name;// name of variable on left side of assign operator
  int datatype; // datatype of node
  struct symbol* var;
  struct expression* left_op;
  struct expression* right_op;
};

#define P_EXPR_KIND 0
#define P_STR_KIND 1
#define P_NEWLINE_KIND 2
struct print{
  int kind;
  struct expression* p_expr;
  char* p_string;
  int newline;
  struct print* next;
};

extern struct statement * stmt_list;
extern struct symbol symbol_array[500];
