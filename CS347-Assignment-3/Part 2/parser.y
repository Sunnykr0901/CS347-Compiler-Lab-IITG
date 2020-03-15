%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yylineno;
int yylinenumber;
extern char* yytext;
extern int yyleng;
void yyerror(char* s);
char list[100][100];
int vals;
%}

%code requires {
    #include "sql.h"
}

%union {
    int intval;
    char text[100];
    struct {
        char *name;
    } name;


    struct and_node and_ent;
    struct and_list list_of_and;
    struct or_list list_of_or;
    struct {
        char* table;
        char* col;
    } colattr;

    struct {
        int type;
    } op;
}

/* declare tokens */
%token SELECT PROJECT CARTESIAN_PRODUCT EQUI_JOIN
%token AND OR NOT
%token LP RP LA RA EQUAL NOT_EQUAL LE GE
%token INT QUOTED_STRING ID
%token DOT COMMA NEWLINE

%type <list_of_or> condition
%type <list_of_and> cond2
%type <and_ent> expr
%type <name> attr
%type <op> op
%type <colattr> col
%type <intval> INT;
%type <text> ID;
%type <text> QUOTED_STRING;


%%
stmt_list: stmt NEWLINE stmt_list
    | stmt
    | error NEWLINE {printf("error: syntax error in line number %d\n",yylineno-1);
        printf("================================\n\n");        
    } stmt_list    
;

stmt:  SELECT LA  RA LP ID RP
			    {
				yylinenumber = yylineno;
				char fname[200];
				memset(fname,0,200);
				sprintf(fname,"input/%s.csv",$5);
				if(check_table_name($5)==0){
				    printf("Table %s not found!\n",$5);
				}
				else{
				    FILE* file = fopen(fname,"r");
				    char str[1000];
				    fgets(str, 1000, file);
				    printf("%s", str);
				    fgets(str, 1000, file);
				    or_list condition;
				    condition.head = condition.tail = NULL;
				    int numOfRecords = 0;
				    while (fgets(str, 1000, file)) {
					sscanf(str, "%[^\n]", str);
					int returnResult = nested_condition_select(condition, str, $5);
					if (returnResult == -1){
					    break;
					}
					else if (returnResult)  {
					    printf("%s\n", str);
					    numOfRecords++;
					}
				    }
				    printf("Number of Records found : %d\n", numOfRecords);
				    fclose(file);
				}
				printf("================================\n\n");        
			    }


    | SELECT LA condition RA LP ID RP
			    {
				yylinenumber = yylineno;
				char fname[200];
				memset(fname,0,200);
				sprintf(fname,"input/%s.csv",$6);
				if(check_table_name($6)==0){
				    printf("Table %s not found!\n",$6);
				}
				else{
				    FILE* file = fopen(fname,"r");
				    char str[1000];
				    fgets(str, 1000, file);
				    printf("%s", str);
				    fgets(str, 1000, file);
				    // printf("%s", str);
				    int numOfRecords = 0;
				    while (fgets(str, 1000, file)) {
					sscanf(str, "%[^\n]", str);
					int returnResult = nested_condition_select($3, str, $6);
					if (returnResult == -1){
					    break;
					}
					else if (returnResult)  {
					    numOfRecords++;
					    printf("%s\n", str);
					}
				    }

				    printf("Number of Records found : %d\n", numOfRecords);
				    fclose(file);
				}
				printf("================================\n\n");

			    }


    | PROJECT LA attr_list RA LP ID RP
				    {
					yylinenumber = yylineno;
					if (!check_table_name($6)) {
					    fprintf(stdout, "Table %s not found\n", $6);
					}
					else {
					    project(list, vals, $6);
					}
					printf("================================\n\n");
				    }


    | LP ID RP CARTESIAN_PRODUCT LP ID RP       
				    {
					yylinenumber = yylineno;
					// printf("hello %s %s\n", $2, $6);
					cartesian_product($2, $6);
					printf("================================\n\n");
				    }


    | LP ID RP EQUI_JOIN LA condition RA LP ID RP       
				    {
					yylinenumber = yylineno;
					int numOfRecords=0;
					 // check if the two table id's exist
					if (!check_table_name($2)) {
					    fprintf(stdout, "Table %s not present\n", $2);
					}
					else if (!check_table_name($9)) {
					    fprintf(stdout, "Table %s not present\n", $9);
					}
					else {
					    // check for each condition unit.table1/2 is set and same as above id's, datatype
					    int x = check($2, $9, &($6));
					    if (x == 1) {
						numOfRecords = equi_join($2, $9, &($6));
					    }
					    printf("Number of Records found : %d\n", numOfRecords);
					}
					printf("================================\n\n");
				    }


    | %empty
