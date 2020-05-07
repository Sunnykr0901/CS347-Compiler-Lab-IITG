%{    
# include "inter.tab.h"
%}
%option noyywrap
%%

"convertToInt"                  { return CONVERTINT; }
"goto"                          { return GOTO; }
"print"                         { return PRINT;}
"<="                            { return LE; }
"return"                        { return RETURN; }
"("                             { return LP; }
"*"                             { return MUL; }
"call"                          { return CALL; }
"~"                             { return NEG; }
"&&"                            { return AND; }
">="                            { return GE; }
"!="                            { return NOTEQUAL; }
"%"                             { return MOD; }
"=="                            { return EQUAL; }
"||"                            { return OR; }
":"                             { return COLON; }
"begin"                         { return BEG; }
">"                             { return GT; }
"+"                             { return PLUS; }
","                             { return COMMA; }
"/"                             { return DIV; }
"read"                          { return READ; }
"refparam"                      { return REFPARAM; }
"<"                             { return LT; }
")"                             { return RP; }
"if"                            { return IF; }
"param"                         { return PARAM; }
"="                             { return ASSIGN; }
"["                             { return LSB; }
"convertToFloat"                { return CONVERTFLOAT; }
"]"                             { return RSB; }
"function"                      { return FUNCTION; }
"end"                           { return END; }

-[0-9]+\.[0-9]*|[0-9]+\.[0-9]*  { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return NUMFLOAT; }
-[0-9]+|[0-9]+                  { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return NUMINT; }
"-"                             { return MINUS; }
[T][0-9]+                       { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return REGINT; }
[F][0-9]+                       { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return REGFLOAT; }
[L][0-9]+                       { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return LABEL; }   
[_a-zA-Z][a-zA-Z_0-9]*          { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return USERVAR; }

\n                              { yylineno++;return NEWLINE;}
[ \t]                           { /* ignore whitespace */ }
%%