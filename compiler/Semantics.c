/* Semantics.c
   Support and semantic action routines.
*/

#include <string.h>
#include <stdlib.h>

#include "CodeGen.h"
#include "Semantics.h"
#include "SymTab.h"
#include "IOMngr.h"


#define FLOAT "float"
#define FLOATARR "floatarr"
#define INT "int"
#define INTARR "intarr"
#define BOOL "bool"
#define BOOLARR "boolarr"


char* ONE_FLOAT = "_one_float";

extern struct SymTab *table;
extern struct SymTab *funcTable;
extern struct InstrSeq *floatData;
extern struct InstrSeq *funcSeq;

/* Semantics support routines */

char* tmpRegType(struct ExprRes* Res1, struct ExprRes* Res2)
{
        char* regType;

        if(NULL == Res1 && NULL == Res2)
        {
                return "int";
        }
        
        if(NULL == Res1)
        {
                return Res2->Type;
        }
        if(NULL == Res2)
        {
                return Res1->Type;
        }

        if(0 == strcmp("float", Res1->Type) || 0 == strcmp("float", Res2->Type))
        {
                regType = "float";
        }
        else
        {
                regType = "int";
        }

        return regType;
}

char* convertToFltOp(char* op)
{
        if(0 == strcmp("add", op))
        {
                return "add.s";
        }
        else if(0 == strcmp("sub", op))
        {
                return "sub.s";
        }
        else if(0 == strcmp("mul", op))
        {
                return "mul.s";
        }
        else if(0 == strcmp("div", op))
        {
                return "div.s";
        }

        WriteIndicator(GetCurrentColumn());
        WriteMessage("Syntax Error: incorrect operator for type float");

        return NULL;
}


/*
  Expects either one or two arguments, order matters. 
*/
void addArrayHandling(struct ExprRes* Expr, struct ExprRes* Expr2)
{
        if(NULL == Expr)
        {
                return;
        }

        if(NULL != Expr2 && NULL == Expr)
        {
                Expr = Expr2;
                Expr2 = NULL;
        }

        if(NULL == Expr2)
        {

                if(0 == strcmp(Expr->Type, INTARR) || 0 == strcmp(Expr->Type, BOOLARR))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Expr->Reg, Expr->Type), ")");
                
                        int reg = AvailTmpReg(INT);
                        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "lw", TmpRegName(reg, INT), addr, NULL));
                
                        ReleaseTmpReg(Expr->Reg, Expr->Type);
                        Expr->Reg = reg;
                        Expr->Type = INT;
                }
                else if(0 == strcmp(Expr->Type, FLOATARR))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Expr->Reg, INT), ")");
                
                        int reg = AvailTmpReg(FLOAT);
                        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "l.s", TmpRegName(reg, FLOAT), addr, NULL));
                
                        ReleaseTmpReg(Expr->Reg, Expr->Type);
                        Expr->Reg = reg;
                        Expr->Type = FLOAT;
                }

        }
        else
        {
                if(0 == strcmp(Expr->Type, INTARR) || 0 == strcmp(Expr->Type, BOOLARR))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Expr->Reg, Expr->Type), ")");
                
                        int reg = AvailTmpReg(INT);
                        Expr2->Instrs = AppendSeq(Expr2->Instrs, GenInstr(NULL, "lw", TmpRegName(reg, INT), addr, NULL));
                
                        ReleaseTmpReg(Expr->Reg, Expr->Type);
                        Expr->Reg = reg;
                        Expr->Type = INT;
                }
                else if(0 == strcmp(Expr->Type, FLOATARR))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Expr->Reg, INT), ")");
                
                        int reg = AvailTmpReg(FLOAT);
                        Expr2->Instrs = AppendSeq(Expr2->Instrs, GenInstr(NULL, "l.s", TmpRegName(reg, FLOAT), addr, NULL));
                
                        ReleaseTmpReg(Expr->Reg, Expr->Type);
                        Expr->Reg = reg;
                        Expr->Type = FLOAT;
                }

                if(0 == strcmp(Expr2->Type, INTARR) || 0 == strcmp(Expr2->Type, BOOLARR))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Expr2->Reg, Expr2->Type), ")");
                
                        int reg = AvailTmpReg(INT);
                        Expr2->Instrs = AppendSeq(Expr2->Instrs, GenInstr(NULL, "lw", TmpRegName(reg, INT), addr, NULL));
                
                        ReleaseTmpReg(Expr2->Reg, Expr2->Type);
                        Expr2->Reg = reg;
                        Expr2->Type = INT;
                }
                else if(0 == strcmp(Expr2->Type, FLOATARR))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Expr2->Reg, INT), ")");
                
                        int reg = AvailTmpReg(FLOAT);
                        Expr2->Instrs = AppendSeq(Expr2->Instrs, GenInstr(NULL, "l.s", TmpRegName(reg, FLOAT), addr, NULL));
                
                        ReleaseTmpReg(Expr2->Reg, Expr2->Type);
                        Expr2->Reg = reg;
                        Expr2->Type = FLOAT;
                }

        }
}


