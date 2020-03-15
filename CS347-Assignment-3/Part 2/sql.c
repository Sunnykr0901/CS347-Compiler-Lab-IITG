#include "sql.h"







int check_table_name(char* tablename){
  char table[200];
    memset(table, 0, 200);
    sprintf(table, "input/%s.csv", tablename);
    FILE* f = fopen(table,"r");
	if(f==NULL)
		return 0;
	
	fclose(f);
	return 1;
}

void project(char list[100][100], int vals, char* table){
    char table_name[100];
    memset(table_name, 0, 100);
    sprintf(table_name, "input/%s.csv", table);

    FILE* f = fopen(table_name,"r");
    char str[1000];
    char str2[1000];
    int arr[100];
    int count=0;
    memset(arr,0,100*sizeof(arr[0]));
    const char s[2] = ",";
    fgets(str, 1000, f);
    sscanf(str, "%[^\n]s", str);
    int t=count-1;	
    char *token;
    strcpy(str2,str);
    token = strtok(str, s);
    int j=0;
    while( token != NULL ) {
        for(int i=0;i<vals;i++){
            if(strcmp(list[i],token)==0){
                count++;
                arr[j]++;break;
            }
        }
	/*if(count==t){
		printf("Error:- Column  with name '%s' does not exist in table %s\n",token,table);
	}*/
        token = strtok(NULL, s);       
        j++;  t++;
    }
    
    if(count != vals){
        printf("Error: some requested column does not exist in %s\n",table);
        return;
    }
    token = strtok(str2, s);
    j=0;
    while( token != NULL ) {
        if(arr[j]){
            printf( "%s ", token );
        }
        token = strtok(NULL, s);       
        j++;  
    }
    printf("\n");
    int numOfRecords = 0;
    fgets(str, 1000, f);
    while(fgets(str, 1000, f)){
        int j=0;
        char *token;
        sscanf(str, "%[^\n]s", str);
        numOfRecords++;
        token = strtok(str, s);
        while( token != NULL ) {
            if(arr[j]){
                printf( "%s ", token );
            }
            token = strtok(NULL, s);
            j++;
        }
        printf("\n");
    }
    printf("Number of Records found : %d\n", numOfRecords);
    fclose(f);
}

void cartesian_product(char *table1, char *table2) {
    char table1Name[200];
    memset(table1Name, 0, 200);
    sprintf(table1Name, "input/%s.csv", table1);
    char table2Name[200];
    memset(table2Name, 0, 200);
    sprintf(table2Name, "input/%s.csv", table2);
    int a = check_table_name(table1);
    int b = check_table_name(table2);
    if (a == 0) {
        fprintf(stderr, "Table %s not present\n", table1);
        return;
    }
    else if (b == 0) {
        fprintf(stderr, "Table %s not present\n", table2);
        return;
    }
    // both files present
    FILE* file1 = fopen(table1Name,"r");
    FILE* file2 = fopen(table2Name,"r");

    char str1[1000];
    fgets(str1, 1000, file1);
    sscanf(str1, "%[^\n]s", str1);
    char *token1;
    const char *s = ",";
    token1 = strtok(str1, s);
    while( token1 != NULL ) {
        printf( "%s.%s, ", table1, token1);
        token1 = strtok(NULL, s);        
    }
    char str2[1000];
    fgets(str2, 1000, file2);
    char *token2;
    token2 = strtok(str2, s);
    while( token2 != NULL ) {
        printf( "%s.%s", table2, token2);
        token2 = strtok(NULL, s);
        if (token2 != NULL) printf(", ");        
    }
    fgets(str1, 1000, file1);
    fgets(str2, 1000, file2);
    fclose(file2);
    int numOfRecords = 0;
    while(fgets(str1, 1000, file1)) {
        sscanf(str1, "%[^\n]s", str1);
        file2 = fopen(table2Name,"r");
        fgets(str2, 1000, file2);
        fgets(str2, 1000, file2);
        
        while (fgets(str2, 1000, file2)) {
            printf("%s", str1);
            printf(",%s", str2);
            numOfRecords++;
        } 
        fclose(file2);     
    }
    printf("Number of Records found : %d\n", numOfRecords);
    fclose(file1);
}







