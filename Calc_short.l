%{
#include "calc.tab.h"
%}
%%
[a-z]   { yylval = yytext[0] - 'a'; return LETTER; }
[0-9]   { yylval = yytext[0] - '0'; return DIGIT; }
[ \t]   ;
\n      return '\n';
.       return yytext[0];
%%
int yywrap(void) { return 1; }