struct ExprRes *  doIntLit(char * digits)
{ 
        struct ExprRes *res;
        res = NULL;
        
        res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
        res->Type = "int";

        res->Reg = AvailTmpReg("int");
        res->Instrs = GenInstr(NULL,"li",TmpRegName(res->Reg, res->Type),digits,NULL);

        return res;
}


struct ExprRes *  doFltLit(char * digits)
{ 
        struct ExprRes *res;
  
        res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
        res->Type = "float";

        res->Reg = AvailTmpReg("float");

        char* floatLabel = GenLabel();
        char underscore[2];
        underscore[0] = '_';
        underscore[1] = '\0';

        floatLabel = strcat(underscore, GenLabel());

        floatData = AppendSeq(floatData, GenInstr(floatLabel, ".float", digits, NULL, NULL));

        res->Instrs = GenInstr(NULL,"l.s",TmpRegName(res->Reg, res->Type), floatLabel, NULL);

        return res;
}


struct ExprRes *  doBoolLit(char * expr)
{ 
        struct ExprRes *res;
  
        res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
        res->Type = "bool";

        res->Reg = AvailTmpReg("bool");

        if(0 == strcmp(expr, "true"))
        {
                res->Instrs = GenInstr(NULL, "li", TmpRegName(res->Reg, res->Type), "1", NULL);
        }
        else if(0 == strcmp(expr, "false"))
        {
                res->Instrs = GenInstr(NULL, "li", TmpRegName(res->Reg, res->Type), "0", NULL);
        }
  
        return res;
}



//expr only used in arrays
struct ExprRes * doRval(char * name, struct ExprRes* expr)
{ 
        addArrayHandling(expr, NULL);

        struct SymEntry* anEntry = FindName(table, name);
   
        if (!anEntry)
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Undeclared variable");
                exit(-1);
        }
        if(NULL != expr && 0 == strcmp(FLOAT, expr->Type))
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Mismatched types");
                exit(-1);
        }
        
        char* type = (char*) GetAttr(anEntry);
        int reg = -100;
        if(0 == strcmp("int", type) || 0 == strcmp(INTARR, type))
        {
                type = INT;
                reg = AvailTmpReg("int");
        }
        else if(0 == strcmp(BOOL, type) || 0 == strcmp(BOOLARR, type))
        {
                type = BOOL;
                reg = AvailTmpReg(BOOL);
        }
        else if(0 == strcmp(FLOAT, type))
        {
                type = FLOAT;
                reg = AvailTmpReg(FLOAT);
        }
        else if(0 == strcmp("floatarr", type))
        {
                type = INT;
                reg = AvailTmpReg(INT);
        }
        else
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("No recognized type");
                exit(-1);
        }                

        struct ExprRes *res = NULL;

        res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
        res->Instrs = NULL;
        res->Reg = reg;
        res->Type = type;

        if(NULL == expr)
        {
                if(0 == strcmp(FLOAT, type))
                {
                        res->Instrs = AppendSeq(res->Instrs, GenInstr(NULL, "l.s", TmpRegName(res->Reg, res->Type), name, NULL));
                }
                else
                {
                        res->Instrs = AppendSeq(res->Instrs, GenInstr(NULL,"lw",TmpRegName(res->Reg, res->Type),name,NULL));
                }
        }
        else
        {
                res->Instrs = AppendSeq(res->Instrs, GenInstr(NULL, "sll", TmpRegName(expr->Reg, expr->Type), TmpRegName(expr->Reg, expr->Type), "2"));
                res->Instrs = AppendSeq(res->Instrs, GenInstr(NULL, "la", TmpRegName(res->Reg, res->Type), name, NULL));
                res->Instrs = AppendSeq(res->Instrs, GenInstr(NULL, "add", TmpRegName(res->Reg, res->Type), TmpRegName(res->Reg, res->Type), TmpRegName(expr->Reg, expr->Type)));

                if(0 == strcmp((char*) GetAttr(anEntry), FLOATARR))
                {
                        res->Type = FLOATARR;
                }
                else
                {
                        res->Type = INTARR;
                }

                ReleaseTmpReg(expr->Reg, expr->Type);
                res->Instrs = AppendSeq(expr->Instrs, res->Instrs);
                free(expr);
        }

        return res;
}



struct ExprRes *  doBinArith(struct ExprRes * Res1, struct ExprRes * Res2, char* operation)  
{
        addArrayHandling(Res1, Res2);