and_list insert_and_list(struct and_list cond2, struct and_node expr){
    and_node* new_elem = malloc(sizeof(and_node));
    memcpy(new_elem, &expr, sizeof (and_node));
    cond2.tail->next_ptr = new_elem;

    cond2.tail = new_elem;
    return cond2;
}

or_list insert_or_list(struct or_list condition, struct and_list cond2){
    and_list* new_elem = malloc(sizeof(and_list));
    memcpy(new_elem, &cond2, sizeof (and_list));
    condition.tail->next_ptr = new_elem;
    condition.tail = new_elem;
    return condition;
}




int complement(int op) {
    if (op == 1) {
        return 2;
    }
    else if (op == 2) {
        return 1;
    }
    else if (op == 3) {
        return 4;
    }
    else if (op == 4) {
        return 3;
    }
    else if (op == 5) {
        return 5;
    }
    else if (op == 6) {
        return 6;
    }     
}

int column_index(char *table, char *column) {
    char tablecopy[200];
    memset(tablecopy,0,200);
    sprintf(tablecopy,"input/%s.csv",table);
    FILE* file = fopen(tablecopy, "r");
    char str[1000];
    char *token;
    const char s[2] = ",";
    int j = 0;
    fgets(str, 1000, file);
    sscanf(str, "%[^\n]", str);
    token = strtok(str, s);
    while( token != NULL ) {
        if (strcmp(token, column) == 0) {
            fclose(file);
            return j;
        }
        j++;
        token = strtok(NULL, s);
    }    
    fclose(file);
    return -1; 
}

char *retval(char *str, int colIndex) {
    char *token;
    const char s[2] = ",";
    token = strtok(str, s);
    int j = 0;
    while( token != NULL ) {
        if (colIndex == j) return token;
        token = strtok(NULL, s);
        j++;         
    }
}

char *getType(char *table, int colIndex){
    char tablecopy[200];
    memset(tablecopy,0,200);
    sprintf(tablecopy,"input/%s.csv",table);
    FILE* file = fopen(tablecopy, "r");
    char str[1000];
    char *token;
    const char s[2] = ",";
    int j = 0;
    fgets(str, 1000, file);
    fgets(str, 1000, file);
    sscanf(str, "%[^\n]", str);
    token = strtok(str, s);
    char data_type[10];
    memset(data_type, 0, 10);
    while( token != NULL ) {
        if (colIndex == j) {
            fclose(file);
            return token;
        }
        token = strtok(NULL, s);
        j++;  
    }    
    fclose(file);
    return NULL;
}

int compareByOp(int val1, int val2, int op) {
    if (op == 1) {
        return val1 < val2;
    }
    else if (op == 2) {
        return val1 > val2;
    }
    else if (op == 3) {
        return val1 <= val2;
    }
    else if (op == 4) {
        return val1 >= val2;
    }
    else if (op == 5) {
        return val1 == val2;
    }
    else if (op == 6) {
        return val1 != val2;
    } 
    return 1;   
}

int compareStringByOp(char *str1, char *str2, int op){
    int returnType = strcmp(str1, str2);
    switch (op)
    {
        case 1: if(returnType < 0) return 1;
            break;
        case 2: if(returnType > 0) return 1;
            break;
        case 3: if(returnType <= 0) return 1;
            break;
        case 4: if(returnType >= 0) return 1;
            break;
        case 5: if(returnType == 0) return 1; 
            break;
        case 6: if(returnType != 0) return 1;
            break;
        default:
            break;
    }
    return 0;
}
 
