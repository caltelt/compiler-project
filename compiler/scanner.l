%{
#include "yaccExample.h"
#include "y.tab.h"

#define YY_INPUT(buf,result,max_size) \
	{ int c = GetSourceChar(); \
          result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
        }

%}


letter [A-Za-z]
digit [0-9]


%%

if					{return IF;}
else                                    {return ELSE;}
while                                   {return WHILE;}
int					{return Int;}
printspace				{return PRINTSPACE;}
println					{return PRINTLN;}
print                                   {return PRINT;}
bool                                    {return Bool;}
float                                   {return Float;}
void                                    {return Void;}
read                                    {return Read;}

true                                    {return BoolLit;}
false                                   {return BoolLit;}

def                                     {return Def;}
return                                  {return Return;}

{letter}({letter}|{digit})*     	{return Ident;}
-?{digit}+\.{digit}+		        {return FloatLit;}
-?{digit}{digit}*                       {return IntLit;}

\/\/.*\n                                {}


\=\=					{return EQ;}
\!\=                                    {return NEQ;}

\!                                      {return Not;}

\=					{return '=';}
\+					{return '+';}
\*					{return '*';}
\-                                      {return '-';}
\/                                      {return '/';}
\%                                      {return '%';}
\^                                      {return '^';}

\|\|                                    {return BoolOr;}
\&\&                                    {return BoolAnd;}

\>                                      {return GT;}
\>\=                                    {return GTE;}
\<                                      {return LT;}
\<\=                                    {return LTE;}


\;					{return ';';}
\:					{return ':';}
\{					{return '{';}
\}					{return '}';}
\(					{return '(';}
\)					{return ')';}
\,                                      {return ',';}
\[                                      {return '[';}
\]                                      {return ']';}

[ ]				{}
\t				{}
\r				{}
\n				{}

.				{WriteIndicator(GetCurrentColumn());
				   WriteMessage("Illegal Character in lex");}

%%

	
yywrap () {
}
			
	
