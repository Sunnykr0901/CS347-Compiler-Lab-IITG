%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void remove_comments(FILE*, FILE*);
    void count_rise(void);
    void class_add(char*);
    int class_check(char*);
    void print_classes();
    void objects(char*);


    char temp[1460];
    char classes[10000][200];
    int tempi=0;
    int no_of_classes = 0;
    int no_of_inherited_classes = 0;
    int no_of_constructors=0;
    int no_of_overloading=0;
    int no_of_objects=0;
    int class_group = 0;
    int inherited_group = 0;
    int constructor_group = 0;
    int operator_group = 0;
    int object_group=0;
%}

wd   [A-Za-z_0-9]
st   [A-Za-z_]
OP \+=|-=|\*=|\/=|%=|\^=|&=|\|=|<<|>>|>>=|<<=|==|!=|<=|>=|<=>|&&|\|\||\+\+|--|\,|->\*|\\->|\(\s*\)|\[\s*\]|\+|-|\*|\/|%|\^|&|\||~|!|=|<|>
dec   public|private|protected

%option noyywrap
%x S1 S2 S3 A1 C1 C2 C3 C4 C5 X1 X2 X3 D1 D2 D3 D4 E1 E2 E3 E4 E5
%%
"/*"                  BEGIN(S2);
<S2>[^*]              ;
<S2>"*"               BEGIN(S3);
<S3>"*"               ;
<S3>[^*/]             BEGIN(S2);
<S3>"/"               BEGIN(INITIAL);

<X2>[^*]              ;
<X2>"*"               BEGIN(X3);
<X3>"*"               ;
<X3>[^*/]             BEGIN(X2);
<X3>"/"               BEGIN(C2);

"//"[^\n]*            count_rise(); 