int compare_select(struct and_node entry_node, char *str1, char* table_name) {//printf("1 ");
     if (entry_node.int1==1 && entry_node.int2==1) {            //INT op INT
        return compareByOp(entry_node.val1, entry_node.val2, entry_node.operation);
	}

     else if(entry_node.str1 != NULL && entry_node.str2!=NULL){    // QUOTED_STRING op QUOTED_STRING
        return compareStringByOp(entry_node.str1, entry_node.str2, entry_node.operation);
    }

    else if (entry_node.int2) {        // col op INT
        if(entry_node.table1 != NULL && strcmp(entry_node.table1, table_name)!=0){
            printf("Associated table name %s winot correct. Actual table name : %s\n", entry_node.table1, table_name);
            return -1;
        }
        int colIndex = column_index(table_name, entry_node.col1);
        if (colIndex == -1) {
            printf("Column %s not found in table %s\n", entry_node.col1, table_name);
            return -1;
        }
        char *data_type = getType(table_name, colIndex);
        if(strcmp(data_type,"int") != 0){
            printf("Data Type mismatch\n");
            return -1;
        }
        entry_node.val1 = atoi(retval(str1, colIndex));
        return compareByOp(entry_node.val1, entry_node.val2, entry_node.operation);
    }
    else if(entry_node.str1 == NULL && entry_node.str2!=NULL){   //printf("2 ");// COL op QUOTED_STRING
        if(entry_node.table1 != NULL && strcmp(entry_node.table1, table_name)!=0){
            printf("Associated table name %s not correct. Actual table name : %s\n", entry_node.table1, table_name);
            return -1;
        }
        int colIndex = column_index(table_name, entry_node.col1);
        if (colIndex == -1) {
            printf("Column %s not found in table %s\n", entry_node.col1, table_name);
            return -1;
        }
        char *data_type = getType(table_name, colIndex);
        if(strcmp(data_type,"str") != 0){
            printf("Data Type mismatch\n");
            return -1;
        }
	
        entry_node.str1 = retval(str1, colIndex);//printf("%s ",entry_node.str1);
	//sprintf(entry_node.str1,"\'%s'",entry_node.str1);
	//entry_node.str1="'"+entry_node.str1+"'";
	//printf("%s%d%s  ",entry_node.str1,entry_node.operation,entry_node.str2);
         return compareStringByOp(entry_node.str1, entry_node.str2, entry_node.operation);
	//return 0;
    }

    else {           //COL op COL
        if(entry_node.table2 != NULL && strcmp(entry_node.table2, table_name)!=0){
            printf("Associated table name %s not correct. Actual table name : %s\n", entry_node.table2, table_name);
            return -1;
        }
        if(entry_node.table1 != NULL && strcmp(entry_node.table1, table_name)!=0){
            printf("Associated table name %s not correct. Actual table name : %s\n", entry_node.table1, table_name);
            return -1;
        }
        int colIndex1 = column_index(table_name, entry_node.col1);
        int colIndex2 = column_index(table_name, entry_node.col2);
        if (colIndex1 == -1) {
            printf("Column %s not found in table %s\n", entry_node.col1, table_name);
            return -1;
        }
        if (colIndex2 == -1) {
            printf("Column %s not found in table %s\n", entry_node.col2, table_name);
            return -1;
        }
        if(strcmp(getType(table_name, colIndex1),getType(table_name, colIndex2)) != 0){
            printf("Data Type mismatch\n");
            return -1;
        }
        if(strcmp(getType(table_name, colIndex1), "str")){
            entry_node.str1 = retval(str1, colIndex1);
            entry_node.str2 = retval(str1, colIndex2);
            return compareStringByOp(entry_node.str1, entry_node.str2, entry_node.operation);
        }
        else{
            entry_node.val1 = atoi(retval(str1, colIndex1));
            entry_node.val2 = atoi(retval(str1, colIndex2));
            return compareByOp(entry_node.val1, entry_node.val2, entry_node.operation);
        }
    }
    return -1;    
}

int nested_condition_select(struct or_list condition, char *str, char* table_name){
    and_list* temp = condition.head;
    if(temp == NULL) return 1;
    int result = 0;
    
    while(temp!=NULL){
        and_node* temp2 = temp->head;
        int val = 1;
        while(temp2!=NULL){
            char str_copy[1000];
            memset(str_copy, 0, 1000);
            sprintf(str_copy, "%s", str);
            int ret;
            if (temp2->is_nested == 1) {
                ret = nested_condition_select(*(temp2->nested_condition), str_copy, table_name);
            }
            else {
                ret = compare_select(*temp2, str_copy, table_name);
            }
            if(ret == -1){
                return -1;
            }
            if(temp2->is_nested ==1 && temp2->not_var){
                ret = ret==0?1:0; 
            }
            val = val & ret;
            temp2 = temp2->next_ptr;
        }
        if(val==1){
            return 1;
        }
        result = result | val;
        temp = temp->next_ptr;
    }
    return result;
}

