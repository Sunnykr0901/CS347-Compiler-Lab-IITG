%{
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <fstream>
#include "SymbolTableParser.h"
using namespace std;

#define INTSIZE 4
#define FLOATSIZE 4

extern int yylex();
extern int yyparse();
extern int yylineno;
extern char* yytext;
extern int yyleng;
void yyerror(char* s);

FILE *mips;
string activeFunc;
int paramOffset;
string returnVal;
int floatLabel = 0;
vector<funcEntry> functionList;
vector<typeRecord> globalVariables;

void saveRegisters(int frameSize);
void retrieveRegisters(int frameSize);  
bool isGlobal;  
%}

%union {
    int intval;
    float floatval;
    char *idName;
}

%token FUNCTION BEG END IF GOTO PARAM REFPARAM CALL LSB RSB RETURN NEWLINE
%token CONVERTINT CONVERTFLOAT LP RP
%token USERVAR REGINT REGFLOAT LABEL NUMINT NUMFLOAT PRINT READ
%token COMMA COLON SEMI
%token PLUS MINUS MUL DIV MOD
%token EQUAL NOTEQUAL OR AND LT GT LE GE ASSIGN NEG

%type <idName> NUMFLOAT NUMINT REGINT REGFLOAT LABEL USERVAR 

%%

STMT_LIST: STMT_LIST STMT NEWLINE
    | STMT NEWLINE
;

