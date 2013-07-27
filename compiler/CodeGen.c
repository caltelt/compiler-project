#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CodeGen.h"

#define MAXREG 10
#define MAXFLTREG 27

extern FILE *aFile;
extern void WriteMessage(const char* mess);

struct TmpReg {
        unsigned char Free;
        unsigned char Used;
        char * Name;
} Registers[MAXREG] 
= { {1, 0, "$t0"},  {1, 0, "$t1"},  {1, 0, "$t2"},  {1, 0, "$t3"},  
    {1, 0, "$t4"},  {1, 0, "$t5"},  {1, 0, "$t6"},  {1, 0, "$t7"},  
    {1, 0, "$t8"},  {1, 0, "$t9"}};


struct TmpFloatReg {
        unsigned char Free;
        unsigned char Used;
        char * Name;
} FltRegisters[MAXFLTREG] 
= { /*{1, 0, "$f0"},  {1, 0, "$f1"},*/  {1, 0, "$f2"},  {1, 0, "$f3"},  
    {1, 0, "$f4"},  {1, 0, "$f5"},  {1, 0, "$f6"},  {1, 0, "$f7"},
    {1, 0, "$f8"},  {1, 0, "$f9"},  {1, 0, "$f10"},  {1, 0, "$f11"},
    /* {1, 0, "$f12"},  {1, 0, "$f13"}, */  {1, 0, "$f14"},  {1, 0, "$f15"},  
    {1, 0, "$f16"},  {1, 0, "$f17"},  {1, 0, "$f18"},  {1, 0, "$f19"},  
    {1, 0, "$f20"},  {1, 0, "$f21"},  {1, 0, "$f22"},  {1, 0, "$f23"},
    {1, 0, "$f24"},  {1, 0, "$f25"},  {1, 0, "$f26"},  {1, 0, "$f27"},
    {1, 0, "$f28"},  {1, 0, "$f29"},  {1, 0, "$f30"},  /*{1, 0, "$f31"}*/ };
      

int NextLabel = 1;
char Buf[16];

extern struct InstrSeq* floatData;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


char * CopyStr(char * AStr)
{
        return (AStr) ? strdup(AStr) : NULL;
}

struct InstrSeq * GenInstr(char *Label, char *OpCode, char *Oprnd1, char *Oprnd2, char *Oprnd3)
{ 
        struct InstrSeq *instr;
  
        instr = (struct InstrSeq *) malloc(sizeof(struct InstrSeq));
        instr->Label = CopyStr(Label);
        instr->OpCode = CopyStr(OpCode);
        instr->Oprnd1 = CopyStr(Oprnd1);
        instr->Oprnd2 = CopyStr(Oprnd2);
        instr->Oprnd3 = CopyStr(Oprnd3);
        instr-> Next = NULL;
	
        return instr;
}
	
struct InstrSeq * AppendSeq(struct InstrSeq *Seq1, struct InstrSeq *Seq2)
{
        struct InstrSeq *instr;

        if (!Seq1) return Seq2;
  
        instr = Seq1;
        while (instr->Next) instr = instr->Next;
        instr->Next = Seq2;
  
        return Seq1;
}

void WriteSeq(struct InstrSeq *ASeq)
{
        struct InstrSeq *instr;

        //printf("WriteSeq\n");
        instr = ASeq;
        while (instr) {
                if (instr->Label) fprintf(aFile,"%s:",instr->Label);
                if (instr->OpCode) {
			fprintf(aFile,"\t%s\t",instr->OpCode);
                        if (instr->Oprnd1) fprintf(aFile,"\t%s",instr->Oprnd1);
                        if (instr->Oprnd2) fprintf(aFile,", %s",instr->Oprnd2);
                        if (instr->Oprnd3) fprintf(aFile,", %s",instr->Oprnd3);
                }
                fprintf(aFile,"\n");
                instr = instr->Next;
        }
        if (aFile != stdout) fclose(aFile);
}

char * GenLabel()
{ 
        char *label;

        label = (char *) malloc(8);
        sprintf(label,"L%d",NextLabel++);
  
        return label;
}
	 