int compare_equi(struct and_node entry_node, char *str1, char *str2, char *table1, char *table2) {

    if (entry_node.int1==1 && entry_node.int2==1) {            //INT op INT
        return compareByOp(entry_node.val1, entry_node.val2, entry_node.operation);
	}

     else if(entry_node.str1 != NULL && entry_node.str2!=NULL){    // QUOTED_STRING op QUOTED_STRING
        return compareStringByOp(entry_node.str1, entry_node.str2, entry_node.operation);
    }


    else if (entry_node.int2) { // col op INT
        int colIndex = column_index(entry_node.table1, entry_node.col1);
        if (colIndex == -1) {
            printf("Column %s not found in table %s\n", entry_node.col1, entry_node.table1);
            return -1;
        }
        if (strcmp(entry_node.table1, table1) == 0)
            entry_node.val1 = atoi(retval(str1, colIndex));
        else 
            entry_node.val1 = atoi(retval(str2, colIndex));
        return compareByOp(entry_node.val1, entry_node.val2, entry_node.operation);
    }
    else if (entry_node.str1 == NULL && entry_node.str2 != NULL) { // col op str
        int colIndex = column_index(entry_node.table1, entry_node.col1);
        if (colIndex == -1) {
            printf("Column %s not found in table %s\n", entry_node.col1, entry_node.table1);
            return -1;
        }
        if (strcmp(entry_node.table1, table1) == 0){
            entry_node.str1 = retval(str1, colIndex);
        }
        else{
            entry_node.str1 = retval(str2, colIndex);   
        }
        return compareStringByOp(entry_node.str1, entry_node.str2, entry_node.operation);
    }
    else { // col op col
        int colIndex1 = column_index(entry_node.table1, entry_node.col1);
        int colIndex2 = column_index(entry_node.table2, entry_node.col2);
        if (colIndex1 == -1) {
            printf("Column %s not found in table %s\n", entry_node.col1, entry_node.table1);
            return -1;
        }
        if (colIndex2 == -1) {
            printf("Column %s not found in table %s\n", entry_node.col2, entry_node.table2);
            return -1;
        }
        char d1[50];
        sprintf(d1, "%s", getType(entry_node.table1, column_index(entry_node.table1, entry_node.col1)));
        if (strcmp(d1, "int") == 0) {
            if (strcmp(entry_node.table1, table1) == 0)
                entry_node.val1 = atoi(retval(str1, colIndex1));
            else 
                entry_node.val1 = atoi(retval(str2, colIndex1));

            if (strcmp(entry_node.table2, table2) == 0)
                entry_node.val2 = atoi(retval(str2, colIndex2));
            else 
                entry_node.val2 = atoi(retval(str1, colIndex2));

            return compareByOp(entry_node.val1, entry_node.val2, entry_node.operation);
        }
        else if (strcmp(d1, "str") == 0) {
            if (strcmp(entry_node.table1, table1) == 0)
                entry_node.str1 = retval(str1, colIndex1);
            else 
                entry_node.str1 = retval(str2, colIndex1);

            if (strcmp(entry_node.table2, table2) == 0)
                entry_node.str2 = retval(str2, colIndex2);
            else 
                entry_node.str2 = retval(str1, colIndex2);

            return compareStringByOp(entry_node.str1, entry_node.str2, entry_node.operation);
        }
    }
    return -1;    
}