        int reg;
        char* regType = tmpRegType(Res1, Res2);

        reg = AvailTmpReg(regType);

        Res1->Instrs = AppendSeq(Res1->Instrs, Res2->Instrs);


        if(0 == strcmp("float", regType))
        {
                //if one is float and the other int, convert the int to float
                if(0 != strcmp("float", Res1->Type))
                {
                        int reg2 = AvailTmpReg("float");
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "mtc1", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(Res1->Reg, Res1->Type);
                        Res1->Type = "float";
                        Res1->Reg = AvailTmpReg("float");

                        AppendSeq(Res1->Instrs, GenInstr(NULL, "cvt.s.w", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(reg2, "float");
                }
                else if(0 != strcmp("float", Res2->Type))
                {
                        int reg2 = AvailTmpReg("float");
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "mtc1", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(Res2->Reg, Res2->Type);
                        Res2->Type = "float";
                        Res2->Reg = AvailTmpReg("float");

                        AppendSeq(Res1->Instrs, GenInstr(NULL, "cvt.s.w", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(reg2, "float");
                }
                
                operation = convertToFltOp(operation);
                AppendSeq(Res1->Instrs, GenInstr(NULL, operation, TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type)));
        }
        else
        {
                AppendSeq(Res1->Instrs, GenInstr(NULL, operation, TmpRegName(Res1->Reg, Res1->Type),TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type)));
        }

        ReleaseTmpReg(reg, regType);
        ReleaseTmpReg(Res2->Reg, Res2->Type);

        free(Res2);

        Res1->Type = regType;
        return Res1;
}




struct ExprRes* doBoolOp(struct ExprRes* Res1, struct ExprRes* Res2, char* op)
{
        int reg;
        char* regType = tmpRegType(Res1, Res2);
        reg = AvailTmpReg(regType);

        addArrayHandling(Res1, Res2);
        AppendSeq(Res1->Instrs,Res2->Instrs);

        AppendSeq(Res1->Instrs,GenInstr(NULL, op, TmpRegName(reg, regType), TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type)));  

        ReleaseTmpReg(Res1->Reg, Res1->Type);
        ReleaseTmpReg(Res2->Reg, Res2->Type);
        Res1->Reg = reg;
        free(Res2);
//        free(regType);
        
        Res1->Type = "bool";
        return Res1;
}


struct InstrSeq * doPrintSpace(struct ExprRes * Expr)
{ 
        addArrayHandling(Expr, NULL);

        struct InstrSeq* code;
        code = Expr->Instrs;

        if(0 == strcmp(Expr->Type, FLOAT) || 0 == strcmp(Expr->Type, FLOATARR))
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Takes integer, currently float");
                exit(-1);
        }

        int reg;
        char* regType = tmpRegType(Expr, NULL);
        reg = AvailTmpReg(regType);
        
        char* firstRunLabel = GenLabel();
        char* checkLabel = GenLabel();
        char* beginLabel = GenLabel();

        code = AppendSeq(code,GenInstr(NULL,"b", firstRunLabel, NULL, NULL));

        AppendSeq(code,GenInstr(beginLabel,"li","$v0","4",NULL));
        AppendSeq(code,GenInstr(NULL,"la","$a0","_sp",NULL));
        AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

        AppendSeq(code, GenInstr(checkLabel, "move", TmpRegName(reg, regType), TmpRegName(Expr->Reg, Expr->Type), NULL));
        AppendSeq(code, GenInstr(NULL, "sub", TmpRegName(Expr->Reg, Expr->Type), TmpRegName(reg, regType),  "1"));
        AppendSeq(code, GenInstr(firstRunLabel, "bgt", TmpRegName(Expr->Reg, Expr->Type), "0", beginLabel));

        ReleaseTmpReg(Expr->Reg, Expr->Type);
        ReleaseTmpReg(reg, regType);
        free(Expr);

        return code;
}

struct InstrSeq * doPrintln(struct InstrSeq * code, struct ExprRes * Expr)
{ 
        if(NULL == code && NULL == Expr)
        {
                code = (struct InstrSeq*) malloc(sizeof(struct InstrSeq));
                AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
                AppendSeq(code,GenInstr(NULL,"la","$a0","_nl",NULL));
                AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

                return code;
        }
        else
        {
                addArrayHandling(Expr, NULL);
                code = AppendSeq(code, Expr->Instrs);
        }

        if(0 == strcmp("float", Expr->Type))
        {
                code = AppendSeq(code,GenInstr(NULL,"li","$v0","2",NULL));
                code = AppendSeq(code, GenInstr(NULL, "mov.s", "$f12", TmpRegName(Expr->Reg, Expr->Type), NULL));
        }
        else if(0 == strcmp(Expr->Type, INT) || 0 == strcmp(Expr->Type, BOOL))
        {
                code = AppendSeq(code,GenInstr(NULL,"li","$v0","1",NULL));
                code = AppendSeq(code,GenInstr(NULL,"move","$a0",TmpRegName(Expr->Reg, Expr->Type),NULL));
        }

