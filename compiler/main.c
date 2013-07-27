#include <stdio.h>
#include "Semantics.h"
#include "CodeGen.h"
#include "SymTab.h"
#include "IOMngr.h"

extern int yyparse();

struct SymTab *table;
struct SymTab *funcTable;
struct SymTab *ProcSymTab;
struct SymEntry *entry;
struct InstrSeq *floatData;
struct InstrSeq *funcSeq;

int inProc = 0;
FILE *aFile;

int main(int argc, char * argv[]) {
	table = CreateSymTab(33);
	funcTable = CreateSymTab(10);

        floatData = (struct InstrSeq*) malloc(sizeof(struct InstrSeq));
        funcSeq = (struct InstrSeq*) malloc(sizeof(struct InstrSeq));
        floatData = NULL;
        funcSeq = NULL;

	//assumes there is a listing file
	OpenFiles(argv[1], argv[2]);
	if (argc == 4) 
		aFile = fopen(argv[3], "w");
	else
		aFile = stdout;

	yyparse();
        return 0;
}