int nested_condition_equi(struct or_list condition, char *str1, char *str2, char *table1, char *table2){
    and_list* temp = condition.head;
    int result = 0;
    
    while(temp!=NULL){
        and_node* temp2 = temp->head;
        int val = 1;
        while(temp2!=NULL){
            char str_copy1[1000];
            memset(str_copy1, 0, 1000);
            sprintf(str_copy1, "%s", str1);
            char str_copy2[1000];
            memset(str_copy2, 0, 1000);
            sprintf(str_copy2, "%s", str2);
            int ret;
            if(temp2->is_nested == 1){
                ret = nested_condition_equi(*(temp2->nested_condition), str_copy1, str_copy2, table1, table2);
            } else {
                ret = compare_equi(*temp2, str_copy1, str_copy2, table1, table2);
            }
            if(ret == -1){
                return -1;
            }
            if(temp2->is_nested ==1 && temp2->not_var){
                ret = ret==0?1:0; 
            }
            val = val & ret;
            temp2 = temp2->next_ptr;
        }
        if(val==1){
            return 1;
        }
        result = result | val;
        temp = temp->next_ptr;
    }
    return result;
}

int check(char *table1, char *table2, struct or_list *conditions) {
    and_list *temp = conditions->head;
    while(temp != NULL) {
        and_node* temp2 = temp->head;
        while (temp2 != NULL) {
            if (temp2->is_nested == 1) {
                if (check(table1, table2, temp2->nested_condition) == -1) return -1;
            }
            else {
                if (temp2->int2) { // col op INT
                    if (temp2->table1 == NULL) {
                        if (column_index(table1, temp2->col1) != -1 && column_index(table2, temp2->col1) != -1) {
                            fprintf(stdout, "line no.: %d Column %s belongs to both %s and %s\n", yylinenumber, temp2->col1, table1, table2);
                            return -1;
                        }
                        else if (column_index(table1, temp2->col1) != -1) temp2->table1 = table1;
                        else if (column_index(table2, temp2->col1) != -1) temp2->table1 = table2;
                        else {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber, temp2->col1, table1, table2);
                            return -1;
                        }
                    }
                    else {
                        if (strcmp(temp2->table1, table1) != 0 && strcmp(temp2->table1, table2) != 0) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col1, table1, table2);
                            return -1;
                        }
                        else if (column_index(temp2->table1, temp2->col1) == -1) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s\n",yylinenumber, temp2->col1, temp2->table1);
                            return -1;
                        }
                    }
                    char d1[50];
                    sprintf(d1, "%s", getType(temp2->table1, column_index(temp2->table1, temp2->col1)));
                    if (strcmp(d1, "int") != 0) {
                        fprintf(stdout, "line no.: %d %s is %s not INT\n", yylinenumber,temp2->col1, d1);
                        return -1;
                    }
                }
                else if (temp2->str2 != NULL) { // col op str
                    if (column_index(table1, temp2->col1) != -1 && column_index(table2, temp2->col1) != -1) {
                        fprintf(stdout, "line no.: %d Column %s belongs to both %s and %s\n", yylinenumber, temp2->col1, table1, table2);
                        return -1;
                    }
                    if (temp2->table1 == NULL) {
                        if (column_index(table1, temp2->col1) != -1) temp2->table1 = table1;
                        else if (column_index(table2, temp2->col1) != -1) temp2->table1 = table2;
                        else {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col1, table1, table2);
                            return -1;
                        }
                    }
                    else {
                        if (strcmp(temp2->table1, table1) != 0 && strcmp(temp2->table1, table2) != 0) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col1, table1, table2);
                            return -1;
                        }
                        else if (column_index(temp2->table1, temp2->col1) == -1) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s\n", yylinenumber,temp2->col1, temp2->table1);
                            return -1;
                        }
                    }
                    char d1[50];
                    sprintf(d1, "%s", getType(temp2->table1, column_index(temp2->table1, temp2->col1)));
                    if (strcmp(d1, "str") != 0) {
                        fprintf(stdout, "line no.: %d %s is %s not str\n", yylinenumber,temp2->col1, d1);
                        return -1;
                    }
                }
                else { // col op col
                    if (temp2->table1 == NULL) {
                        if (column_index(table1, temp2->col1) != -1 && column_index(table2, temp2->col1) != -1) {
                            fprintf(stdout, "line no.: %d Column %s belongs to both %s and %s\n", yylinenumber, temp2->col1, table1, table2);
                            return -1;
                        }
                        if (column_index(table1, temp2->col1) != -1) temp2->table1 = table1;
                        else if (column_index(table2, temp2->col1) != -1) temp2->table1 = table2;
                        else {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col1, table1, table2);
                            return -1;
                        }
                    }
                    else {
                        if (strcmp(temp2->table1, table1) != 0 && strcmp(temp2->table1, table2) != 0) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col1, table1, table2);
                            return -1;
                        }
                        else if (column_index(temp2->table1, temp2->col1) == -1) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s\n", yylinenumber,temp2->col1, temp2->table1);
                            return -1;
                        }
                    }
                    if (temp2->table2 == NULL) {
                        if (column_index(table1, temp2->col1) != -1 && column_index(table2, temp2->col1) != -1) {
                            fprintf(stdout, "line no.: %d Column %s belongs to both %s and %s\n", yylinenumber, temp2->col1, table1, table2);
                            return -1;
                        }
                        if (column_index(table1, temp2->col2) != -1) temp2->table2 = table1;
                        else if (column_index(table2, temp2->col2) != -1) temp2->table2 = table2;
                        else {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col2, table1, table2);
                            return -1;
                        }
                    }
                    else {
                        if (strcmp(temp2->table2, table1)!=0 && strcmp(temp2->table2, table2) != 0) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s or %s\n", yylinenumber,temp2->col2, table1, table2);
                            return -1;
                        }
                        else if (column_index(temp2->table2, temp2->col2) == -1) {
                            fprintf(stdout, "line no.: %d Column %s does not belong to %s\n", yylinenumber,temp2->col2, temp2->table2);
                            return -1;
                        }
                    }
                    char d1[50], d2[50];
                    sprintf(d1, "%s", getType(temp2->table1, column_index(temp2->table1, temp2->col1)));
                    sprintf(d2, "%s", getType(temp2->table2, column_index(temp2->table2, temp2->col2)));
                    if (strcmp(d1, d2) != 0) {
                        fprintf(stdout, "line no.: %d Different data type %s %s\n", yylinenumber,temp2->col1, temp2->col2);
                        return -1;
                    }
                }
                
            }
            temp2 = temp2->next_ptr;
        }
        temp = temp->next_ptr;
    }
    return 1;
}