        code = AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

        AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
        AppendSeq(code,GenInstr(NULL,"la","$a0","_nl",NULL));
        AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

        ReleaseTmpReg(Expr->Reg, Expr->Type);
        free(Expr);

        return code;
}

struct InstrSeq * doPrint(struct InstrSeq * code, struct ExprRes * Expr)
{
        addArrayHandling(Expr, NULL);

        if(NULL == code)
        {
                code = Expr->Instrs;
        }
        else
        {
                code = AppendSeq(code, Expr->Instrs);
        }

        //if not floating point
        if(0 == strcmp("float", Expr->Type))
        {
                code = AppendSeq(code, GenInstr(NULL,"li","$v0","2",NULL));
                code = AppendSeq(code, GenInstr(NULL,"mov.s","$f12",TmpRegName(Expr->Reg, Expr->Type),NULL));
        }
        else
        {
                code = AppendSeq(code, GenInstr(NULL,"li","$v0","1",NULL));
                code = AppendSeq(code, GenInstr(NULL,"move","$a0",TmpRegName(Expr->Reg, Expr->Type),NULL));
        }

        code = AppendSeq(code, GenInstr(NULL,"syscall",NULL,NULL,NULL));

        AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
        AppendSeq(code,GenInstr(NULL,"la","$a0","_sp",NULL));
        AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

        ReleaseTmpReg(Expr->Reg, Expr->Type);
        free(Expr);

        return code;
}


struct InstrSeq * doAssign(char *name, struct ExprRes* Res, struct ExprRes* Expr)
{ 
        addArrayHandling(Expr, NULL);

        struct InstrSeq *code;
        struct SymEntry* anEntry;
        char* type;

        if(NULL != name)
        {
                anEntry = FindName(table, name);
                type = (char*) GetAttr(anEntry);
        }
        else
        {
                anEntry = NULL;
                type = Expr->Type;
        }

        //if not in table
        if(NULL == anEntry && NULL == Res)  //asdf
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Undeclared variable");
                exit(-1);
        }
        else
        {
                //else if type doesnt match, also error
                if(NULL != Expr->Type && 0 != strcmp(type, Expr->Type))
                {
                        WriteIndicator(GetCurrentColumn());
                        WriteMessage("Wrong type");
                        exit(-1);
                }
        }

        code = Expr->Instrs;

        //check if float = int
        if(NULL != Res && (0 == strcmp(FLOAT, Res->Type) || 0 == strcmp(FLOATARR, Res->Type)) && 0 == strcmp(INT, Expr->Type))
        {
                int reg2 = AvailTmpReg(FLOAT);
                AppendSeq(code, GenInstr(NULL, "mtc1", TmpRegName(Expr->Reg, Expr->Type), TmpRegName(reg2, "float"), NULL));

                ReleaseTmpReg(Expr->Reg, Expr->Type);
                Expr->Type = FLOAT;
                type = Expr->Type;
                Expr->Reg = AvailTmpReg(FLOAT);

                AppendSeq(code, GenInstr(NULL, "cvt.s.w", TmpRegName(Expr->Reg, Expr->Type), TmpRegName(reg2, "float"), NULL));

                ReleaseTmpReg(reg2, FLOAT);
        }

        //if not assigning to arr
        if(NULL != anEntry)
        {
                if(0 == strcmp(type, FLOAT))
                {
                        code = AppendSeq(code, GenInstr(NULL, "s.s", TmpRegName(Expr->Reg, Expr->Type), name, NULL));
                }
                else
                {
                        code = AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(Expr->Reg, Expr->Type), name, NULL));
                }
        }
        else
        {
                if(0 == strcmp(type, FLOATARR) || 0 == strcmp(type, FLOAT))
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Res->Reg, INT), ")");

                        code = AppendSeq(Res->Instrs, code);
                        code = AppendSeq(code, GenInstr(NULL, "s.s", TmpRegName(Expr->Reg, Expr->Type), addr, NULL));
                }
                else
                {
                        char addr[8];
                        sprintf(addr, "%s%s%s", "(", TmpRegName(Res->Reg, INT), ")");

                        code = AppendSeq(Res->Instrs, code);
                        code = AppendSeq(code, GenInstr(NULL, "sw", TmpRegName(Expr->Reg, Expr->Type), addr, NULL));
                }
        }

        if(NULL != Res)
        {
                ReleaseTmpReg(Res->Reg, Res->Type);
                free(Res);
        }

        ReleaseTmpReg(Expr->Reg, Expr->Type);
        free(Expr);
  
        return code;
}