int AvailTmpReg(const char* type)
{	int i;
        
        if(0 == strcmp("float", type))
        {
                for (i = 0; i < MAXFLTREG; i++) 
                {
                        if (FltRegisters[i].Free) 
                        {
                                FltRegisters[i].Free = 0;
                                FltRegisters[i].Used = 1;
                                return i;
                        }
                }
        }
        else
        {
                for (i = 0; i < MAXREG; i++) 
                {
                        if (Registers[i].Free) 
                        {
                                Registers[i].Free = 0;
                                Registers[i].Used = 1;
                                return i;
                        }
                }
                
        }

        WriteMessage("\n\n\tNot enough registers.\n");
        exit(-1);
}


char * TmpRegName(int RegNum, const char* type)
{
        if ((0 == strcmp("float", type) || 0 == strcmp("floatarr", type)) && (RegNum >= 0) && ( RegNum < MAXFLTREG))
        {
                return FltRegisters[RegNum].Name;
        } 
        else if(RegNum >= 0 && RegNum < MAXREG)
        {
                return Registers[RegNum].Name;
        }
        else
        {
                if((0 == strcmp("float", type) || 0 == strcmp("floatarr", type)) && -1 == RegNum)
                {
                        return "$f0";
                }
                else
                {
                        return "$v0";
                }
        }

        return "Candy";
}


void ReleaseTmpReg(int ANum, const char* type)
{
        if(0 == strcmp("float", type) && (ANum >= 0) && ( ANum < MAXFLTREG)) 
        {
                FltRegisters[ANum].Free = 1;
        } 
        else if ((ANum >= 0) && ( ANum < MAXREG)) 
        {
                Registers[ANum].Free = 1;
        } 
        return;
}

void ResetAllTmpReg(const char* type)
{ 
        int i;

        if(0 == strcmp("float", type))
        {
                for (i = 0; i < MAXFLTREG; i++) 
                {
                        FltRegisters[i].Free = 1;
                        FltRegisters[i].Used = 0;
                }
        }
        else
        {
                for (i = 0; i < MAXREG; i++) 
                {
                        Registers[i].Free = 1;
                        Registers[i].Used = 0;
                }
        }

        return;
}


struct InstrSeq * SaveSeq()
{ 
        struct InstrSeq * save, *code;
        int i, scnt;
        char addr[8], offset[8];
  
        scnt = -1;
        save = NULL;
        code = NULL;
        for (i = 0; i < MAXREG; i++) 
        {
                if (!Registers[i].Free) 
                {
                        scnt++;
                        sprintf(addr,"%d($sp)",scnt * 4);
                        save = AppendSeq(save,GenInstr(NULL,"sw",TmpRegName(i, "int"),addr,NULL));
                }
        }
        for(i = 0; i < MAXFLTREG; i++)
        {
                if(!FltRegisters[i].Free) 
                {
                        scnt++;
                        sprintf(addr, "%d($sp)", scnt * 4);
                        save = AppendSeq(save, GenInstr(NULL, "sw", TmpRegName(i, "float"), addr, NULL));
                }
        }

        if (scnt > 0) {
                sprintf(offset,"%d",scnt*4);
                code = GenInstr(NULL,"subu","$sp","$sp",offset);
                AppendSeq(code, save);
        }
  
        return code;
}

struct InstrSeq * RestoreSeq()
{
        struct InstrSeq * code, * save;
        int i, scnt;

        char addr[8], offset[8];
  
        scnt = 0;
        save = NULL;
        code = NULL;
        for (i = 0; i < MAXREG; i++)
        {
                if (!Registers[i].Free) 
                {
                        scnt++;
                        sprintf(addr,"%d($sp)",scnt*4);
                        save = AppendSeq(save,GenInstr(NULL,"lw",TmpRegName(i, "int"),addr,NULL));
                }
        }
        for (i = 0; i < MAXFLTREG; i++)
        {
                if (!FltRegisters[i].Free) 
                {
                        scnt++;
                        sprintf(addr,"%d($sp)",scnt*4);
                        save = AppendSeq(save,GenInstr(NULL,"l.s",TmpRegName(i, "float"),addr,NULL));
                }
        }

        if (scnt > 0)
        {
                sprintf(offset,"%d",scnt*4);
                code = AppendSeq(save,GenInstr(NULL,"addu","$sp","$sp",offset));
        }
  
        return code;
}

char * Imm(int Val)
{
        sprintf(Buf,"%d",Val);
        return Buf;
}

char * RegOff(int Offset, char * Reg)
{
        sprintf(Buf,"%d(%s)",Offset,Reg);
        return Buf;
}