int equi_join(char *table1, char *table2, struct or_list *conditions) {
    char table1Name[200];
    memset(table1Name, 0, 200);
    sprintf(table1Name, "input/%s.csv", table1);
    char table2Name[200];
    memset(table2Name, 0, 200);
    sprintf(table2Name, "input/%s.csv", table2);

    FILE* file1 = fopen(table1Name,"r");
    FILE* file2 = fopen(table2Name,"r");

    char str1[1000];
    fgets(str1, 1000, file1);
    sscanf(str1, "%[^\n]s", str1);
    char *token1;
    const char *s = ",";
    token1 = strtok(str1, s);
    while (token1 != NULL) {
        printf( "%s.%s, ", table1, token1);
        token1 = strtok(NULL, s);        
    }
    char str2[1000];
    fgets(str2, 1000, file2);
    char *token2;
    token2 = strtok(str2, s);
    while (token2 != NULL) {
        printf( "%s.%s", table2, token2);
        token2 = strtok(NULL, s);
        if (token2 != NULL) printf(", ");        
    }
    fgets(str1, 1000, file1);
    fgets(str2, 1000, file2);
    fclose(file2);
    int numOfRecords = 0;
    while(fgets(str1, 1000, file1)) {
        sscanf(str1, "%[^\n]s", str1);

        file2 = fopen(table2Name,"r");
        fgets(str2, 1000, file2);
        fgets(str2, 1000, file2);
        while (fgets(str2, 1000, file2)) {
            if (nested_condition_equi(*conditions, str1, str2, table1, table2)) {
                printf("%s", str1);
                printf(",%s", str2);
                numOfRecords++;
            };
        } 
        fclose(file2);     
    }
    fclose(file1);
    return numOfRecords;
}