/*
  either a var id or a arr expr
*/
struct InstrSeq * read(char* id, struct ExprRes *Expr)
{
        struct ExprRes *Res = (struct ExprRes*) malloc(sizeof(struct ExprRes));
        Res->Instrs = NULL;
        Res->Type = NULL;

        if(NULL != Expr)
        {
                if(0 == strcmp(FLOATARR, Expr->Type))
                {
                        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "li", "$v0", "6", NULL));
                        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "syscall", NULL, NULL, NULL));

                        Res->Type = FLOAT;
                        Res->Reg = -1;
                        return doAssign(NULL, Expr, Res);
                }
                else
                {
                        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "li", "$v0", "5", NULL));
                        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "syscall", NULL, NULL, NULL));

                        Res->Type = INT;
                        Res->Reg = -1;
                        return doAssign(NULL, Expr, Res);
                }
        }
        else
        {
                struct SymEntry *anEntry = FindName(table, id);
                char *type = (char*) GetAttr(anEntry);

                if(0 == strcmp(FLOAT, type))
                {
                        Res->Instrs = AppendSeq(Res->Instrs, GenInstr(NULL, "li", "$v0", "6", NULL));
                        Res->Instrs = AppendSeq(Res->Instrs, GenInstr(NULL, "syscall", NULL, NULL, NULL));

                        Res->Type = FLOAT;
                        Res->Reg = -1;
                        return doAssign(id, NULL, Res);
                }
                else
                {
                        Res->Instrs = AppendSeq(Res->Instrs, GenInstr(NULL, "li", "$v0", "5", NULL));
                        Res->Instrs = AppendSeq(Res->Instrs, GenInstr(NULL, "syscall", NULL, NULL, NULL));

                        Res->Type = INT;
                        Res->Reg = -1;
                        return doAssign(id, NULL, Res);
                }                
        }
}


struct ExprRes * doBExpr(struct ExprRes * Res1,  struct ExprRes * Res2, char* op)
{
        addArrayHandling(Res1, Res2);
        Res1->Instrs = AppendSeq(Res1->Instrs, Res2->Instrs);

        int reg;
        char* regType = "bool";
        reg = AvailTmpReg(regType);
        
        //compare values stored in reg's of Res1 and 2.
        char* label  = GenLabel();
        char* failLabel = GenLabel();


        //load true into result
        Res1->Instrs = AppendSeq(Res1->Instrs, GenInstr(NULL, "li", TmpRegName(reg, regType), "1", NULL));

        if(0 != strcmp("float", Res1->Type) && 0 != strcmp("float", Res2->Type))
        {
                //if false, branch over putting true into register
                AppendSeq(Res1->Instrs, GenInstr(NULL, op, TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type), label));
        }
        else
        {
                if(0 != strcmp("float", Res1->Type))
                {
                        int reg2 = AvailTmpReg("float");
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "mtc1", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(Res1->Reg, Res1->Type);
                        Res1->Type = "float";
                        Res1->Reg = AvailTmpReg("float");

                        AppendSeq(Res1->Instrs, GenInstr(NULL, "cvt.s.w", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(reg2, "float");
                }
                else if(0 != strcmp("float", Res2->Type))
                {
                        int reg2 = AvailTmpReg("float");
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "mtc1", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(Res2->Reg, Res2->Type);
                        Res2->Type = "float";
                        Res2->Reg = AvailTmpReg("float");

                        AppendSeq(Res1->Instrs, GenInstr(NULL, "cvt.s.w", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(reg2, "float"), NULL));

                        ReleaseTmpReg(reg2, "float");
                }

                if(0 == strcmp("blt", op))
                {
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", label, NULL, NULL));
                }
                else if(0 == strcmp("bgt", op))
                {
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1f", label, NULL, NULL));
                }
                else if(0 == strcmp("beq", op))
                {
                        //if either is less than the other, not equal
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", failLabel, NULL, NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(Res1->Reg, Res1->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", failLabel, NULL, NULL));

                        //else it passes
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "b", label, NULL, NULL));
                }
                else if(0 == strcmp("bne", op))
                {
                        //if either is less than the other, not equal
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", label, NULL, NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(Res1->Reg, Res1->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", label, NULL, NULL));

                        //else if fails
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "b", failLabel, NULL, NULL));
                }
                else if(0 == strcmp("ble", op))
                {
                        //if less than, pass, if greater than, fail
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res2->Reg, Res2->Type), TmpRegName(Res1->Reg, Res1->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", failLabel, NULL, NULL));

                        AppendSeq(Res1->Instrs, GenInstr(NULL, "b", label, NULL, NULL));
                }
                else if(0 == strcmp("bge", op))
                {
                        //if less than, pass, if greater than, fail
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "c.lt.s", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res2->Reg, Res2->Type), NULL));
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "bc1t", failLabel, NULL, NULL));
                        //else was not greater than, pass
                        AppendSeq(Res1->Instrs, GenInstr(NULL, "b", label, NULL, NULL));
                }
        }

        AppendSeq(Res1->Instrs, GenInstr(failLabel, "li", TmpRegName(reg, regType), "0", NULL));

        //if Res1 was turned into a float above, change it back to a bool type
        //and get the right type of register
        if(0 == strcmp("float", Res1->Type))
        {
                ReleaseTmpReg(Res1->Reg, Res1->Type);
                Res1->Type = "bool";
                Res1->Reg = AvailTmpReg(Res1->Type);
        }

        AppendSeq(Res1->Instrs, GenInstr(label, "move", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(reg, regType), NULL));
                        
        ReleaseTmpReg(reg, regType);
        ReleaseTmpReg(Res2->Reg, Res2->Type);
        free(Res2);
