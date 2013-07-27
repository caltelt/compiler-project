%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yaccExample.h"
#include "Semantics.h"
#include "CodeGen.h"

extern int yylex();	/* The next token function. */
extern char *yytext;   /* The matched token text.  */
extern int yyleng;      /* The token text length.   */
extern int yyparse();
void dumpTable();

extern struct SymTab *table;
extern struct SymTab *funcTable;
extern struct SymEntry *entry;

%}


%union {
  int val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;
}

%type <string> Id
%type <string> Ident
%type <val> SIZE

%type <InstrSeq> P0
%type <InstrSeq> P1
%type <ExprRes> E0
%type <ExprRes> E1
%type <ExprRes> E2
%type <ExprRes> E3
%type <ExprRes> E4
%type <ExprRes> E5
%type <ExprRes> R0
%type <ExprRes> O0
%type <ExprRes> O1

%type <InstrSeq> StmtSeq
%type <InstrSeq> RStmtSeq
%type <InstrSeq> Stmt

%token Ident 		
%token IntLit
%token FloatLit
%token Int
%token Float
%token PRINT
%token PRINTLN
%token PRINTSPACE
%token IF
%token ELSE
%token WHILE
%token EQ
%token NEQ
%token LT
%token LTE
%token GT
%token GTE
%token Bool
%token BoolLit
%token BoolAnd
%token BoolOr
%token Def
%token Return
%token Void
%token Not
%token Read

%%

Prog		:	Declarations Functions StmtSeq					        {Finish($3); } ;

Declarations	:	Dec Declarations							{};
Declarations	:										{};

Dec		:	Int Id ';'	                                                        {EnterName(table, $2, &entry); SetAttr(entry, "int");};
Dec             :       Bool Id ';'                                                             {EnterName(table, $2, &entry); SetAttr(entry, "bool");};
Dec             :       Float Id ';'                                                            {EnterName(table, $2, &entry); SetAttr(entry, "float");};

Dec		:	Int '[' SIZE ']' Id ';'                                                 {EnterName(table, $5, &entry); SetAttr(entry, "intarr");decArr($5, $3);};
Dec		:	Bool '[' SIZE ']' Id ';'                                                {EnterName(table, $5, &entry); SetAttr(entry, "boolarr");decArr($5, $3);};
Dec		:	Float '[' SIZE ']' Id ';'	                                        {EnterName(table, $5, &entry); SetAttr(entry, "floatarr");decArr($5, $3);};

Functions       :       FuncDec Functions                                                       {};
Functions       :                                                                               {};

FuncDec 	:	Def Int Ident {EnterName(funcTable, yytext, &entry);  SetAttr(entry, "int"); } '(' ')' '{' RStmtSeq '}'        {doFuncDec(entry->Name, $8);};
FuncDec 	:	Def Bool Ident {EnterName(funcTable, yytext, &entry); SetAttr(entry, "bool"); } '(' ')' '{' RStmtSeq '}'       {doFuncDec(entry->Name, $8);};
FuncDec 	:	Def Float Ident {EnterName(funcTable, yytext, &entry); SetAttr(entry, "float"); } '(' ')' '{' RStmtSeq '}'      {doFuncDec(entry->Name, $8);};
FuncDec 	:	Def Void Ident {EnterName(funcTable, yytext, &entry); SetAttr(entry, "void"); } '(' ')' '{' StmtSeq '}'        {doFuncDec(entry->Name, $8);};

RStmtSeq 	:	StmtSeq Return E0 ';'							{$$ = AppendSeq($1, doReturn($3)); } ;

StmtSeq 	:	Stmt StmtSeq								{$$ = AppendSeq($1, $2); } ;
StmtSeq		:										{$$ = NULL;} ;

Stmt		:	PRINTSPACE E0 ';'							{$$ = doPrintSpace($2);};
Stmt		:	PRINTLN P0 ';'								{$$ = $2;};
Stmt		:	PRINT P1 ';'								{$$ = $2;};