;



attr_list: attr COMMA attr_list
		    {
			sprintf(list[vals], "%s", $1.name);
			vals++;
		    }
    | attr
		    {
			memset(list, 0, 10000);
			vals = 0;
			sprintf(list[0], "%s", $1.name);
			vals++;
		    }
;




condition: cond2 OR condition
		    {
			$$ = insert_or_list($3, $1); 
		    } 

    | cond2  
		    {
			$$.tail = malloc(sizeof(and_list));
			$$.head = $$.tail;
			memcpy($$.head, &$1, sizeof (and_list));
		    }
;



cond2: expr AND cond2
		    {
			$$ = insert_and_list($3, $1); 
		    }

    | expr
		    {
			$$.tail = malloc(sizeof(and_node));
			$$.head = $$.tail;
			$$.next_ptr = NULL;
			memcpy($$.head, &$1, sizeof (and_node));
		    }
;




expr: col op col 
    {
        if($1.table==NULL){ $$.table1 = $1.table; }
        else { $$.table1 = malloc(100); memset($$.table1, 0, 100); sprintf($$.table1, "%s", $1.table);}
        if($3.table==NULL){ $$.table2 = $3.table; }
        else { $$.table2 = malloc(100); memset($$.table2, 0, 100); sprintf($$.table2, "%s", $3.table);}
        $$.operation = $2.type;
        $$.int1 = 0;        $$.int2 = 0;
        $$.str1 = NULL;         $$.str2 = NULL;
	$$.col1 = malloc(100);  memset($$.col1, 0, 100);
        $$.col2 = malloc(100);  memset($$.col2, 0, 100); 
        sprintf($$.col1, "%s", $1.col);
        sprintf($$.col2, "%s", $3.col);
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    }


    | col op INT 
    {
        if($1.table==NULL){ $$.table1 = $1.table; }
        else { $$.table1 = malloc(100); memset($$.table1, 0, 100); sprintf($$.table1, "%s", $1.table);}
        $$.table2 = NULL;
        $$.operation = $2.type;
        $$.int1 = 0;    $$.int2 = 1;
        $$.val2 = $3;
        $$.str1 = NULL;     $$.str2 = NULL;
	$$.col1 = malloc(100);  memset($$.col1, 0, 100);
        $$.col2 = NULL;
        sprintf($$.col1, "%s", $1.col);
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    }


    | INT op col
    {
        if($3.table==NULL){ $$.table1 = $3.table; }
        else { $$.table1 = malloc(100); memset($$.table1, 0, 100); sprintf($$.table1, "%s", $3.table);}
        $$.table2 = NULL;
        $$.operation = complement($2.type);
        $$.int1 = 0;        $$.int2 = 1;
        $$.val2 = $1;
        $$.str1 = NULL;         $$.str2 = NULL;
	$$.col1 = malloc(100);  memset($$.col1, 0, 100);
        $$.col2 = NULL;
        sprintf($$.col1, "%s", $3.col);
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    }


   | INT op INT
    {
	$$.table1 = NULL;
        $$.table2 = NULL;
        $$.operation = $2.type;
        $$.int1 = 1;        $$.int2 = 1;
        $$.val1 = $1;           $$.val2=$3;
        $$.str1 = NULL;         $$.str2 = NULL;
	$$.col1 = NULL;
        $$.col2 = NULL;
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    } 


    | col op QUOTED_STRING
    {
        if($1.table==NULL){ $$.table1 = $1.table; }
        else { $$.table1 = malloc(100); memset($$.table1, 0, 100); sprintf($$.table1, "%s", $1.table);}
        $$.table2 = NULL;
        $$.operation = $2.type;
        $$.int1 = 0;       $$.int2 = 0;
        $$.str1 = NULL;
        $$.str2 = malloc(100); memset($$.str2, 0, 100);
        sprintf($$.str2, "%s", $3);
	$$.col1 = malloc(100);  memset($$.col1, 0, 100);
        $$.col2 = NULL;
        sprintf($$.col1, "%s", $1.col);
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    }


    | QUOTED_STRING op col
    {
        if($3.table==NULL){ $$.table1 = $3.table; }
        else { $$.table1 = malloc(100); memset($$.table1, 0, 100); sprintf($$.table1, "%s", $3.table);}
        $$.table2 = NULL;
        $$.col1 = malloc(100);  memset($$.col1, 0, 100);
        $$.col2 = NULL;
        sprintf($$.col1, "%s", $3.col);
        $$.operation = complement($2.type);
        $$.int1 = 0;      $$.int2 = 0;
        $$.str1 = NULL;
        $$.str2 = malloc(100); memset($$.str2, 0, 100);
        sprintf($$.str2, "%s", $1);
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    }

    | QUOTED_STRING op QUOTED_STRING
    {
        $$.table1 = NULL;
        $$.table2 = NULL;
        $$.operation = $2.type;
        $$.int1 = 0;       $$.int2 = 0;
        $$.str1 = malloc(100); memset($$.str1, 0, 100);
        $$.str2 = malloc(100); memset($$.str2, 0, 100);
	sprintf($$.str2, "%s", $1);
        sprintf($$.str2, "%s", $3);
	$$.col1 = NULL;
        $$.col2 = NULL;
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = NULL;
	$$.is_nested = 0;
    }


    | LP condition RP
    {   
        $$.table1 = NULL;  $$.table2 = NULL;
        $$.operation = 0;
        $$.int1 = 0;   $$.int2 = 0;
        $$.str1 = NULL;    $$.str2 = NULL;
        $$.col1 = NULL;    $$.col2 = NULL;
        $$.next_ptr = NULL;
        $$.not_var = 0;
        $$.nested_condition = malloc(sizeof(or_list));
        memcpy($$.nested_condition, &$2, sizeof (or_list));
	$$.is_nested = 1;
    }


    | NOT LP condition RP
    {   
        $$.table1 = NULL;   $$.table2 = NULL;
        $$.col1 = NULL;     $$.col2 = NULL;
        $$.int1 = 0;    $$.int2 = 0;
        $$.str1 = NULL;     $$.str2 = NULL;
	$$.operation = 0;
        $$.next_ptr = NULL;
        $$.not_var = 1;
        $$.nested_condition = malloc(sizeof(or_list));
        memcpy($$.nested_condition, &$3, sizeof (or_list));
	$$.is_nested = 1;
    }
;

col: ID DOT ID {
        $$.table = malloc(100);
	memset($$.table, 0, 100);
        sprintf($$.table, "%s", $1);
        $$.col = malloc(100);
        memset($$.col, 0, 100);
        sprintf($$.col, "%s", $3);
    }


    | ID  {
        $$.table = NULL;
        $$.col = malloc(100);
        memset($$.col, 0, 100);
        sprintf($$.col, "%s", $1);       
    }
;


op:   LA {$$.type = 1;}
    | RA {$$.type = 2;}
    | LE {$$.type = 3;}
    | GE {$$.type = 4;}
    | EQUAL {$$.type = 5;}
    | NOT_EQUAL {$$.type = 6;}
;

attr: ID   {
    $$.name = malloc(100);
    memset($$.name, 0, 100);
    sprintf($$.name, "%s", yytext);
    
};

%%
int main(int argc, char **argv)
{
  yyparse();
}

void yyerror(char *s)
{      
    // printf( "error!!: %s at line %d\n", s, yylineno);
    // fflush(stdout);
}
