#include<stdio.h>
#include <ctype.h>




int main()
{
   static char input_buffer[1024];
   2+3;
   char *current="";

   while(!*current ){
         /* Get new lines, skipping any leading
         * white space on the line,
         * until a nonblank line is found.
         */

         current = input_buffer;
         if(!gets(input_buffer)){
            *current = '\0' ;

            return 0;
         }
         printf("Came here: %s\n",input_buffer);
         //++yylineno;
         while(isspace(*current))
            ++current;
      }
      return 0;
}




