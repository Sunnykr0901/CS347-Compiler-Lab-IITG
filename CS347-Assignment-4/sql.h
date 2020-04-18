#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct or_list;
extern int yylinenumber;
typedef struct and_node{
    char *table1, *table2, *col1, *col2;
    int val1, val2;
    char *str1, *str2;
    int operation, int1, int2;
    struct and_node* next_ptr;
    int is_nested;
    struct or_list* nested_condition;
    int not_var;
} and_node;

typedef struct and_list {
    and_node* head;
    and_node* tail;
    struct and_list* next_ptr;
} and_list;

typedef struct or_list {
    and_list* head;
    and_list* tail;
} or_list;

and_list insert_and_list(struct and_list, struct and_node);
or_list insert_or_list(struct or_list, struct and_list);
int check_table_name(char* tablename);
void project(char list[100][100], int vals, char* table);
void cartesian_product(char *table1, char *table2) ;
int complement(int);
int column_index(char *, char *);
char *retval(char *, int);
char *getType(char *, int);
int compare_select(struct and_node, char *, char *);
int nested_condition_select(struct or_list, char *, char *);
int compare_equi(struct and_node, char *, char *, char *, char *);
int nested_condition_equi(struct or_list, char *, char *, char *, char *);
int check(char *, char *, struct or_list *);
int equi_join(char *, char *, struct or_list *);
