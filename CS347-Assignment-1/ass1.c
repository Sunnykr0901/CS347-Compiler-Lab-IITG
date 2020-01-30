#include "lex.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* yytext = ""; /* Lexeme (not '\0'
                      terminated)              */
int yyleng   = 0;  /* Lexeme length.           */
int yylineno = 0;  /* Input line number        */

struct node{
  int id;
  char *st;
  int len;
};

struct node2{
  
  char *st;
  int id;
};

struct node* lex(void){

   static char input_buffer[1024];
   char        *current;

   current = yytext + yyleng; /* Skip current
                                 lexeme        */

   struct node *n1=(struct node*)malloc(sizeof(struct node));

   while(1){       /* Get the next one         */
      while(!*current){
         /* Get new lines, skipping any leading
         * white space on the line,
         * until a nonblank line is found.
         */

         current = input_buffer;
         if(!gets(input_buffer)){
            *current = '\0' ;
            n1->id=EOI;
            return n1;
         }
         ++yylineno;
         while(isspace(*current))
            ++current;
      }
      for(; *current; ++current){
         /* Get the next token */
         yytext = current;
         yyleng = 1;
         switch( *current ){
           case ';': n1->id=SEMI;
            return n1;
           case '+':  n1->id=PLUS;
            return n1;
           case '-':  n1->id=MINUS;
            return n1;
           case '*':  n1->id=TIMES;
            return n1;
           case '/':  n1->id=DIV;
            return n1;
           case '(':  n1->id=LP;
            return n1;
           case ')':  n1->id=RP;
            return n1;
            case '=': n1->id=EQUALTO;
            return n1;
            case '<': n1->id=LESS;
            return n1;
            case '>': n1->id=GREATER;
            return n1;
            case ':': ++current;
                      if(*current=='='){
                        n1->id=ASSIGN;
                        yyleng=2;
                        return n1;
                      }
                      else{
                        fprintf(stderr, "Not valid character after ':' <%c>\n", *current);
                        n1->id=-1;
                        return n1;
                      }
                      break;

           case '\n':
           case '\t':
           case ' ' :
            break;
           default:
            if(!isalnum(*current)){
               fprintf(stderr, "Not alphanumeric <%c>\n", *current);
               n1->id=-1;
               return n1;
             }
            else{
              char *temp=(char *)malloc(sizeof(char)*1024);
              int len=0;
              int flag=1;
               while(isalnum(*current)){
                  temp[len++]=*current;
                  if(isalpha(temp[len-1])){
                    temp[len-1]=tolower(temp[len-1]);
                    flag=0;
                  }
                  ++current;

               }
               temp[len]='\0';
               
               yyleng = current - yytext;

               if(flag)               //Constant
                {
                  n1->id=CONSTANT;
                  n1->st=temp;
                  n1->len=len;
                  return n1;
               }   
               if(!strcmp(temp,"if"))  //if keyword
               {
                  n1->id=IF;
                  return n1;
               }   
               else if(!strcmp(temp,"then"))  //then keyword
                {
                  n1->id=THEN;
                  return n1;
               }   
              else if(!strcmp(temp,"while"))  //then keyword
                 {
                  n1->id=WHILE;
                  return n1;
               }   
                else if(!strcmp(temp,"begin"))  //then keyword
                 {
                  n1->id=BEGIN;
                  return n1;
               }   
                else if(!strcmp(temp,"end"))  //then keyword
                 {
                  n1->id=END;
                  return n1;
               }   
                else if(!strcmp(temp,"do"))  //then keyword
                 {
                  n1->id=DO;
                  return n1;
               }    
                else if(!strcmp(temp,"then"))  //then keyword
                 {
                  n1->id=THEN;
                  return n1;
               }   
                else if(isalpha(temp[0])) //Identifier
                  {
                  n1->id=ID;
                  n1->st=temp;
                  n1->len=len;
                  return n1;
               }   
                else{
                    fprintf(stderr, "Not recognised <%s>\n", temp);
                    n1->id=-1;
                    return n1;
                  }

               
            }
            break;
         }
      }
   }
}


static int Lookahead = -1; /* Lookahead token  */
struct node *cur;

struct node* match(void){
   /* Return true if "token" matches the
      current lookahead symbol.                */
  
   if(Lookahead == -1)
      {
        cur=lex();
        Lookahead++;
      }

   return cur;
}

void advance(void){
/* Advance the lookahead to the next
   input symbol.                               */

    cur = lex();
}

int auto_id;
struct node2 array[100000];
int size;

int check_sym(char *st)
{
  
  for(int i=0;i<size;i++)
    if(!strcmp(st,(array[i].st)))
    {
      
      return (array[i].id);
    }
    return -1;

}



int main()
{

  FILE *fp ; 
  fp = fopen("symbol_table.txt","w");
  FILE *fp2 ; 
  fp2 = fopen("output.txt","w");
  struct node *ret=lex();
  auto_id=1;
  
 size=0;

  
  while(ret->id!=EOI&&ret->id!=-1)
  {
    switch(ret->id)
    {
      case ID:if(check_sym(ret->st)==-1){
            fprintf(fp,"%d %s\n",auto_id,ret->st);
              
              array[size].st=ret->st;
              array[size++].id=auto_id;
              fprintf(fp2,"<ID,%d>\n",auto_id++);

             }
            else
            {
              
              
              fprintf(fp2,"<ID,%d>\n",check_sym(ret->st));
            }

              
              break;
      case CONSTANT:fprintf(fp,"%d %s\n",auto_id,ret->st);
              fprintf(fp2,"<CONSTANT,%d>\n",auto_id++);
              break;
      case SEMI:fprintf(fp2,"<;>\n");
                break;
      case PLUS:fprintf(fp2,"<+>\n");
                break;
      case TIMES:fprintf(fp2,"<*>\n");
                break;
      case LP:fprintf(fp2,"<(>\n");
                break;
      case RP:fprintf(fp2,"<)>\n");
                break;
      case MINUS:fprintf(fp2,"<->\n");
                break;
      case DIV:fprintf(fp2,"</>\n");
                break;
      case ASSIGN:fprintf(fp2,"<:=>\n");
                break;
      case LESS:fprintf(fp2,"<<>\n");
                break;
      case GREATER:fprintf(fp2,"<>>\n");
                break;
      case EQUALTO:fprintf(fp2,"<==>\n");
                break;
       case IF:fprintf(fp2,"<if>\n");
                break;
      case THEN:fprintf(fp2,"<then>\n");
                break;
      case WHILE:fprintf(fp2,"<while>\n");
                break;
      case DO:fprintf(fp2,"<do>\n");
                break;
      case BEGIN:fprintf(fp2,"<begin>\n");
                break;
      case END:fprintf(fp2,"<end>\n");
                break;
    
  }
  ret=lex();
}

fclose(fp);
fclose(fp2);



  
  return 0;
}