STMT: ASG
    | FLOATASG
    | GOTO LABEL
    {
        fprintf(mips, "j %s\n", $2);
    }
    | LABEL COLON
    {
        fprintf(mips, "%s:\n", $1);
    }
    | IFSTMT
    | PARAM REGINT
    {
        // The initial frame of the caller function remains intact, grows downwards for each param
        paramOffset += INTSIZE;
        fprintf(mips, "sub $sp, $sp, %d\n", INTSIZE); // addu $sp, $sp, -INTSIZE
        fprintf(mips, "sw $t%c, 0($sp)\n", $2[1]);     // sw $t0, 0($sp)
    }
    | PARAM REGFLOAT
    {
        paramOffset += FLOATSIZE;
        fprintf(mips, "sub $sp, $sp, %d\n", FLOATSIZE);    // addu $sp, $sp, -INTSIZE
        fprintf(mips, "mfc1 $s0, $f%s\n", $2+1);             // store a float reg into int reg s0
        fprintf(mips, "sw $s0, 0($sp)\n");                 // sw $t0, 0($sp)
    }
    | REFPARAM REGINT 
    {
        returnVal = string($2);
    }
    | REFPARAM REGFLOAT
    {
        returnVal = string($2);
    }
    | CALL USERVAR COMMA NUMINT
    {
        int frameSize = getFunctionOffset(functionList, activeFunc); 
        saveRegisters(frameSize+paramOffset);       // Save all temp registers
        fprintf(mips, "jal %s\n", $2);                     // jal calling
        retrieveRegisters(frameSize+paramOffset);   // retrieve all registers
        if(returnVal==""){

        } else if(returnVal[0] == 'F'){
            fprintf(mips, "move $s0, $v0\n");   // move result to refparam
            fprintf(mips, "mtc1 $s0, $f%s\n", returnVal.c_str()+1);   // move result to refparam
        } else {
            fprintf(mips, "move $t%c, $v0\n", returnVal[1]);   // move result to refparam 
        }
        int funcParamOffset = getParamOffset(functionList, string($2));
        fprintf(mips, "add $sp, $sp, %d\n", funcParamOffset);  // collapse space used by parameters
        paramOffset-=funcParamOffset;
        returnVal = "";
    }
    | FUNCTION BEG USERVAR 
    {
        activeFunc = string($3);
        fprintf(mips, "%s:\n", $3);
        // Push return address and frame poIntermediate to top of frame
        int frameSize = getFunctionOffset(functionList, activeFunc);
        fprintf(mips, "subu $sp, $sp, %d\n", frameSize);
        fprintf(mips, "sw $ra, %d($sp)\n", frameSize-INTSIZE);
        fprintf(mips, "sw $fp, %d($sp)\n", frameSize-2*INTSIZE);
        fprintf(mips, "move $fp, $sp\n");
    }
    | FUNCTION END
    {
        int frameSize = getFunctionOffset(functionList, activeFunc);
        fprintf(mips, "end_%s:\n", activeFunc.c_str());
        fprintf(mips, "move $sp, $fp\n");                          // move    $sp,$fp
        fprintf(mips, "lw $ra, %d($sp)\n", frameSize-INTSIZE);     // lw      $31,52($sp)
        fprintf(mips, "lw $fp, %d($sp)\n", frameSize-2*INTSIZE);   // lw      $fp,48($sp)
        fprintf(mips, "addu $sp, $sp, %d\n", frameSize);           // addiu   $sp,$sp,56
        fprintf(mips, "j $ra\n");                                  // j       $31
        //nop
    }
    | RETURN 
    {
        fprintf(mips, "j end_%s\n", activeFunc.c_str());
    }
    | RETURN REGINT
    {
        fprintf(mips, "move $v0, $t%c\n", $2[1]);
        fprintf(mips, "j end_%s\n", activeFunc.c_str());
    }
    | RETURN REGFLOAT
    {
        fprintf(mips, "mfc1 $s0, $f%s\n", $2+1);
        fprintf(mips, "move $v0, $s0\n");
        fprintf(mips, "j end_%s\n", activeFunc.c_str());
    }
    | PRINT REGINT
    {
        fprintf(mips, "move $a0, $t%s\n", $2+1);
        fprintf(mips, "li $v0 1\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "li $v0, 4\n");//         li $v0, 4 # system call code for printing string = 4
        fprintf(mips, "la $a0, endline\n");// la $a0, out_string # load address of string to be printed into $a0
        fprintf(mips, "syscall\n");// syscall
    }
    | PRINT REGFLOAT
    {
        fprintf(mips, "mov.s $f12, $f%s\n", $2+1);
        fprintf(mips, "li $v0 2\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "li $v0, 4\n");//         li $v0, 4 # system call code for printing string = 4
        fprintf(mips, "la $a0, endline\n");// la $a0, out_string # load address of string to be printed into $a0
        fprintf(mips, "syscall\n");// syscall
    }
    | READ REGINT
    {
        fprintf(mips, "li $v0 5\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "move $t%s, $v0\n", $2+1);
    }
    | READ REGFLOAT
    {
        fprintf(mips, "li $v0 6\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "mov.s $f%s, $f0\n", $2+1);
    }
;


ASG: USERVAR ASSIGN REGINT
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($1), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "sw $t%c, %d($sp)\n", $3[1], offset);
        } else {
            fprintf(mips, "sw $t%s, %s\n", $3+1, $1); 
        }
    }
    | USERVAR LSB NUMINT RSB ASSIGN REGINT
    {
        // useless
        int offset = getOffset(functionList, globalVariables, activeFunc, string($1), 0, isGlobal)+paramOffset;
        fprintf(mips, "sw $t%c, %d($sp)\n", $3[1], offset);
    }
    | USERVAR LSB REGINT RSB ASSIGN REGINT
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($1), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", $3+1);
            fprintf(mips,"sw $t%s, 0($s0)\n", $6+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", $1);
            fprintf(mips,"addu $s0, $s1, $t%s\n", $3+1);
            fprintf(mips,"sw $t%s, 0($s0)\n", $6+1);
        }
    }
    | REGINT ASSIGN USERVAR
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($3), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "lw $t%c, %d($sp)\n", $1[1], offset);
        } else {
            fprintf(mips, "lw $t%c, %s\n", $1[1], $3);
        }
    }
    | REGINT ASSIGN USERVAR LSB REGINT RSB
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($3), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", $5+1);
            fprintf(mips,"lw $t%s, 0($s0)\n", $1+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips,"la $s0, %s\n", $3);
            fprintf(mips,"addu $s0, $s0, $t%s\n", $3+1);
            fprintf(mips,"lw $t%s, 0($s0)\n", $1+1);
        }
    }
    | REGINT ASSIGN USERVAR LSB NUMINT RSB
    {
        //useless
        int offset = getOffset(functionList, globalVariables, activeFunc, string($3), 0, isGlobal)+paramOffset;
        fprintf(mips, "sw $t%c, %d($sp)\n", $1[1], offset);
    }
    | REGINT ASSIGN NUMINT
    {
        fprintf(mips, "li $t%c, %s\n", $1[1], $3);
    }
    | REGINT ASSIGN REGINT
    {
        fprintf(mips, "move $t%c, $t%c\n", $1[1], $3[3]);
    }
    | REGINT ASSIGN CONVERTINT LP REGFLOAT RP
    {
        fprintf(mips, "cvt.w.s $f%s, $f%s\n", $5+1, $5+1);
        fprintf(mips, "mfc1 $t%c, $f%s\n", $1[1], $5+1);
    }
    | REGINT ASSIGN REGINT PLUS NUMINT
    {
        fprintf(mips, "addu $t%c, $t%c, %s\n", $1[1], $3[1], $5);
    }
    | REGINT ASSIGN REGINT MINUS NUMINT
    {
        fprintf(mips, "subu $t%c, $t%c, %s\n", $1[1], $3[1], $5);
    }
    | REGINT ASSIGN REGINT PLUS REGINT
    {
        fprintf(mips, "add $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT MINUS REGINT
    {
        fprintf(mips, "sub $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT MUL REGINT
    {
        fprintf(mips, "mul $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT DIV REGINT
    {
        fprintf(mips, "div $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
        fprintf(mips, "mflo $t%c\n", $1[1]);
    }
    | REGINT ASSIGN REGINT MOD REGINT
    {
        fprintf(mips, "div $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
        fprintf(mips, "mfhi $t%c\n", $1[1]);
    }
    | REGINT ASSIGN REGINT EQUAL REGINT
    {
        fprintf(mips, "seq $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT NOTEQUAL REGINT
    {
        fprintf(mips, "sne $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT AND REGINT 
    {
        // hack, will not arise when short-circuit is done
        fprintf(mips, "sne $t%c, $t%c, 0\n", $3[1], $3[1]);
        fprintf(mips, "sne $t%c, $t%c, 0\n", $5[1], $5[1]);
        fprintf(mips, "and $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT OR REGINT
    {
        fprintf(mips, "or $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT LT REGINT
    {
        fprintf(mips, "slt $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT GT REGINT
    {
        fprintf(mips, "sgt $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT LE REGINT
    {
        fprintf(mips, "sle $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT GE REGINT
    {
        fprintf(mips, "sge $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
;

FLOATASG: USERVAR ASSIGN REGFLOAT
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($1), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "s.s $f%s, %d($sp)\n", $3+1, offset);
        } else {
            fprintf(mips, "s.s $f%s, %s\n", $3+1, $1);
        }
    }
    | USERVAR LSB NUMINT RSB ASSIGN REGFLOAT
    {
        //useless
        int offset = getOffset(functionList, globalVariables, activeFunc, string($1), 0, isGlobal)+paramOffset;
        fprintf(mips, "s.s $f%s, %d($sp)\n", $3+1, offset);
    }
    | USERVAR LSB REGINT RSB ASSIGN REGFLOAT
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($1), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", $3+1);
            fprintf(mips,"s.s $f%s, 0($s0)\n", $6+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", $1);
            fprintf(mips,"addu $s0, $s1, $t%s\n", $3+1);
            fprintf(mips,"s.s $f%s, 0($s0)\n", $6+1);
        }
    }
    | REGFLOAT ASSIGN USERVAR
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($3), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "l.s $f%s, %d($sp)\n", $1+1, offset);
        } else {
            fprintf(mips, "l.s $f%s, %s\n", $1+1, $3);
        }
    }
    | REGFLOAT ASSIGN USERVAR LSB REGINT RSB
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string($3), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips, "subu $s0, $sp, $t%s\n", $5+1);
            fprintf(mips, "l.s $f%s, %d($s0)\n", $1+1, offset);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", $3);
            fprintf(mips,"addu $s0, $s1, $t%s\n", $5+1);
            fprintf(mips,"l.s $f%s, 0($s0)\n", $1+1);
        }
    }
    | REGFLOAT ASSIGN CONVERTFLOAT LP REGINT RP
    {
        // convert from integer to float
        fprintf(mips, "mtc1 $t%c, $f%s\n", $5[1], $1+1);
        fprintf(mips, "cvt.s.w $f%s, $f%s\n", $1+1, $1+1);
    }
    | REGFLOAT ASSIGN NUMFLOAT
    {
        fprintf(mips, "li.s $f%s, %s\n", $1+1, $3);
    }
    | REGFLOAT ASSIGN REGFLOAT
    {
        fprintf(mips, "mov.s $f%s, $f%s\n", $1+1, $3+1);
    }
    | REGFLOAT ASSIGN REGFLOAT PLUS REGFLOAT
    {
        fprintf(mips, "add.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGFLOAT ASSIGN REGFLOAT MINUS REGFLOAT
    {
        fprintf(mips, "sub.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGFLOAT ASSIGN REGFLOAT MUL REGFLOAT
    {
        fprintf(mips, "mul.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGFLOAT ASSIGN REGFLOAT DIV REGFLOAT
    {
        fprintf(mips, "div.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGINT ASSIGN REGFLOAT EQUAL REGFLOAT
    {
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT NOTEQUAL REGFLOAT
    {
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT AND REGFLOAT
    {
        fprintf(mips, "li.d $f31, 0\n");
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $3+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT OR REGFLOAT
    {
        fprintf(mips, "li.d $f31, 0\n");
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $3+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT LT REGFLOAT
    {
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.lt.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT GT REGFLOAT
    {
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.le.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT LE REGFLOAT
    {
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.le.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
    | REGINT ASSIGN REGFLOAT GE REGFLOAT
    {
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.lt.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
;

IFSTMT: IF REGINT EQUAL REGINT GOTO LABEL
    {
        fprintf(mips, "beq $t%c, $t%c, %s\n", $2[1], $4[1], $6);
    }
    | IF REGINT NOTEQUAL REGINT GOTO LABEL
    {
        fprintf(mips, "bne $t%c, $t%c, %s\n", $2[1], $4[1], $6);
    }
    | IF REGINT EQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "beq $t%c, %s, %s\n", $2[1], $4, $6);
    }
    | IF REGINT NOTEQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "bne $t%c, %s, %s\n", $2[1], $4, $6);
    }
    | IF REGFLOAT EQUAL REGFLOAT GOTO LABEL
    {
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $2+1, $4+1);
        fprintf(mips, "bc1t FLOAT%d\n", floatLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        floatLabel++;
    }
    | IF REGFLOAT NOTEQUAL REGFLOAT GOTO LABEL
    {
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $2+1, $4+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        floatLabel++;
    }
    | IF REGFLOAT EQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "mtc1 $0, $f31\n");
        fprintf(mips, "cvt.s.w $f31, $f31\n");
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f31\n", $2+1);
        fprintf(mips, "bc1t FLOAT%d\n", floatLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        floatLabel++;
    }
    | IF REGFLOAT NOTEQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "mtc1 $0, $f31\n");
        fprintf(mips, "cvt.s.w $f31, $f31\n");
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f31\n", $2+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel); // goto label float when equal to 0
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        floatLabel++;
    }
;

%%

void saveRegisters(int frameSize){
    for(int i=0; i<10; i++){
        fprintf(mips, "sw $t%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+1)*INTSIZE);
    }
    for(int i=0; i<11; i++){
        fprintf(mips, "s.s $f%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+11)*INTSIZE);
    }
}

void retrieveRegisters(int frameSize){
    for(int i=0; i<10; i++){
        fprintf(mips, "lw $t%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+1)*INTSIZE);
    }
    for(int i=0; i<11; i++){
        fprintf(mips, "l.s $f%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+11)*INTSIZE);
    }
}

void yyerror(char *s)
{      
    printf("\nSyntax error %s at line %d\n", s, yylineno);
    // cout << BOLD(FRED("Error : ")) << FYEL("Syntax error " + string(s) + "in Intermediatemediate code at line " + to_string(yylineno)) << endl;
    fflush(stdout);
}

int main(int argc, char **argv)
{
    readSymbolTable(functionList, globalVariables);
    returnVal = ""; 
    isGlobal = false;
    mips = fopen("mips.s", "w");
    fflush(mips);
    fprintf(mips,".data\n");
    for(auto it : globalVariables){
        fprintf(mips, "%s: .space %d\n", it.name.c_str(), 4*(it.varOffset));
    }
    fprintf(mips,"endline: .asciiz \"\\n\"\n");
    fprintf(mips,".text\n");
    paramOffset = 0;
    floatLabel = 0;
    yyparse();
    fflush(mips);
    fclose(mips);
}
