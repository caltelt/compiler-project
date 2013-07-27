#####################################################################
# Douglas MacFarland
# Feb. 14, 2013
#
# CS 442 : Compiler
#
#####################################################################
#
# Type "make" or "make all" to compile your code
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################

CC=gcc
CFLAGS=-Wall -g
# Linker flag for Linux
#LDFLAGS=-lm -lrt

all: Compiler

Compiler: SymTab.o IOMngr.o Main.o CodeGen.o Semantics.o Bison.o Flex.o
	$(CC) -g -o Compiler *.o

SymTab.o: SymTab.h SymTab.c
	$(CC) -c $(CFLAGS) SymTab.c

IOMngr.o: IOMngr.h IOMngr.c
	$(CC) -c $(CFLAGS) IOMngr.c

Main.o: main.c SymTab.o IOMngr.o
	$(CC) -c $(CFLAGS) main.c

CodeGen.o: CodeGen.h CodeGen.c
	$(CC) -c $(CFLAGS) CodeGen.c

Semantics.o: Semantics.h Semantics.c SymTab.o IOMngr.o CodeGen.o
	$(CC) -c $(CFLAGS) Semantics.c

Bison.o: parser.y SymTab.o IOMngr.o Semantics.o CodeGen.o
	bison -dyvW parser.y
	$(CC) -g -c y.tab.c

Flex.o: scanner.l SymTab.o IOMngr.o Bison.o
	flex scanner.l
	$(CC) -g -c lex.yy.c

clean:
	$(RM) lex.yy.c y.tab.c y.tab.h Compiler *.o