[^A-Za-z_]operator" "*{OP}" "*([^\{\;\n]*)[\n\{]     {operator_group = 1; if(yytext[yyleng-1]=='\n'){count_rise();}}

[^A-Za-z0-9_]class[ ]+    { if(yytext[0] == '\n'){count_rise();} BEGIN(C1); }
<C1>{st}{wd}*             {memset(temp, 0, sizeof(temp)) ; snprintf(temp, 200, "%s", yytext); BEGIN(C2) ; }
<C2>[ \t]                 { BEGIN(C2) ; } 
<C2>\n                    { class_group = 1; count_rise(); if(class_check(temp)==0){class_add(temp);} BEGIN(INITIAL);}
<C2>"{"                   { class_group = 1; if(class_check(temp)==0){class_add(temp);} BEGIN(INITIAL); }
<C2>":"                   { BEGIN(C3); }  
<C2>"/*"                  { BEGIN(X2); }
<C2>[^\n{:]               { class_add(temp); BEGIN(INITIAL);}
<C3>[ \t]                 { BEGIN(C3); }
<C3>{dec}                 { BEGIN(C3); }
<C3>{st}{wd}*             { BEGIN(C4); }
<C4>[ \t]                 { BEGIN(C4); }
<C4>","                   { BEGIN(C3); }
<C4>\n                    { inherited_group = 1, class_group = 1; count_rise(); if(class_check(temp)==0){class_add(temp);} BEGIN(INITIAL);}
<C4>"{"                   { class_group = 1, inherited_group = 1; if(class_check(temp)==0){class_add(temp);} BEGIN(INITIAL); }
<C4>[^,\n{ ]              { class_add(temp); BEGIN(INITIAL);}


[~]                       { BEGIN(E1);}
<E1>{st}{wd}*             { BEGIN(E1); }
<E1>[ \t]                 ;
<E1>[(]                   { BEGIN(E3);}
<E3>[^)]                  ;
<E3>[)]                   { BEGIN(E4);}
<E4>[ ]                   { BEGIN(E4);}
<E4>[{:]                  { BEGIN(INITIAL);}
<E4>\n                    { count_rise(); BEGIN(INITIAL);}
<E4>[^\n{:]               { BEGIN(INITIAL);} 


{st}{wd}*[ ]*[(]          { memset(temp, 0, sizeof(temp)) ; sscanf(yytext, "%[A-Za-z0-9_]s", temp); BEGIN(D3) ;}
<D1>[ \t]                 { BEGIN(D1);}
<D1>[(]                   { BEGIN(D3);}
<D3>[^)]                  { BEGIN(D3);}
<D3>[)]                   { BEGIN(D4);}
<D4>[ \t]                 { BEGIN(D4);}
<D4>[{:]                  { if (class_check(temp)){ constructor_group = 1;} BEGIN(INITIAL);}
<D4>\n                    { if (class_check(temp)) {constructor_group = 1;}count_rise(); BEGIN(INITIAL);}
<D4>[^\n{:]               { BEGIN(INITIAL);} 

.                         ;    
\n                        { count_rise();}

{st}{wd}*[*]*[ ]+[*]*[A-Za-z0-9_,][A-Za-z0-9_,\.\[\] ()]*[^\n;<>]*;  {objects(yytext);}      

%%
void class_add(char *temp){
    snprintf(classes[tempi], 200, "%s", temp);
    tempi++;
}

int class_check(char *class_name){
    int i;
    for(i=0;i<tempi;i++){
        if(strcmp(class_name, classes[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void objects(char *char_temp){
    char class_name[250];
    memset(class_name, 0, sizeof(class_name));
    sscanf(char_temp, "%s", class_name);
    int length = strlen(class_name);
    while(class_name[length-1] == '*') {
        class_name[length-1] = '\0';
        length--;
    }
    if(strstr(char_temp, "operator") && strstr(char_temp, "{")){
        operator_group=1;
        return;
    }
    if(class_check(class_name)){
        object_group = 1;
    }
}
void print_classes(){
    int i;
    printf("Printing classes : \n");
    for(i=0;i<tempi;i++){
        printf("%s ", classes[i]);
    }
    printf("\n");
}

void count_rise(){
    no_of_classes += class_group;
    no_of_inherited_classes += inherited_group;
    no_of_constructors += constructor_group;
    no_of_overloading += operator_group;
    no_of_objects += object_group;
    class_group = inherited_group = constructor_group = operator_group = object_group = 0;
}

void remove_comments(FILE* src, FILE* dst){
    int singleline_comment = 0, multiline_comment = 0, length=0, i=0, string_started=0;
    char *r_line;
    r_line = malloc(1000);
    memset(r_line, 0, sizeof(r_line));
    size_t maximum_length = 1000;
    while(getline(&r_line, &maximum_length, src)!=-1){
        length = (int)strlen(r_line);
        if(r_line[length-1]=='\n'){
            length--;
        }
        singleline_comment = string_started = 0;
        for(i=0;i<length;i++){
            if(string_started && r_line[i] == '\"' && r_line[i-1] != '\\'){
                string_started = 0;
                r_line[i-1] = ' ';
                r_line[i] = ' ';
            }
            else if(multiline_comment == 1 && r_line[i] == '*' && r_line[i+1] == '/'){
                multiline_comment = 0;
                r_line[i] = ' ';
                r_line[i+1] = ' ';
                i++;
            }
            else if(string_started){
                r_line[i-1] = ' ';
            }
            else if(singleline_comment || multiline_comment){
                r_line[i] = ' ';
            }
            else if(r_line[i] == '\"' && r_line[i-1] != '\\'){
                string_started = 1;
            }
            else if(r_line[i] == '/' && r_line[i+1] == '/'){
                singleline_comment = 1;
                r_line[i] = ' ';
                r_line[i+1] = ' ';
                i++;
            }
            else if(r_line[i] == '/' && r_line[i+1] == '*'){
                multiline_comment = 1;
                r_line[i] = ' ';
                r_line[i+1] = ' ';
                i++;
            }
        }
        fprintf(dst, "%s", r_line);
        memset(r_line, 0, sizeof(r_line));
    }
}

void main(int argc, char **argv){
    argv++;
    argc--;
    if(argc == 0){
        printf("Enter file name\n");
        exit(0);
    }
    FILE* file_ptr = fopen(argv[0], "r");
    if(file_ptr == NULL){
        printf("File not found!\n");
        exit(0);
    }
    FILE* file_inter = fopen("intermediate.txt", "w");
    remove_comments(file_ptr, file_inter);   
    fclose(file_inter);
    fclose(file_ptr);
    file_ptr = fopen("intermediate.txt", "r");
 
    yyin = file_ptr;
    yylex();
    count_rise();
    printf("\nClasses : %d\n", no_of_classes);
    printf("Inherited Classes : %d\n", no_of_inherited_classes);
    
    printf("Constructors : %d\n", no_of_constructors);
    printf("Overloading  : %d\n", no_of_overloading);
    printf("Objects  : %d\n", no_of_objects);
}
