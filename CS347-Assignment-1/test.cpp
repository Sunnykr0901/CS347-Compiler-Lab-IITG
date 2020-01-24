#include<stdio.h>
#include <ctype.h>




int main()
{
   static char input_buffer[1024];
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

#include <stdarg.h>

#define MAXFIRST 16
#define SYNCH   SEMI

int   legal_lookahead(  first_arg )
int   first_arg;
{
    /* Simple error detection and recovery. Arguments are a 0-terminated list of
     * those tokens that can legitimately come next in the input. If the list is
     * empty, the end of file must come next. Print an error message if
     * necessary. Error recovery is performed by discarding all input symbols
     * until one that's in the input list is found
     *
     * Return true if there's no error or if we recovered from the error,
     * false if we can't recover.
     */

    va_list    args;
    int     tok;
    int     lookaheads[MAXFIRST], *p = lookaheads, *current;
    int     error_printed = 0;
    int     rval        = 0;

    va_start( args, first_arg );

    if( !first_arg )
    {
   if( match(EOI) )
       rval = 1;
    }
    else
    {
   *p++ = first_arg;
   while( (tok = va_arg(args, int)) && p < &lookaheads[MAXFIRST] )
       *p++ = tok;

   while( !match( SYNCH ) )
   {
       for( current = lookaheads; current < p ; ++current )
      if( match( *current ) )
      {
          rval = 1;
          goto exit;
      }

       if( !error_printed )
       {
      fprintf( stderr, "Line %d: Syntax error\n", yylineno );
      error_printed = 1;
       }

       advance();
   }
    }

exit:
    va_end( args )
    return rval;
}