//        free(regType);

        Res1->Type = "bool";
        return Res1;
}



/*
  do an if statement
*/
struct InstrSeq * doIf(struct ExprRes * bRes, struct InstrSeq * seq)
{
        addArrayHandling(bRes, NULL);

        //make a label
        char* label = GenLabel();

        //append current instructions
        struct InstrSeq* seq2;
        //check bExpr, branch if not true
        seq2 = AppendSeq(bRes->Instrs, GenInstr(NULL, "bne", TmpRegName(bRes->Reg, bRes->Type), "1", label));
        //put body of if after check
        AppendSeq(seq2, seq);
        //put label after body, branch to this if if is false
        AppendSeq(seq2, GenInstr(label, NULL, NULL, NULL, NULL));

        //free register used by bRes
        ReleaseTmpReg(bRes->Reg, bRes->Type);
        //free bRes as it is not needed anymore
        free(bRes);

        return seq2;
}



struct InstrSeq * doIfElse(struct ExprRes * bRes, struct InstrSeq * seq, struct InstrSeq* seq2)
{
        addArrayHandling(bRes, NULL);

        //make a label
        char* label = GenLabel();
        char* endLabel = GenLabel();

        //append current instructions
        struct InstrSeq* seq3;
        //check bExpr, branch if not true
        seq3 = AppendSeq(bRes->Instrs, GenInstr(NULL, "bne", TmpRegName(bRes->Reg, bRes->Type), "1", label));

        //put body of if after check
        AppendSeq(seq3, seq);
        AppendSeq(seq3, GenInstr(NULL, "b", endLabel, NULL, NULL));

        //put label after else, branch to this if if is false
        AppendSeq(seq3, GenInstr(label, NULL, NULL, NULL, NULL));
        
        //put else 
        AppendSeq(seq3, seq2);
                
        //final label, end of if-else statement
        AppendSeq(seq3, GenInstr(endLabel, NULL, NULL, NULL, NULL));
        
        //free register used by bRes
        ReleaseTmpReg(bRes->Reg, bRes->Type);
        //free bRes as it is not needed anymore
        free(bRes);

        return seq3;
}



/*
  do a while statement
  //NOT A DO-WHILE LOOP
  */
struct InstrSeq * doWhile(struct ExprRes * expr, struct InstrSeq * seq)
{
        addArrayHandling(expr, NULL);

        //make a label
        char* beginLabel = GenLabel();
        char* endLabel = GenLabel();

        //append current instructions
        struct InstrSeq* seq2;
        //check bExpr, branch if not true
        seq2 = AppendSeq(NULL, GenInstr(NULL, "b", endLabel, NULL, NULL));
        //begin loop
        AppendSeq(seq2, GenInstr(beginLabel, NULL, NULL, NULL, NULL));
        //body of loop
        AppendSeq(seq2, seq);

        //check at bottom
        AppendSeq(seq2, GenInstr(endLabel, NULL, NULL, NULL, NULL));
        AppendSeq(seq2, expr->Instrs);
        AppendSeq(seq2, GenInstr(NULL, "beq", TmpRegName(expr->Reg, expr->Type), "1", beginLabel));

//        ReleaseTmpReg(expr->Reg);
//        free(expr);

        return seq2;
}