Stmt		:	Id '(' ')' ';'								{$$ = doFunc($1);};

Stmt		:	Id '=' R0 ';'								{$$ = doAssign($1, NULL, $3);};
Stmt		:	E5 '=' R0 ';'           						{$$ = doAssign(NULL, $1, $3);};
Stmt		:	Id '=' Read ';'								{$$ = read($1, NULL); } ;
Stmt		:	E5 '=' Read ';'           						{$$ = read(NULL, $1);};

Stmt		:	IF '(' R0 ')' '{' StmtSeq '}' ELSE '{' StmtSeq '}'      	        {$$ = doIfElse($3, $6, $10);};
Stmt		:	IF '(' R0 ')' '{' StmtSeq '}'    				        {$$ = doIf($3, $6);}
Stmt		:	WHILE '(' E0 ')' '{' StmtSeq '}'    				        {$$ = doWhile($3, $6);};

P0              :       P1 ',' E0                                                               {$$ = doPrintln($1, $3);};
P0              :       E0                                                                      {$$ = doPrintln(NULL, $1);};
P0              :                                                                               {$$ = doPrintln(NULL, NULL);};

P1              :       P1 ',' E0                                                               {$$ = doPrint($1, $3);};
P1              :       E0                                                                      {$$ = doPrint(NULL, $1);};

R0		:	Id '(' ')' 								{$$ = doFuncReturn($1);};
R0              :       E0                                                                      {$$ = $1;};

E0              :       E0 BoolAnd E1                                                           {$$ = doBoolOp($1, $3, "and");};
E0              :       E0 BoolOr E1                                                            {$$ = doBoolOp($1, $3, "or");};
E0              :       E1                                                                      {$$ = $1;};

E1		:	E2 EQ E2								{$$ = doBExpr($1, $3, "beq");};
E1		:	E2 NEQ E2								{$$ = doBExpr($1, $3, "bne");};
E1		:	E2 GT E2								{$$ = doBExpr($1, $3, "bgt");};
E1		:	E2 LT  E2								{$$ = doBExpr($1, $3, "blt");};
E1		:	E2 GTE E2								{$$ = doBExpr($1, $3, "bge");};
E1		:	E2 LTE  E2								{$$ = doBExpr($1, $3, "ble");};
E1              :       E2                                                                      {$$ = $1;};

E2		:	E2 '+' E3								{$$ = doBinArith($1, $3, "add"); };
E2		:	E2 '-' E3								{$$ = doBinArith($1, $3, "sub"); };
E2		:	E3									{$$ = $1; };

E3		:	E3 '*' E4								{$$ = doBinArith($1, $3, "mul"); };
E3              :       E3 '/' E4                                                               {$$ = doBinArith($1, $3, "div"); };
E3              :       E3 '%' E4                                                               {$$ = doBinArith($1, $3, "rem"); };
E3		:	O0									{$$ = $1; } ;

O0		:	O1 '^' O1      								{$$ = doExponent($1, $3); } ;
O0		:	O1      								{$$ = $1; } ;

O1		:	'(' E0 ')'								{$$ = $2; } ;
O1		:	Not  O1  								{$$ = not($2); } ;
O1		:	'-'  O1  								{$$ = neg($2); } ;
O1		:	E4      								{$$ = $1; } ;

E4		:	IntLit									{$$ = doIntLit(yytext); };
E4		:	FloatLit								{$$ = doFltLit(yytext); };

E4              :       BoolLit                                                                 {$$ = doBoolLit(yytext);};
E4		:	Id '[' E2 ']'								{$$ = doRval($1, $3); };
E4		:	Id									{$$ = doRval($1, NULL); };

E5		:	Id '[' E2 ']'								{$$ = doRval($1, $3); };

Id		: 	Ident									{$$ = strdup(yytext);}



SIZE		:	IntLit									{$$ = atoi(yytext); };

%%



yyerror(char *s)  {
  WriteIndicator(GetCurrentColumn());
  WriteMessage(s);
}
