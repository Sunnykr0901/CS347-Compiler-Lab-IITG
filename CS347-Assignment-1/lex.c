#include "lex.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char* yytext = ""; /* Lexeme (not '\0'
                      terminated)              */
int yyleng   = 0;  /* Lexeme length.           */
int yylineno = 0;  /* Input line number        */

int lex(void){

   static char input_buffer[1024];
   char        *current;

   current = yytext + yyleng; /* Skip current
                                 lexeme        */

   while(1){       /* Get the next one         */
      while(!*current){
         /* Get new lines, skipping any leading
         * white space on the line,
         * until a nonblank line is found.
         */

         current = input_buffer;
         if(!gets(input_buffer)){
            *current = '\0' ;

            return EOI;
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
           case ';':
            return SEMI;
           case '+':
            return PLUS;
           case '-':
            return MINUS;
           case '*':
            return TIMES;
           case '/':
            return DIV;
           case '(':
            return LP;
           case ')':
            return RP;
            case '=':
            return EQUALTO;
            case '<':
            return LESS;
            case '>':
            return GREATER;
            case ':': ++current;
                      if(*current=='=')
                        return ASSIGN;
                      else
                        fprintf(stderr, "Not valid character after ':' <%c>\n", *current);
                      break;

           case '\n':
           case '\t':
           case ' ' :
            break;
           default:
            if(!isalnum(*current))
               fprintf(stderr, "Not alphanumeric <%c>\n", *current);
            else{
              char *temp=(char *)malloc(sizeof(char)*1024);
              int len=0;
              bool flag=1;
               while(isalnum(*current)){
                  temp[len++]=*current;
                  if(isalpha(temp[len-1])){
                    temp[len-1]=to_lower(temp[len-1]);
                    flag=0;
                  }
                  ++current;

               }
               temp[len]='\0';
               yyleng = current - yytext;
               if(flag)               //Constant
                return CONSTANT;
               if(!strcmp(temp,"if"))  //if keyword
                  return IF;
               else if(!strcmp(temp,"then"))  //then keyword
                  return THEN; 
              else if(!strcmp(temp,"while"))  //then keyword
                  return WHILE; 
                else if(!strcmp(temp,"begin"))  //then keyword
                  return BEGIN; 
                else if(!strcmp(temp,"end"))  //then keyword
                  return END;
                else if(!strcmp(temp,"do"))  //then keyword
                  return DO; 
                else if(!strcmp(temp,"then"))  //then keyword
                  return THEN;
                else if(isalpha(temp[0])) //Identifier
                  return ID;
                else 
                    fprintf(stderr, "Not recognised <%s>\n", temp);

               
            }
            break;
         }
      }
   }
}


static int Lookahead = -1; /* Lookahead token  */

int match(int token){
   /* Return true if "token" matches the
      current lookahead symbol.                */

   if(Lookahead == -1)
      Lookahead = lex();

   return token == Lookahead;
}

void advance(void){
/* Advance the lookahead to the next
   input symbol.                               */

    Lookahead = lex();
}