void doFuncDec(const char* id, struct InstrSeq* code)
{
        char underscore[2];
        underscore[0] = '_';
        underscore[1] = '\0';

        char* label = strcat(underscore, strdup(id));
        
        struct InstrSeq* saveCode;
        
        //save stack pointer
        saveCode = AppendSeq(GenInstr(label, NULL, NULL, NULL, NULL), GenInstr(NULL, "subu", "$sp", "$sp", "4"));
        AppendSeq(saveCode, GenInstr(NULL, "sw", "$ra", "($sp)", NULL));

        code = AppendSeq(saveCode, code);

        AppendSeq(code, GenInstr(NULL, "lw", "$ra", "($sp)", NULL));
        AppendSeq(code, GenInstr(NULL, "addu", "$sp", "$sp", "4"));

        AppendSeq(code, RestoreSeq());
        AppendSeq(code, GenInstr(NULL, "jr", "$ra", NULL, NULL));

        funcSeq = AppendSeq(funcSeq, code);
}


struct InstrSeq* doFunc(const char* id)
{
        struct InstrSeq* code = NULL;
        struct SymEntry* entry = FindName(funcTable, id);

        if(NULL == entry)
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("No such function declared.");
        }

        char underscore[2];
        underscore[0] = '_';
        underscore[1] = '\0';
        
        char* label = strcat(underscore, strdup(id));

        //save all needed registers onto stack before going into function
        code = AppendSeq(code, SaveSeq());
        code = AppendSeq(code, GenInstr(NULL, "jal", label, NULL, NULL));

        return code;
}


struct ExprRes* doFuncReturn(const char* id)
{
        struct SymEntry* entry = FindName(funcTable, id);

        if(NULL == entry)
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("No such function declared.");
                exit(-1);
        }

        char underscore[2];
        underscore[0] = '_';
        underscore[1] = '\0';
        
        char* label = (char*) malloc(sizeof(char) * 25);
        label = strcat(underscore, strdup(id));

        struct ExprRes* Res = (struct ExprRes*) malloc(sizeof(struct ExprRes));
        Res->Instrs = NULL;

        //save all needed registers onto stack before going into function
        Res->Instrs = SaveSeq();
        Res->Instrs = AppendSeq(Res->Instrs, GenInstr(NULL, "jal", label, NULL, NULL));

        Res->Reg = -1;
        Res->Type = (char*) GetAttr(entry);

        return Res;
}


struct InstrSeq* doReturn(struct ExprRes* Res)
{
        addArrayHandling(Res, NULL);

        struct InstrSeq* code;

        if(0 == strcmp("float", Res->Type))
        {
                code = AppendSeq(Res->Instrs, GenInstr(NULL, "mov.s", "$f0", TmpRegName(Res->Reg, Res->Type), NULL));
        }
        else
        {
                code = AppendSeq(Res->Instrs, GenInstr(NULL, "move", "$v0", TmpRegName(Res->Reg, Res->Type), NULL));
        }

        ReleaseTmpReg(Res->Reg, Res->Type);
        //return register
        Res->Reg = -1;
        free(Res);

        return code;
}

struct ExprRes* doExponent(struct ExprRes* Res1, struct ExprRes* Res2)
{
        addArrayHandling(Res1, Res2);

        if(0 == strcmp("float", Res2->Type) || 0 == strcmp("bool", Res1->Type))
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Float exponent or bool base");
        }

        struct InstrSeq* code = Res1->Instrs;
        char* startLabel = GenLabel();
        char* endLabel = GenLabel();

        //reg1 for counter, reg2 for temporary original value of Res1->reg
        int tmpReg1 = AvailTmpReg("int");
        int tmpReg2 = AvailTmpReg(Res1->Type);

        code = AppendSeq(code, Res2->Instrs);

        //how many times we've looped so far
        code = AppendSeq(code, GenInstr(NULL, "li", TmpRegName(tmpReg1, "int"), "0", NULL));

        if(0 == strcmp("float", Res1->Type))
        {
                //make a copy of original value to mul by
                code = AppendSeq(code, GenInstr(NULL, "mov.s", TmpRegName(tmpReg2, Res1->Type), TmpRegName(Res1->Reg, Res1->Type), NULL));
                code = AppendSeq(code, GenInstr(NULL, "l.s", TmpRegName(Res1->Reg, Res1->Type), ONE_FLOAT, NULL));

                code = AppendSeq(code, GenInstr(startLabel, "bge", TmpRegName(tmpReg1, "int"), TmpRegName(Res2->Reg, Res2->Type), endLabel));

                code = AppendSeq(code, GenInstr(NULL, "mul.s", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res1->Reg, Res1->Type), TmpRegName(tmpReg2, Res1->Type)));
                code = AppendSeq(code, GenInstr(NULL, "add", TmpRegName(tmpReg1, "int"), TmpRegName(tmpReg1, "int"), "1"));
                code = AppendSeq(code, GenInstr(NULL, "j", startLabel, NULL, NULL));
        }
        else
        {
                code = AppendSeq(code, GenInstr(NULL, "move", TmpRegName(tmpReg2, Res1->Type), TmpRegName(Res1->Reg, Res1->Type), NULL));
                code = AppendSeq(code, GenInstr(NULL, "li", TmpRegName(Res1->Reg, Res1->Type), "1", NULL));

                code = AppendSeq(code, GenInstr(startLabel, "bge", TmpRegName(tmpReg1, "int"), TmpRegName(Res2->Reg, Res2->Type), endLabel));

                code = AppendSeq(code, GenInstr(NULL, "mul", TmpRegName(Res1->Reg, Res1->Type), TmpRegName(Res1->Reg, Res1->Type), TmpRegName(tmpReg2, Res1->Type)));
                code = AppendSeq(code, GenInstr(NULL, "add", TmpRegName(tmpReg1, "int"), TmpRegName(tmpReg1, "int"), "1"));
                code = AppendSeq(code, GenInstr(NULL, "j", startLabel, NULL, NULL));
        }

        code = AppendSeq(code, GenInstr(endLabel, NULL, NULL, NULL, NULL));

        //FINISH UP STRONG YO
        Res1->Instrs = code;

        ReleaseTmpReg(Res2->Reg, Res2->Type);
        free(Res2);

        return Res1;
}

