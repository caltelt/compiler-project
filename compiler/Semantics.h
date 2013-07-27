/* Semantics.h
   The action and supporting routines for performing semantics processing.
*/

/* Semantic Records */
struct IdList 
{
        struct SymEntry * TheEntry;
        struct IdList * Next;
};

struct ExprRes 
{
        int Reg;
        char* Type;
        struct InstrSeq * Instrs;
};

struct ExprResList 
{
	struct ExprRes *Expr;
	struct ExprResList * Next;
};



/* Semantics Actions */
extern struct ExprRes *  doIntLit(char * digits);
extern struct ExprRes *  doFltLit(char * digits);

extern void  doFuncDec(const char* id, struct InstrSeq* StmtSeq);
extern struct InstrSeq*  doFunc(const char* id);
extern struct InstrSeq* doReturn(struct ExprRes* Res);
extern struct ExprRes* doFuncReturn(const char* id);

extern struct ExprRes* doExponent(struct ExprRes* Res1, struct ExprRes* Res2);
extern struct ExprRes * not(struct ExprRes *Expr);
extern struct ExprRes * neg(struct ExprRes *Expr);

extern struct ExprRes *  doBoolLit(char * digits);
extern struct ExprRes *  doRval(char * name, struct ExprRes* expr);
//extern struct ExprRes *  doRval(char * name);
extern struct InstrSeq *  doAssign(char * name, struct ExprRes* Res, struct ExprRes * Expr);
extern struct InstrSeq * read(char* id, struct ExprRes *Expr);

extern struct ExprRes *  doBinArith(struct ExprRes * Res1,  struct ExprRes * Res2, char* operation);

extern struct InstrSeq *  doPrintSpace(struct ExprRes * Expr);
extern struct InstrSeq *  doPrintln(struct InstrSeq * code, struct ExprRes * Expr);
extern struct InstrSeq *  doPrint(struct InstrSeq * code, struct ExprRes * Expr);

extern struct ExprRes * doBExpr (struct ExprRes * Res1,  struct ExprRes * Res2, char* op);
extern struct ExprRes *  doBoolOp(struct ExprRes * Res1,  struct ExprRes * Res2, char* op);

extern struct InstrSeq * doIf(struct ExprRes *bRes, struct InstrSeq * seq);
extern struct InstrSeq * doIfElse(struct ExprRes *bRes, struct InstrSeq * seq, struct InstrSeq* seq2);
extern struct InstrSeq * doWhile(struct ExprRes *bRes, struct InstrSeq * seq);


//done
extern void	Finish(struct InstrSeq *Code);
