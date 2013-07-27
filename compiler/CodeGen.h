/* CodeGen.h
   Routines to support the generation of assembly code.
   
*/

#include <stdio.h>

extern FILE *AssmFile;

struct InstrSeq {
  char *Label;
  char *OpCode;
  char *Oprnd1;
  char *Oprnd2;
  char *Oprnd3;
  struct InstrSeq *Next;
};

extern void InitCodeGen(char *AFilename);

extern struct InstrSeq * GenInstr(char *Label, char *OpCode, char *Oprnd1, char *Oprnd2, char *Oprnd3);

extern struct InstrSeq * AppendSeq(struct InstrSeq *Seq1, struct InstrSeq *Seq2);

extern void WriteSeq(struct InstrSeq *ASeq);

extern char * GenLabel();

extern int AvailTmpReg(const char* type);
extern char * TmpRegName(int RegNum, const char* type);
extern void ReleaseTmpReg(int ANum, const char* type);
extern void ResetAllTmpReg(const char* type);

extern struct InstrSeq * SaveSeq();
extern struct InstrSeq * RestoreSeq();

extern char * Imm(int Val);
extern char * RegOff(int Offset, char * Reg);