void decArr(char* id, int size)
{
        struct SymEntry* entry = FindName(table, id);

        if(NULL == entry)
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Id does not exist");
                exit(-1);
        }
        
        char* spaceSize = (char*) malloc(sizeof(char) * 5);
        sprintf(spaceSize, "%d", size * 4);

        floatData = AppendSeq(floatData, GenInstr(id, ".space", spaceSize, NULL, NULL));
}

struct ExprRes * not(struct ExprRes *Expr)
{
        addArrayHandling(Expr, NULL);

        if(0 != strcmp(INT, Expr->Type) && 0 != strcmp(BOOL, Expr->Type))
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Requires bool or int");
                exit(-1);
        }

        Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "xori", TmpRegName(Expr->Reg, Expr->Type), TmpRegName(Expr->Reg, Expr->Type), "1"));

        return Expr;
}


struct ExprRes * neg(struct ExprRes *Expr)
{
        addArrayHandling(Expr, NULL);

        if(0 == strcmp(INT, Expr->Type))
        {
                Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "neg", TmpRegName(Expr->Reg, Expr->Type), TmpRegName(Expr->Reg, Expr->Type), NULL));
        }
        else if(0 == strcmp(FLOAT, Expr->Type))
        {
                Expr->Instrs = AppendSeq(Expr->Instrs, GenInstr(NULL, "neg.s", TmpRegName(Expr->Reg, Expr->Type), TmpRegName(Expr->Reg, Expr->Type), NULL));
        }
        else
        {
                WriteIndicator(GetCurrentColumn());
                WriteMessage("Requires bool or int");
                exit(-1);
        }

        return Expr;
}




void Finish(struct InstrSeq *Code)
{ 
        struct InstrSeq *code;
        struct SymEntry *entry;

        //meta stuffs
        code = GenInstr(NULL,".text",NULL,NULL,NULL);
        AppendSeq(code,GenInstr(NULL,".globl","main",NULL,NULL));
        AppendSeq(code, GenInstr("main",NULL,NULL,NULL,NULL));

        //functions
        char* jOverFuncs = GenLabel();
        AppendSeq(code, GenInstr(NULL, "j", jOverFuncs, NULL, NULL));
        AppendSeq(code, funcSeq);
        AppendSeq(code, GenInstr(jOverFuncs, NULL, NULL, NULL, NULL));

        //code
        AppendSeq(code,Code);

        //ending stuffs
        AppendSeq(code, GenInstr(NULL, "li", "$v0", "10", NULL)); 
        AppendSeq(code, GenInstr(NULL,"syscall",NULL,NULL,NULL));
        AppendSeq(code,GenInstr(NULL,".data",NULL,NULL,NULL));
        AppendSeq(code,GenInstr(NULL,".align","4",NULL,NULL));
        AppendSeq(code,GenInstr("_nl",".asciiz","\"\\n\"",NULL,NULL));
        AppendSeq(code,GenInstr("_sp",".asciiz","\"\\ \"",NULL,NULL));
        AppendSeq(code, GenInstr(ONE_FLOAT, ".float", "1.0", NULL, NULL));
        AppendSeq(code, floatData);

        entry = FirstEntry(table);
        while (entry) {
                if(0 != strcmp("intarr", (char*) GetAttr(entry)) && 0 != strcmp("floatarr", (char*) GetAttr(entry)) && 0 != strcmp("boolarr", (char*) GetAttr(entry)))
                {
                        AppendSeq(code,GenInstr((char *) GetName(entry),".word","0",NULL,NULL));
                }
                entry = NextEntry(table, entry);
        }
  
        WriteSeq(code);
  
        return;
}

